#!/usr/bin/env python3
"""GitHub-hosted controller for one tagged ECS builder and one retained disk."""
import argparse
import base64
from datetime import datetime, timedelta, timezone
import hashlib
import ipaddress
import json
import os
from pathlib import Path
import re
import shlex
import subprocess
import sys
import time
import urllib.parse
import urllib.request
import urllib.error
import uuid

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
PROJECT = 'chromium-hmos'


class ECSServiceError(RuntimeError):
    def __init__(self, action, reply):
        self.reply = reply
        super().__init__(f'ECS {action} failed: ' + ecs_error_details(reply))


def http_json(request, label, redactions=()):
    try:
        with urllib.request.urlopen(request, timeout=30) as response:
            return json.load(response)
    except urllib.error.HTTPError as error:
        try:
            reply = json.loads(error.read())
        except (ValueError, UnicodeError):
            reply = {}
        message = str(reply.get('Message', reply.get('message', '')))
        for secret in redactions:
            if secret:
                message = message.replace(secret, '[REDACTED]')
        code = str(reply.get('Code', reply.get('code', 'unknown')))
        raise RuntimeError(f'{label}: HTTP {error.code}, {code}: {message[:600]}') from None


def write_json(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_suffix('.tmp')
    temporary.write_text(json.dumps(value, indent=2) + '\n')
    temporary.replace(path)


def github_output(key, value):
    if os.environ.get('GITHUB_OUTPUT'):
        with open(os.environ['GITHUB_OUTPUT'], 'a') as output:
            output.write(f'{key}={value}\n')


def oidc_parameters(config, token, run_id):
    return {
        'Action': 'AssumeRoleWithOIDC', 'Version': '2015-04-01', 'Format': 'JSON',
        'Timestamp': datetime.now(timezone.utc).strftime('%Y-%m-%dT%H:%M:%SZ'),
        'SignatureNonce': str(uuid.uuid4()),
        'RoleArn': config['role_arn'], 'OIDCProviderArn': config['oidc_provider_arn'],
        'OIDCToken': token, 'RoleSessionName': 'chromium-' + run_id, 'DurationSeconds': '3600'}


class Cloud:
    def __init__(self, config):
        self.config = config
        self.client = None
        self.refresh_at = 0

    def authenticate(self):
        # Tokens stay on the GitHub-hosted controller, never on ECS or disk.
        from aliyunsdkcore.client import AcsClient
        from aliyunsdkcore.auth.credentials import StsTokenCredential
        endpoint = os.environ['ACTIONS_ID_TOKEN_REQUEST_URL']
        endpoint += ('&' if '?' in endpoint else '?') + urllib.parse.urlencode(
            {'audience': self.config['audience']})
        request = urllib.request.Request(endpoint, headers={
            'Authorization': 'Bearer ' + os.environ['ACTIONS_ID_TOKEN_REQUEST_TOKEN']})
        token = http_json(request, 'GitHub OIDC',
                          [os.environ['ACTIONS_ID_TOKEN_REQUEST_TOKEN']])['value']
        # Only public binding claims are logged, never the JWT or its signature.
        encoded = token.split('.')[1]
        claims = json.loads(base64.urlsafe_b64decode(encoded + '=' * (-len(encoded) % 4)))
        print('OIDC identity:', json.dumps({key: claims.get(key) for key in
              ('iss', 'aud', 'sub', 'repository', 'ref')}, ensure_ascii=False), flush=True)
        payload = urllib.parse.urlencode(oidc_parameters(
            self.config, token, os.environ['GITHUB_RUN_ID'])).encode()
        request = urllib.request.Request('https://sts.aliyuncs.com/', data=payload)
        reply = http_json(request, 'STS AssumeRoleWithOIDC', [token])
        if 'Credentials' not in reply:
            raise RuntimeError('OIDC exchange failed: ' + str(reply.get('Code', 'unknown')))
        credentials = reply['Credentials']
        self.client = AcsClient(region_id=self.config['region'], credential=StsTokenCredential(
            credentials['AccessKeyId'], credentials['AccessKeySecret'], credentials['SecurityToken']))
        self.refresh_at = time.monotonic() + 3000

    def api(self, action, **params):
        return self.rpc(action, params, f'ecs.{self.config["region"]}.aliyuncs.com', '2014-05-26')

    def rpc(self, action, params, domain, version):
        from aliyunsdkcore.request import CommonRequest
        if time.monotonic() >= self.refresh_at:
            self.authenticate()
        request = CommonRequest()
        request.set_accept_format('json')
        request.set_protocol_type('https')
        request.set_domain(domain)
        request.set_version(version)
        request.set_action_name(action)
        request.set_method('POST')
        request.add_query_param('RegionId', self.config['region'])
        for key, value in params.items():
            if isinstance(value, bool):
                value = str(value).lower()
            elif isinstance(value, (list, dict)):
                value = json.dumps(value, separators=(',', ':'))
            request.add_query_param(key, str(value))
        try:
            # Preserve the service's AccessDeniedDetail, which the SDK's
            # exception wrapper otherwise discards.
            status, _, body = self.client.get_response(request)
            reply = json.loads(body)
        except Exception as error:
            # SDK transport errors can contain a signed URL/security token.
            # Report the action and machine-readable code, never that URL.
            code = error.get_error_code() if hasattr(error, 'get_error_code') else type(error).__name__
            raise RuntimeError(f'ECS {action} failed ({code})') from None
        if not 200 <= status < 300:
            raise ECSServiceError(action, reply)
        return reply


def ecs_error_details(reply):
    details = {key: reply[key] for key in
               ('Code', 'Message', 'RequestId', 'AccessDeniedDetail') if key in reply}
    # Transport bodies and signed URLs are never logged.
    return re.sub(r'https?://[^\s"<>]+', '[URL REDACTED]',
                  json.dumps(details, ensure_ascii=False))[:5000]


def tags(instance):
    return {tag['TagKey']: tag['TagValue'] for tag in instance.get('Tags', {}).get('Tag', [])}


def validate_template(template, image, disk):
    data_disks = template.get('DataDisks', [])
    if isinstance(data_disks, dict):
        data_disks = data_disks.get('DataDisk', [])
    if data_disks:
        raise RuntimeError('Launch template must not create data disks; retain and attach the configured disk')
    if template.get('RamRoleName'):
        raise RuntimeError('Builder template must not attach a RAM instance role')
    if not template.get('KeyPairName') or not template.get('VSwitchId'):
        raise RuntimeError('Launch template must specify an SSH key pair and vSwitch')
    if template.get('ZoneId') and template['ZoneId'] != disk['ZoneId']:
        raise RuntimeError('Launch template and retained disk are in different zones')
    mappings = image.get('DiskDeviceMappings', {}).get('DiskDeviceMapping', [])
    if not mappings or any(mapping.get('Type') != 'system' for mapping in mappings):
        raise RuntimeError('Image contains a data-disk snapshot; use a system-only image')


def create_parameters(config, template, disk, repository, run_id, attempt):
    token = hashlib.sha256(f'{repository}/{run_id}/{attempt}'.encode()).hexdigest()[:48]
    result = {
        'LaunchTemplateId': config['launch_template_id'],
        'LaunchTemplateVersion': config['launch_template_version'],
        'ZoneId': disk['ZoneId'], 'Amount': 1, 'MinAmount': 1,
        'ClientToken': token, 'InstanceName': f'chromium-ci-{run_id}-{attempt}',
        'InstanceChargeType': 'PostPaid', 'SpotStrategy': 'SpotAsPriceGo',
        # Independent upper bound if the GitHub controller itself disappears.
        'AutoReleaseTime': (datetime.now(timezone.utc) + timedelta(hours=8)).strftime('%Y-%m-%dT%H:%M:%SZ'),
        'SystemDisk.DeleteWithInstance': True,
        'InternetChargeType': 'PayByTraffic', 'InternetMaxBandwidthOut': 100,
    }
    for index, (key, value) in enumerate({
            'ci-project': PROJECT, 'ci-repository': repository,
            'ci-run': run_id, 'ci-attempt': attempt}.items(), 1):
        result[f'Tag.{index}.Key'] = key
        result[f'Tag.{index}.Value'] = value
    return result


class Controller:
    def __init__(self, config, cloud=None):
        self.config = config
        self.cloud = cloud or Cloud(config)
        self.repository = os.environ['GITHUB_REPOSITORY']
        self.run_id = os.environ['GITHUB_RUN_ID']
        self.attempt = os.environ.get('GITHUB_RUN_ATTEMPT', '1')
        if not re.fullmatch(r'\d+', self.run_id + self.attempt):
            raise ValueError('Invalid run identifier')
        self.run_key = self.run_id + '-' + self.attempt
        self.state_path = ROOT / 'build-status/cloud-state.json'
        self.state = json.loads(self.state_path.read_text()) if self.state_path.exists() else {}
        self.bootstrap = '/root/chromium-ci/' + self.run_key
        self.major = int(config['engine_major'])
        self.data_root = f'/root/chromium-{self.major}'
        self.remote_task = self.data_root + '/ci/cloud/' + self.run_key
        self.unit = 'chromium-ci-' + self.run_key
        self.ssh_key = Path(os.environ.get('RUNNER_TEMP', '/tmp')) / ('chromium-key-' + self.run_key)
        self.known_hosts = self.ssh_key.with_suffix('.known-hosts')

    def save(self, **updates):
        self.state.update(updates)
        write_json(self.state_path, self.state)

    def disk(self):
        disks = self.cloud.api('DescribeDisks', DiskIds=[self.config['disk_id']])['Disks']['Disk']
        if len(disks) != 1 or disks[0]['DiskId'] != self.config['disk_id']:
            raise RuntimeError('Configured retained disk was not found')
        return disks[0]

    def instance(self, instance_id):
        values = self.cloud.api('DescribeInstances', InstanceIds=[instance_id])['Instances']['Instance']
        return values[0] if values else None

    def own(self, instance):
        actual = tags(instance)
        expected = {'ci-project': PROJECT, 'ci-repository': self.repository,
                    'ci-run': self.run_id, 'ci-attempt': self.attempt}
        if any(actual.get(key) != value for key, value in expected.items()):
            raise RuntimeError('Refusing to manage an instance not owned by this workflow attempt')

    def wait(self, check, description, seconds=600):
        deadline = time.monotonic() + seconds
        while True:
            result = check()
            if result:
                return result
            if time.monotonic() >= deadline:
                raise TimeoutError(description)
            time.sleep(5)

    def ssh_options(self):
        return ['-i', str(self.ssh_key), '-o', 'BatchMode=yes', '-o', 'ConnectTimeout=15',
                '-o', 'ServerAliveInterval=15', '-o', 'ServerAliveCountMax=2',
                '-o', 'StrictHostKeyChecking=accept-new',
                '-o', 'UserKnownHostsFile=' + str(self.known_hosts),
                '-o', 'HostKeyAlias=' + self.state['instance_id']]

    def ssh(self, command, check=True, timeout=90):
        return subprocess.run(['ssh', *self.ssh_options(), 'root@' + self.state['ip'], command],
                              check=check, capture_output=True, text=True, timeout=timeout)

    def scp(self, source, target, receive=False):
        remote = 'root@' + self.state['ip'] + ':'
        args = [remote + source, str(target)] if receive else [str(source), remote + target]
        subprocess.run(['scp', *self.ssh_options(), *args], check=True, timeout=1800)

    def initialize(self):
        key = os.environ.get('ALIYUN_SSH_KEY', '')
        if not key.strip():
            raise RuntimeError('Missing repository secret ALIYUN_SSH_KEY')
        fd = os.open(self.ssh_key, os.O_WRONLY | os.O_CREAT | os.O_TRUNC, 0o600)
        os.fchmod(fd, 0o600)
        with os.fdopen(fd, 'w') as stream:
            stream.write(key.rstrip() + '\n')

    def diagnose(self):
        """Compare authorization contexts using RunInstances DryRun only."""
        disk = self.disk()
        reply = self.cloud.api('DescribeLaunchTemplateVersions',
                               LaunchTemplateId=self.config['launch_template_id'],
                               **{'LaunchTemplateVersion.1': self.config['launch_template_version']})
        template = reply['LaunchTemplateVersionSets']['LaunchTemplateVersionSet'][0]['LaunchTemplateData']
        params = create_parameters(self.config, template, disk, self.repository, self.run_id, self.attempt)
        expanded = dict(params)
        for key in ('ImageId', 'InstanceType', 'VSwitchId', 'SecurityGroupId', 'KeyPairName'):
            if template.get(key):
                expanded[key] = template[key]
        for key in ('Category', 'Size'):
            if template.get('SystemDisk', {}).get(key):
                expanded['SystemDisk.' + key] = template['SystemDisk'][key]
        inline = {key: value for key, value in expanded.items()
                  if key not in ('LaunchTemplateId', 'LaunchTemplateVersion')}
        results = []
        for name, probe in [('template', params), ('template-explicit', expanded), ('inline', inline)]:
            try:
                self.cloud.api('RunInstances', **probe, DryRun=True)
                result = {'probe': name, 'Code': 'UnexpectedSuccess'}
            except ECSServiceError as error:
                result = {'probe': name, **error.reply}
            results.append(result)
            print(name + ': ' + ecs_error_details(result), flush=True)
        write_json(ROOT / 'build-status/cloud-preflight.json', results)
        encoded = results[0].get('AccessDeniedDetail', {}).get('EncodedDiagnosticMessage')
        if encoded and hasattr(self.cloud, 'rpc'):
            try:
                decoded = self.cloud.rpc('DecodeDiagnosticMessage',
                                         {'EncodedDiagnosticMessage': encoded},
                                         'ram.aliyuncs.com', '2015-05-01')
                write_json(ROOT / 'build-status/cloud-permission-decoded.json', decoded)
                print('Decoded permission diagnosis: ' + json.dumps(decoded, ensure_ascii=False), flush=True)
            except ECSServiceError as error:
                print('Permission diagnosis could not be decoded: ' + ecs_error_details(error.reply), flush=True)

    def provision(self):
        self.initialize()
        branch = os.environ['GITHUB_REF_NAME']
        if branch != f'hmos-{self.major}-adapter':
            raise RuntimeError('Configured data disk does not match this engine branch')
        disk = self.disk()
        if disk['Status'] != 'Available' or disk.get('InstanceId'):
            raise RuntimeError('Retained disk is still attached/in use; detach it from the manual builder first')
        template = self.cloud.api('DescribeLaunchTemplateVersions',
                                  LaunchTemplateId=self.config['launch_template_id'],
                                  **{'LaunchTemplateVersion.1': self.config['launch_template_version']})
        template = template['LaunchTemplateVersionSets']['LaunchTemplateVersionSet'][0]['LaunchTemplateData']
        images = self.cloud.api('DescribeImages', ImageId=template['ImageId'])['Images']['Image']
        if len(images) != 1:
            raise RuntimeError('Template image was not found')
        validate_template(template, images[0], disk)
        params = create_parameters(self.config, template, disk, self.repository, self.run_id, self.attempt)
        reply = self.cloud.api('RunInstances', **params)
        instance_id = reply['InstanceIdSets']['InstanceIdSet'][0]
        self.save(instance_id=instance_id, disk_id=disk['DiskId'], run_key=self.run_key)
        # Persist immediately, before any other operation can fail or be cancelled.
        github_output('instance_id', instance_id)
        print('Created builder', instance_id, flush=True)

        def running():
            instance = self.instance(instance_id)
            if not instance:
                return None
            self.own(instance)
            return instance if instance['Status'] == 'Running' else None
        instance = self.wait(running, 'Instance did not start')
        addresses = instance.get('PublicIpAddress', {}).get('IpAddress', [])
        if not addresses:
            raise RuntimeError('Launch template did not provide a public IPv4 address')
        ip = str(ipaddress.ip_address(addresses[0]))
        self.save(ip=ip)
        self.cloud.api('AttachDisk', InstanceId=instance_id, DiskId=disk['DiskId'], DeleteWithInstance=False)

        def attached():
            current = self.disk()
            if current.get('InstanceId') == instance_id and current['Status'] == 'In_use':
                if current.get('DeleteWithInstance') is not False:
                    raise RuntimeError('Retained disk is not protected from instance deletion')
                return current
            return None
        self.wait(attached, 'Disk did not attach')

        def ssh_ready():
            try:
                return self.ssh('true', check=False, timeout=25).returncode == 0
            except subprocess.TimeoutExpired:
                return False
        self.wait(ssh_ready, 'SSH did not become ready')
        print('Builder and retained disk ready', flush=True)

    def run(self):
        self.initialize()
        sha = os.environ['GITHUB_SHA']
        if not re.fullmatch(r'[a-f0-9]{40}', sha):
            raise ValueError('Invalid commit')
        bundle = Path(os.environ.get('RUNNER_TEMP', '/tmp')) / ('chromium-' + self.run_key + '.bundle')
        subprocess.run(['git', 'bundle', 'create', str(bundle), sha, '--branches', '--tags'],
                       cwd=ROOT, check=True)
        self.ssh('mkdir -p ' + shlex.quote(self.bootstrap))
        request = {
            'sha': sha, 'branch': os.environ['GITHUB_REF_NAME'], 'run_key': self.run_key,
            'disk_uuid': self.config['disk_uuid'], 'major': self.major, 'jobs': self.config['jobs'],
            'package': os.environ.get('CLOUD_PACKAGE', 'true') == 'true',
            'crash_build_id': os.environ.get('CRASH_BUILD_ID', ''),
            'crash_addresses': os.environ.get('CRASH_ADDRESSES', ''),
        }
        local_request = bundle.with_suffix('.json')
        write_json(local_request, request)
        for local, name in [(bundle, 'repo.bundle'), (local_request, 'request.json'),
                            (HERE / 'remote.sh', 'remote.sh')]:
            self.scp(local, self.bootstrap + '/' + name)
        command = ['systemd-run', '--unit=' + self.unit, '--collect',
                   '--property=KillMode=control-group', '--property=RuntimeMaxSec=18300',
                   '--property=TimeoutStopSec=60', '/bin/bash', self.bootstrap + '/remote.sh',
                   self.bootstrap]
        self.ssh(shlex.join(command))
        deadline = time.monotonic() + 18000
        offset = 0
        failures = 0
        while time.monotonic() < deadline:
            code = (
                'import pathlib,json,subprocess; r=pathlib.Path(' + repr(self.bootstrap) + '); '
                'p=r/"build.log"; f=p.open("rb") if p.exists() else None; '
                f'f.seek({offset}) if f else None; data=f.read(131072) if f else b""; '
                'rc=r/"exit-code"; '
                'unit=subprocess.run(["systemctl","show","--property=ActiveState","--value",' +
                repr(self.unit + '.service') + '],capture_output=True,text=True).stdout.strip(); '
                'status=int(rc.read_text()) if rc.exists() else '
                '(125 if unit not in ("active","activating","deactivating") else None); '
                'print(json.dumps({"log":data.decode(errors="replace"),'
                '"size":len(data),"exit":status}))')
            try:
                reply = self.ssh('python3 -c ' + shlex.quote(code), timeout=60)
                result = json.loads(reply.stdout)
                failures = 0
            except (subprocess.SubprocessError, json.JSONDecodeError):
                failures += 1
                if failures >= 6:
                    raise RuntimeError('SSH unavailable; instance may have been reclaimed. Cache remains on data disk')
                time.sleep(10)
                continue
            print(result['log'], end='', flush=True)
            offset += result['size']
            if result['exit'] is not None and result['size'] < 131072:
                self.save(build_exit=result['exit'])
                if result['exit']:
                    raise RuntimeError(f'Remote build failed, exit {result["exit"]}')
                return
            time.sleep(10)
        raise TimeoutError('Remote build exceeded five hours')

    def fetch(self):
        if not self.state.get('ip'):
            return
        self.initialize()
        # The remote task keeps artifacts on the retained disk, not /tmp.
        destination = ROOT / 'build-status/cloud'
        destination.mkdir(parents=True, exist_ok=True)
        command = 'tar -C ' + shlex.quote(self.remote_task) + ' -czf ' + shlex.quote(
            self.remote_task + '/diagnostics.tar.gz') + ' build.log status request.json'
        result = self.ssh(command, check=False, timeout=120)
        if result.returncode:
            # The disk may not have mounted yet; collect bootstrap errors too.
            result = self.ssh('cat ' + shlex.quote(self.bootstrap + '/build.log'), check=False)
            (destination / 'bootstrap.log').write_text(result.stdout)
            raise RuntimeError('Remote diagnostics not available; see bootstrap.log')
        self.scp(self.remote_task + '/diagnostics.tar.gz', destination / 'diagnostics.tar.gz', receive=True)
        manifest_reply = self.ssh('cat ' + shlex.quote(self.remote_task + '/artifacts/manifest.json'), check=False)
        if manifest_reply.returncode:
            if self.state.get('build_exit') == 0:
                raise RuntimeError('Build succeeded but artifact manifest is missing')
            return
        manifest = json.loads(manifest_reply.stdout)
        if manifest['commit'] != os.environ['GITHUB_SHA']:
            raise RuntimeError('Artifact commit does not match the workflow')
        artifacts = ROOT / 'cloud-artifacts'
        artifacts.mkdir(exist_ok=True)
        for entry in manifest['files']:
            name = entry['name']
            if Path(name).name != name or name in ('', '.', '..'):
                raise RuntimeError('Invalid artifact filename')
            target = artifacts / name
            self.scp(self.remote_task + '/artifacts/' + name, target, receive=True)
            with target.open('rb') as stream:
                digest = hashlib.file_digest(stream, 'sha256').hexdigest()
            if target.stat().st_size != entry['bytes'] or digest != entry['sha256']:
                raise RuntimeError('Artifact checksum mismatch: ' + name)
        write_json(artifacts / 'manifest.json', manifest)
        self.save(artifacts_verified=True)

    def cleanup(self):
        # Discovery also covers cancellation/lost responses before saving the ID.
        values = []
        for attempt in range(4):
            reply = self.cloud.api('DescribeInstances', **{
                'Tag.1.Key': 'ci-project', 'Tag.1.Value': PROJECT,
                'Tag.2.Key': 'ci-repository', 'Tag.2.Value': self.repository,
                'Tag.3.Key': 'ci-run', 'Tag.3.Value': self.run_id,
                'Tag.4.Key': 'ci-attempt', 'Tag.4.Value': self.attempt, 'PageSize': 100})
            values = reply['Instances']['Instance']
            if values or attempt == 3:
                break
            time.sleep(10)
        for instance in values:
            self.cleanup_instance(instance)

    def cleanup_instance(self, instance):
        self.own(instance)
        instance_id = instance['InstanceId']
        if instance.get('OperationLocks', {}).get('LockReason'):
            raise RuntimeError('Instance has operation locks; retaining it to protect the data disk')
        disk = self.disk()
        if disk.get('InstanceId') == instance_id and disk.get('DeleteWithInstance') is not False:
            raise RuntimeError('Refusing deletion while retained disk has DeleteWithInstance enabled')
        if instance['Status'] not in ('Running', 'Stopped', 'Stopping'):
            self.wait(lambda: (value := self.instance(instance_id)) is None or
                      value['Status'] in ('Running', 'Stopped', 'Stopping'),
                      'Instance creation/state transition did not settle; preserving it')
            instance = self.instance(instance_id)
            if instance is None:
                return
        # Best-effort orderly shutdown: systemd owns all Ninja child process
        # groups, including stopped ones. Cloud StopInstance is the fallback.
        addresses = instance.get('PublicIpAddress', {}).get('IpAddress', [])
        if instance['Status'] == 'Running' and addresses and os.environ.get('ALIYUN_SSH_KEY'):
            self.save(instance_id=instance_id, ip=str(ipaddress.ip_address(addresses[0])))
            self.initialize()
            stop = ['systemctl', 'stop', self.unit + '.service']
            try:
                self.ssh(shlex.join(stop), check=False, timeout=90)
                self.ssh('sync', check=False, timeout=90)
            except subprocess.SubprocessError:
                pass
        # Stop gracefully even if the SSH upload/poll failed. Never force-delete
        # an active builder or release a disk. Stop -> detach -> verify -> delete.
        if instance['Status'] not in ('Stopped', 'Stopping'):
            self.cloud.api('StopInstance', InstanceId=instance_id, ForceStop=False)
        self.wait(lambda: (value := self.instance(instance_id)) is None or value['Status'] == 'Stopped',
                  'Builder did not stop; instance preserved', seconds=600)
        disk = self.disk()
        if disk.get('InstanceId') == instance_id:
            self.cloud.api('DetachDisk', InstanceId=instance_id, DiskId=self.config['disk_id'])
            self.wait(lambda: self.disk()['Status'] == 'Available',
                      'Disk did not detach; instance preserved', seconds=600)
        other_data_disks = self.cloud.api('DescribeDisks', InstanceId=instance_id,
                                          DiskType='data')['Disks']['Disk']
        if other_data_disks:
            raise RuntimeError('Instance still has data disks attached; refusing to delete it')
        if self.instance(instance_id):
            self.cloud.api('DeleteInstance', InstanceId=instance_id, Force=False)
            self.wait(lambda: self.instance(instance_id) is None, 'Instance deletion did not finish')
        print('Released builder; retained disk preserved:', instance_id, flush=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('command', choices=['provision', 'run', 'fetch', 'cleanup', 'diagnose'])
    args = parser.parse_args()
    config = json.loads((HERE / 'config.json').read_text())
    controller = Controller(config)
    getattr(controller, args.command)()


if __name__ == '__main__':
    try:
        main()
    except Exception as error:
        # Never dump HTTP bodies, signed requests or credentials on auth errors.
        print(f'Cloud CI failed: {type(error).__name__}: {error}', file=sys.stderr)
        sys.exit(1)
