#!/usr/bin/env python3
"""Exercise orchestration failures with an in-memory ECS and real cache/Git fixtures.

No SSH, cloud authentication, provisioning or other network traffic is used.
"""
import copy
import hashlib
import importlib.util
import io
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
import urllib.error
import urllib.request
from unittest.mock import patch

sys.dont_write_bytecode = True
ROOT = Path(__file__).resolve().parents[2]


def load(name, path):
    spec = importlib.util.spec_from_file_location(name, ROOT / path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


cloud = load('cloud_ci', '.github/cloud/cloud.py')
cache = load('cache_health', '.github/cloud/cache-health.py')
snapshot = load('snapshot157', 'scripts/apply-157-snapshot.py')
publisher = load('cloud_publisher', '.github/cloud/publish.py')
CONFIG = json.loads((ROOT / '.github/cloud/config.json').read_text())


def owned_instance():
    return {'InstanceId': 'i-builder', 'Status': 'Running',
            'PublicIpAddress': {'IpAddress': ['192.0.2.10']},
            'Tags': {'Tag': [{'TagKey': key, 'TagValue': value} for key, value in {
                'ci-project': 'chromium-hmos', 'ci-repository': 'owner/repo',
                'ci-run': '123', 'ci-attempt': '1'}.items()]}}


class FakeECS:
    def __init__(self):
        self.calls = []
        self.instance = None
        self.disk = {'DiskId': CONFIG['disk_id'], 'Status': 'Available',
                     'ZoneId': 'eu-central-1a', 'InstanceId': '', 'DeleteWithInstance': False}
        self.template = {'ImageId': 'm-system-only', 'KeyPairName': 'builder-key',
                         'VSwitchId': 'vsw-test', 'DataDisks': {'DataDisk': []}}
        self.image = {'DiskDeviceMappings': {'DiskDeviceMapping': [{'Type': 'system'}]}}
        self.extra_data_disk = False

    def api(self, action, **params):
        self.calls.append((action, copy.deepcopy(params)))
        if action == 'DescribeDisks':
            if 'InstanceId' in params:
                return {'Disks': {'Disk': [{'DiskId': 'd-unexpected'}] if self.extra_data_disk else []}}
            return {'Disks': {'Disk': [copy.deepcopy(self.disk)]}}
        if action == 'DescribeLaunchTemplateVersions':
            return {'LaunchTemplateVersionSets': {'LaunchTemplateVersionSet': [
                {'LaunchTemplateData': copy.deepcopy(self.template)}]}}
        if action == 'DescribeImages':
            return {'Images': {'Image': [copy.deepcopy(self.image)]}}
        if action == 'RunInstances':
            self.instance = owned_instance()
            return {'InstanceIdSets': {'InstanceIdSet': ['i-builder']}}
        if action == 'DescribeInstances':
            return {'Instances': {'Instance': [copy.deepcopy(self.instance)] if self.instance else []}}
        if action == 'AttachDisk':
            self.disk.update(Status='In_use', InstanceId=params['InstanceId'],
                             DeleteWithInstance=params['DeleteWithInstance'])
            return {}
        if action == 'StopInstance':
            assert params['ForceStop'] is False
            self.instance['Status'] = 'Stopped'
            return {}
        if action == 'DetachDisk':
            assert self.instance['Status'] == 'Stopped'
            self.disk.update(Status='Available', InstanceId='')
            return {}
        if action == 'DeleteInstance':
            assert self.disk['Status'] == 'Available' and self.disk['DeleteWithInstance'] is False
            assert params['Force'] is False
            self.instance = None
            return {}
        raise AssertionError(action)


class LifecycleTest(unittest.TestCase):
    def setUp(self):
        self.folder = tempfile.TemporaryDirectory()
        self.root = Path(self.folder.name)
        self.env = patch.dict(os.environ, {'GITHUB_REPOSITORY': 'owner/repo',
                              'GITHUB_RUN_ID': '123', 'GITHUB_RUN_ATTEMPT': '1',
                              'GITHUB_REF_NAME': 'hmos-157-adapter',
                              'GITHUB_SHA': '1' * 40, 'RUNNER_TEMP': str(self.root)}, clear=True)
        self.env.start()
        self.root_patch = patch.object(cloud, 'ROOT', self.root)
        self.root_patch.start()
        self.ecs = FakeECS()
        self.controller = cloud.Controller(CONFIG, self.ecs)
        self.controller.initialize = lambda: None
        self.controller.ssh = lambda *args, **kwargs: subprocess.CompletedProcess([], 0, '{}', '')

    def tearDown(self):
        self.root_patch.stop()
        self.env.stop()
        self.folder.cleanup()

    def test_create_attach_and_cleanup_retains_only_disk(self):
        self.controller.provision()
        self.assertFalse(self.ecs.disk['DeleteWithInstance'])
        self.assertEqual(json.loads(self.controller.state_path.read_text())['instance_id'], 'i-builder')
        self.controller.cleanup()
        self.assertIsNone(self.ecs.instance)
        self.assertEqual(self.ecs.disk['Status'], 'Available')
        mutations = [name for name, _ in self.ecs.calls if not name.startswith('Describe')]
        self.assertEqual(mutations, ['RunInstances', 'AttachDisk', 'StopInstance', 'DetachDisk', 'DeleteInstance'])

    def test_permission_probes_never_create_or_attach_resources(self):
        original = self.ecs.api
        probes = []
        def api(action, **params):
            if action == 'RunInstances':
                self.assertIs(params.get('DryRun'), True)
                probes.append(params)
                code = 'Forbidden.RAM' if len(probes) == 1 else 'DryRunOperation'
                raise cloud.ECSServiceError(action, {'Code': code})
            self.assertTrue(action.startswith('Describe'))
            return original(action, **params)
        self.ecs.api = api
        self.controller.diagnose()
        self.assertEqual(len(probes), 3)
        self.assertNotIn('LaunchTemplateId', probes[-1])
        self.assertIsNone(self.ecs.instance)
        self.assertEqual(self.ecs.disk['Status'], 'Available')

    def test_occupied_disk_fails_before_spending_on_a_new_instance(self):
        self.ecs.disk.update(Status='In_use', InstanceId='i-manual-paused')
        with self.assertRaisesRegex(RuntimeError, 'still attached'):
            self.controller.provision()
        self.assertEqual([name for name, _ in self.ecs.calls], ['DescribeDisks'])

    def test_wrong_engine_cannot_touch_disk(self):
        os.environ['GITHUB_REF_NAME'] = 'hmos-155-adapter'
        with self.assertRaisesRegex(RuntimeError, 'does not match'):
            self.controller.provision()
        self.assertEqual(self.ecs.calls, [])

    def test_rejects_template_data_disk_or_image_snapshot_before_create(self):
        for mode in ('template', 'image'):
            with self.subTest(mode=mode):
                self.ecs.template['DataDisks'] = {'DataDisk': [{'SnapshotId': 's-old'}]} if mode == 'template' else []
                self.ecs.image['DiskDeviceMappings']['DiskDeviceMapping'] = [
                    {'Type': 'system'}, {'Type': 'data'}] if mode == 'image' else [{'Type': 'system'}]
                with self.assertRaisesRegex(RuntimeError, 'data.disk'):
                    self.controller.provision()
                self.assertNotIn('RunInstances', [name for name, _ in self.ecs.calls])

    def test_preserve_instance_if_data_disk_deletion_flag_is_wrong(self):
        self.controller.provision()
        self.ecs.calls.clear()
        self.ecs.disk['DeleteWithInstance'] = True
        with self.assertRaisesRegex(RuntimeError, 'Refusing deletion'):
            self.controller.cleanup_instance(self.ecs.instance)
        self.assertFalse(any(not name.startswith('Describe') for name, _ in self.ecs.calls))

    def test_cleanup_will_not_delete_another_run_or_manual_instance(self):
        foreign = owned_instance()
        foreign['Tags']['Tag'][2]['TagValue'] = '999'
        with self.assertRaisesRegex(RuntimeError, 'not owned'):
            self.controller.cleanup_instance(foreign)
        self.assertEqual(self.ecs.calls, [])

    def test_orphan_discovery_does_not_require_local_state(self):
        self.ecs.instance = owned_instance()
        self.ecs.disk.update(Status='In_use', InstanceId='i-builder')
        self.assertFalse(self.controller.state_path.exists())
        self.controller.cleanup()
        self.assertIsNone(self.ecs.instance)

    def test_cleanup_preserves_instance_on_security_lock(self):
        instance = owned_instance()
        instance['OperationLocks'] = {'LockReason': [{'LockReason': 'security'}]}
        with self.assertRaisesRegex(RuntimeError, 'operation locks'):
            self.controller.cleanup_instance(instance)
        self.assertEqual(self.ecs.calls, [])

    def test_unexpected_attached_disk_prevents_instance_deletion(self):
        self.controller.provision()
        self.ecs.extra_data_disk = True
        with self.assertRaisesRegex(RuntimeError, 'still has data disks'):
            self.controller.cleanup()
        self.assertIsNotNone(self.ecs.instance)
        self.assertEqual(self.ecs.instance['Status'], 'Stopped')

    def test_creation_is_idempotent_spot_only_and_bound_to_pinned_template(self):
        args = (CONFIG, self.ecs.template, self.ecs.disk, 'owner/repo', '123', '1')
        first = cloud.create_parameters(*args)
        second = cloud.create_parameters(*args)
        self.assertEqual(first['ClientToken'], second['ClientToken'])
        self.assertEqual(first['LaunchTemplateVersion'], CONFIG['launch_template_version'])
        self.assertEqual(first['SpotStrategy'], 'SpotAsPriceGo')
        self.assertEqual(first['SpotDuration'], 1)
        self.assertEqual(first['InstanceChargeType'], 'PostPaid')
        self.assertEqual(first['Amount'], 1)
        self.assertIn('AutoReleaseTime', first)

    def test_template_zone_and_ram_role_are_checked_before_spending(self):
        for key, value in [('ZoneId', 'other-zone'), ('RamRoleName', 'unrelated-role')]:
            with self.subTest(key=key):
                template = dict(self.ecs.template, **{key: value})
                with self.assertRaises(RuntimeError):
                    cloud.validate_template(template, self.ecs.image, self.ecs.disk)

    def test_already_stopped_builder_can_release_without_force_stop(self):
        self.controller.provision()
        self.ecs.instance['Status'] = 'Stopped'
        self.ecs.calls.clear()
        self.controller.cleanup()
        self.assertNotIn('StopInstance', [name for name, _ in self.ecs.calls])
        self.assertIsNone(self.ecs.instance)

    def test_same_disk_moved_elsewhere_is_not_detached_from_other_instance(self):
        self.controller.provision()
        self.ecs.disk.update(Status='In_use', InstanceId='i-manual')
        self.ecs.calls.clear()
        # The fake catches deletion while the disk is not Available. Stop
        # before deletion to inspect the real detach decision independently.
        original_api = self.ecs.api
        def api(action, **params):
            if action == 'DeleteInstance':
                self.ecs.calls.append((action, params))
                self.ecs.instance = None
                return {}
            return original_api(action, **params)
        self.ecs.api = api
        self.controller.cleanup()
        self.assertNotIn('DetachDisk', [name for name, _ in self.ecs.calls])
        self.assertEqual(self.ecs.disk['InstanceId'], 'i-manual')

    def test_ssh_secret_is_written_only_to_private_temporary_file(self):
        os.environ['ALIYUN_SSH_KEY'] = 'test-only-key-material'
        cloud.Controller.initialize(self.controller)
        self.assertEqual(self.controller.ssh_key.stat().st_mode & 0o777, 0o600)
        self.assertEqual(self.controller.ssh_key.read_text(), 'test-only-key-material\n')
        self.assertFalse(self.controller.state_path.exists())

    def test_remote_failure_is_not_reported_as_a_successful_build(self):
        self.controller.save(instance_id='i-builder', ip='192.0.2.10')
        self.controller.scp = lambda *args, **kwargs: None
        commands = []
        def ssh(command, **kwargs):
            commands.append(command)
            result = {'log': 'compile failed\n', 'size': 15, 'exit': 17}
            return subprocess.CompletedProcess([], 0, json.dumps(result), '')
        self.controller.ssh = ssh
        with patch.object(cloud.subprocess, 'run'), self.assertRaisesRegex(RuntimeError, 'exit 17'):
            self.controller.run()
        self.assertEqual(self.controller.state['build_exit'], 17)
        self.assertTrue(any('KillMode=control-group' in value for value in commands))
        launch = next(value for value in commands if value.startswith('systemd-run '))
        self.assertIn('--property=User=root', launch)
        self.assertIn('--property=SetLoginEnvironment=yes', launch)
        self.assertEqual(self.ecs.calls, [])

    def test_lost_ssh_fails_without_creating_a_second_instance(self):
        self.controller.save(instance_id='i-builder', ip='192.0.2.10')
        self.controller.scp = lambda *args, **kwargs: None
        def ssh(command, **kwargs):
            if command.startswith('python3'):
                raise subprocess.TimeoutExpired('ssh', 60)
            return subprocess.CompletedProcess([], 0, '', '')
        self.controller.ssh = ssh
        with patch.object(cloud.subprocess, 'run'), patch.object(cloud.time, 'sleep'):
            with self.assertRaisesRegex(RuntimeError, 'SSH unavailable'):
                self.controller.run()
        self.assertEqual(self.ecs.calls, [])

    def test_artifacts_from_another_commit_are_rejected(self):
        self.controller.save(instance_id='i-builder', ip='192.0.2.10')
        self.controller.scp = lambda *args, **kwargs: None
        def ssh(command, **kwargs):
            reply = {'commit': '2' * 40, 'files': []}
            return subprocess.CompletedProcess([], 0, json.dumps(reply), '')
        self.controller.ssh = ssh
        with self.assertRaisesRegex(RuntimeError, 'commit does not match'):
            self.controller.fetch()
        self.assertNotIn('artifacts_verified', self.controller.state)

    def test_artifact_paths_cannot_escape_download_directory(self):
        self.controller.save(instance_id='i-builder', ip='192.0.2.10')
        self.controller.scp = lambda *args, **kwargs: None
        def ssh(command, **kwargs):
            reply = {'commit': '1' * 40, 'files': [{'name': '../escaped.har'}]}
            return subprocess.CompletedProcess([], 0, json.dumps(reply), '')
        self.controller.ssh = ssh
        with self.assertRaisesRegex(RuntimeError, 'Invalid artifact filename'):
            self.controller.fetch()

    def test_corrupted_download_cannot_be_marked_verified(self):
        self.controller.save(instance_id='i-builder', ip='192.0.2.10')
        def scp(source, target, **kwargs):
            Path(target).write_bytes(b'bad')
        self.controller.scp = scp
        def ssh(command, **kwargs):
            reply = {'commit': '1' * 40, 'files': [{'name': 'engine.har', 'bytes': 4,
                     'sha256': hashlib.sha256(b'good').hexdigest()}]}
            return subprocess.CompletedProcess([], 0, json.dumps(reply), '')
        self.controller.ssh = ssh
        with self.assertRaisesRegex(RuntimeError, 'checksum mismatch'):
            self.controller.fetch()
        self.assertNotIn('artifacts_verified', self.controller.state)

    def test_ram_policy_covers_calls_without_granting_disk_deletion(self):
        self.controller.provision()
        self.controller.cleanup()
        policy = json.loads((ROOT / '.github/cloud/ram-policy.json').read_text())
        actions = set()
        for statement in policy['Statement']:
            value = statement['Action']
            actions.update(value if isinstance(value, list) else [value])
        self.assertTrue(all('ecs:' + action in actions for action, _ in self.ecs.calls))
        self.assertNotIn('ecs:DeleteDisk', actions)
        self.assertNotIn('ecs:*', actions)


class CacheTest(unittest.TestCase):
    def test_live_progress_samples_actual_step_numbers_across_ninja_phases(self):
        with tempfile.TemporaryDirectory() as folder, patch.dict(os.environ, {
                'GITHUB_SHA': '1' * 40, 'GITHUB_REPOSITORY': 'owner/repo', 'GITHUB_RUN_ID': '123'}):
            progress = cloud.ProgressPublisher(Path(folder))
            uploaded = []
            progress.upload = lambda value: uploaded.append(value.copy())
            progress.consume('[1/14] preflight\n[14/14] done\n[1/201] main\n[49/201] skip\n[5')
            progress.consume('0/201] source\n[50/201] duplicate\n[100/201] source\n[201/201] done\n')
            self.assertEqual([(item['steps'], item['total']) for item in uploaded],
                             [(1, 14), (14, 14), (1, 201), (50, 201), (100, 201), (201, 201)])
            self.assertEqual(uploaded[-1]['percent'], 100)
            self.assertEqual(json.loads((Path(folder) / 'progress.json').read_text())['steps'], 201)

    def test_progress_upload_failure_keeps_latest_snapshot_for_retry(self):
        with tempfile.TemporaryDirectory() as folder, patch.dict(os.environ, {
                'GITHUB_SHA': '1' * 40, 'GITHUB_REPOSITORY': 'owner/repo', 'GITHUB_RUN_ID': '123'}):
            progress = cloud.ProgressPublisher(Path(folder))
            progress.upload = lambda value: (_ for _ in ()).throw(RuntimeError('offline'))
            progress.consume('[50/200] target\n')
            self.assertEqual(progress.pending['steps'], 50)
            uploaded = []
            progress.upload = lambda value: uploaded.append(value.copy())
            progress.flush()
            self.assertIsNone(progress.pending)
            self.assertEqual(uploaded[0]['steps'], 50)

    def test_progress_api_reloads_revision_after_final_status_rewrites_branch(self):
        with patch.dict(os.environ, {'GITHUB_REPOSITORY': 'owner/repo'}):
            progress = cloud.ProgressPublisher()
            progress.blob_sha = 'stale'
            replies = [subprocess.CompletedProcess([], 1, '', '(HTTP 409)'),
                       subprocess.CompletedProcess([], 0, '{"sha":"current"}', ''),
                       subprocess.CompletedProcess([], 0, '{"content":{"sha":"next"}}', '')]
            with patch.object(cloud.subprocess, 'run', side_effect=replies) as run:
                progress.upload({'run_id': '123', 'steps': 50, 'total': 200})
            self.assertEqual(progress.blob_sha, 'next')
            self.assertEqual(json.loads(run.call_args.kwargs['input'])['sha'], 'current')

    def test_ecs_diagnostics_preserve_denial_details_without_signed_urls(self):
        message = cloud.ecs_error_details({
            'Code': 'Forbidden.RAM', 'Message': 'Denied https://ecs.test/?SecurityToken=secret',
            'RequestId': 'request-test',
            'AccessDeniedDetail': {'AuthAction': 'ecs:RunInstances', 'PolicyType': 'AccountLevelIdentityBasedPolicy'},
            'Transport': 'private-value'})
        self.assertIn('ecs:RunInstances', message)
        self.assertIn('request-test', message)
        self.assertNotIn('secret', message)
        self.assertNotIn('private-value', message)

    def test_oidc_role_trust_uses_ram_action_not_the_sts_api_name(self):
        trust = json.loads((ROOT / '.github/cloud/trust-policy.json').read_text())['Statement'][0]
        self.assertIn('sts:AssumeRole', trust['Action'])
        self.assertNotIn('sts:AssumeRoleWithOIDC', trust['Action'])
        self.assertEqual(trust['Principal']['Federated'], CONFIG['oidc_provider_arn'])
        self.assertEqual(trust['Condition']['StringEquals']['oidc:aud'], CONFIG['audience'])
        self.assertEqual(trust['Condition']['StringLike']['oidc:sub'],
                         'repo:miramira8295@300834246/chromium-hmos@1372926316:ref:refs/heads/*')

    def test_unsigned_sts_exchange_includes_mandatory_common_parameters(self):
        first = cloud.oidc_parameters(CONFIG, 'test-only-token', '123')
        second = cloud.oidc_parameters(CONFIG, 'test-only-token', '123')
        self.assertRegex(first['Timestamp'], r'^\d{4}-\d\d-\d\dT\d\d:\d\d:\d\dZ$')
        self.assertNotEqual(first['SignatureNonce'], second['SignatureNonce'])
        self.assertEqual(first['OIDCToken'], 'test-only-token')
        self.assertEqual(first['RoleArn'], CONFIG['role_arn'])

    def test_auth_error_diagnostics_do_not_expose_oidc_token(self):
        reply = json.dumps({'Code': 'InvalidIdentityToken', 'Message': 'Rejected test-sensitive-token'}).encode()
        error = urllib.error.HTTPError('https://sts.aliyuncs.com/', 400, 'Bad Request', {}, io.BytesIO(reply))
        with patch.object(cloud.urllib.request, 'urlopen', side_effect=error):
            with self.assertRaises(RuntimeError) as raised:
                cloud.http_json(urllib.request.Request('https://sts.aliyuncs.com/'),
                                'STS', ['test-sensitive-token'])
        self.assertIn('InvalidIdentityToken', str(raised.exception))
        self.assertNotIn('test-sensitive-token', str(raised.exception))

    def test_status_publication_builds_an_orphan_tree_without_changing_checkout(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            def git(*args):
                return subprocess.check_output(['git', '-C', str(root), *args], text=True).strip()
            git('init', '-q')
            (root / 'controller.py').write_text('controller source\n')
            git('add', '.')
            git('-c', 'user.name=Test', '-c', 'user.email=test@example.invalid', 'commit', '-qm', 'source')
            original_head = git('rev-parse', 'HEAD')
            (root / 'build-status').mkdir()
            (root / 'build-status/latest.json').write_text('{"status":"ok"}')
            original_call = publisher.call
            pushed = []
            def call(*args, **kwargs):
                if args[:2] == ('git', 'push'):
                    pushed.append(args[-1].split(':')[0])
                    return subprocess.CompletedProcess(args, 0)
                return original_call(*args, **kwargs)
            with patch.object(publisher, 'ROOT', root), patch.object(publisher, 'call', call), patch.dict(
                    os.environ, {'GITHUB_SHA': original_head, 'CLOUD_JOB_STATUS': 'success'}):
                publisher.status()
            self.assertEqual(git('rev-parse', 'HEAD'), original_head)
            self.assertEqual(git('diff', '--cached', '--name-only'), '')
            self.assertEqual(git('ls-tree', '-r', '--name-only', pushed[0]), 'build-status/latest.json')
            self.assertEqual(git('rev-list', '--parents', '-n1', pushed[0]), pushed[0])

    def test_remote_bootstrap_failure_records_exit_before_any_disk_operation(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            (root / 'request.json').write_text('{"sha":"invalid"}')
            result = subprocess.run(['bash', str(ROOT / '.github/cloud/remote.sh'), str(root)],
                                    capture_output=True, text=True)
            self.assertNotEqual(result.returncode, 0)
            self.assertEqual(int((root / 'exit-code').read_text()), result.returncode)
            self.assertIn('Remote task exited', (root / 'build.log').read_text())

    def test_only_incomplete_generated_files_are_invalidated(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            for name, data in [('valid.o', b'ELF'), ('incomplete.o', b''),
                               ('incomplete.js', b''), ('valid.stamp', b''),
                               ('source.cc', b''), ('unknown.o', b'')]:
                (root / name).write_bytes(data)
            (root / 'outside.o').symlink_to(root / 'valid.o')
            (root / '.ninja_log').write_text('# ninja log v7\n' + ''.join(
                f'1\t2\t3\t{name}\tabc\n' for name in
                ['valid.o', 'incomplete.o', 'incomplete.js', 'valid.stamp', 'source.cc', 'outside.o']))
            removed = cache.repair(root, root / 'report.json')
            self.assertEqual(removed, ['incomplete.js', 'incomplete.o'])
            for name in ['valid.o', 'valid.stamp', 'source.cc', 'unknown.o', 'outside.o']:
                self.assertTrue((root / name).exists())

    def test_reset_invalidates_snapshot_receipt(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            def git(*args):
                return subprocess.check_output(['git', '-C', str(root), *args], text=True).strip()
            git('init', '-q')
            (root / 'source.cc').write_text('upstream\n')
            git('add', '.')
            git('-c', 'user.name=Test', '-c', 'user.email=test@example.invalid', 'commit', '-qm', 'base')
            (root / 'source.cc').write_text('adapted\n')
            git('add', '.')
            receipt, index_receipt = root / '.git/receipt', root / '.git/index-receipt'
            receipt.write_text('revision:patch')
            index_receipt.write_text(git('write-tree'))
            self.assertTrue(snapshot.snapshot_is_current(root, receipt, index_receipt, 'revision:patch'))
            git('reset', '--hard', 'HEAD')
            self.assertFalse(snapshot.snapshot_is_current(root, receipt, index_receipt, 'revision:patch'))


if __name__ == '__main__':
    unittest.main()
