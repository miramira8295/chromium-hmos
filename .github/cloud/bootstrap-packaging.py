#!/usr/bin/env python3
"""Bootstrap the Linux packaging SDK on the retained disk.

Uses the same public Huawei CLT mirror as libsdl-org/SDL CI. Each range
is checked, unzip validates CRCs, and the imported archive SHA256 is recorded.
The existing Chromium native SDK and its sysroot are not changed.
"""
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor,wait,FIRST_COMPLETED
import hashlib,json,shutil,subprocess,sys,time,urllib.request,zipfile

root=Path(sys.argv[1]).resolve()
version='6.1.1.280'
url='https://libsdl.org/harmonyos-devtools/commandline-tools-linux-x64-'+version+'.zip'
size=2141466303
expected_sha256='b9caf7b73c541b90e6c8f3c7c3de7f2bea9b35e41e80cd3525f2f759ebf16cf4'
target=root/('harmonyos-clt-'+version)
assert subprocess.run(['mountpoint','-q',str(root.parent)]).returncode==0
if target.exists():
    raise RuntimeError('Toolchain destination already exists; validate it before replacing it')
parts=root/('clt-'+version+'-download-parts')
parts.mkdir(exist_ok=True)
count=16
width=(size+count-1)//count

def fetch(index):
    start=index*width
    end=min(size-1,start+width-1)
    path=parts/f'{index:02}.part'
    if path.exists() and path.stat().st_size==end-start+1: return path
    for attempt in range(3):
        try:
            request=urllib.request.Request(url,headers={'Range':f'bytes={start}-{end}'})
            with urllib.request.urlopen(request,timeout=120) as response:
                assert response.status==206, 'Server must honor byte ranges'
                assert response.headers['Content-Range']==f'bytes {start}-{end}/{size}'
                with path.open('wb') as output:
                    shutil.copyfileobj(response,output,1024*1024)
            assert path.stat().st_size==end-start+1
            return path
        except Exception:
            if attempt==2: raise
    raise RuntimeError('Download did not finish')

start_time=time.monotonic()
with ThreadPoolExecutor(max_workers=count) as pool:
    pending={pool.submit(fetch,index) for index in range(count)}
    while pending:
        done,pending=wait(pending,timeout=20,return_when=FIRST_COMPLETED)
        for future in done: future.result()
        total=sum(path.stat().st_size for path in parts.glob('*.part'))
        print(f'SDK downloaded {total}/{size} bytes in {time.monotonic()-start_time:.0f}s',flush=True)
archive=root/('commandline-tools-linux-x64-'+version+'.zip')
digest=hashlib.sha256()
with archive.open('wb') as output:
    for index in range(count):
        with (parts/f'{index:02}.part').open('rb') as source:
            while chunk:=source.read(1024*1024):
                digest.update(chunk)
                output.write(chunk)
assert digest.hexdigest()==expected_sha256, 'Packaging archive checksum mismatch'
staging=root/('harmonyos-clt-'+version+'.installing')
staging.mkdir(exist_ok=True)
with zipfile.ZipFile(archive) as package:
    for name in package.namelist():
        assert not Path(name).is_absolute() and '..' not in Path(name).parts
print('Extracting verified-size SDK archive',flush=True)
subprocess.run(['unzip','-oq',str(archive),'-d',str(staging)],check=True)
clt=staging/'command-line-tools'
meta=json.loads((clt/'sdk/default/sdk-pkg.json').read_text())
api_version=int(meta['data']['apiVersion'])
assert api_version>=23
assert 'autoCreateEmptyFile' in (clt/'sdk/default/openharmony/ets/api/@ohos.file.picker.d.ts').read_text()
node=clt/'tool/node/bin/node'
with node.open('rb') as stream: assert stream.read(4)==b'\x7fELF'
subprocess.run([str(node),'--version'],check=True)
staging.rename(target)
receipt={'version':version,'api':api_version,'url':url,'sha256':digest.hexdigest(),'bytes':size,'path':str(target/'command-line-tools')}
(root/'packaging-clt-receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
subprocess.run(['sync','-f',str(root)],check=True)
print(json.dumps(receipt),flush=True)
