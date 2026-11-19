#!/usr/bin/env python3
"""Record resource pressure and OOM evidence on the retained build disk.
No process command lines, environments, credentials or user data are sampled.
"""
import json, pathlib, time, subprocess, sys
out=pathlib.Path(sys.argv[1])
out.parent.mkdir(parents=True,exist_ok=True)
end=time.monotonic()+21600
with out.open('a',buffering=1) as stream:
 while time.monotonic()<end:
  mem={}
  for line in pathlib.Path('/proc/meminfo').read_text().splitlines():
   key,rest=line.split(':',1)
   if key in ('MemTotal','MemAvailable','SwapTotal','SwapFree','Dirty','Writeback'):mem[key]=rest.strip()
  compilers=[]
  for proc in pathlib.Path('/proc').iterdir():
   if not proc.name.isdigit():continue
   try:
    if (proc/'comm').read_text().strip()!='clang++':continue
    info={k:v.strip() for k,v in (l.split(':',1) for l in (proc/'status').read_text().splitlines() if ':' in l)}
    args=(proc/'cmdline').read_bytes().decode().split('\0')
    compilers.append({'pid':int(proc.name),'rss_kb':int(info.get('VmRSS','0 kB').split()[0]),
                      'swap_kb':int(info.get('VmSwap','0 kB').split()[0]),
                      'source':args[args.index('-c')+1] if '-c' in args else ''})
   except (OSError,ValueError,IndexError):pass
  row={'time':time.time(),'mem':mem,'pressure':pathlib.Path('/proc/pressure/memory').read_text().strip(),'load':pathlib.Path('/proc/loadavg').read_text().strip()}
  row['compiler_count']=len(compilers)
  row['compiler_rss_kb']=sum(c['rss_kb'] for c in compilers)
  row['compiler_swap_kb']=sum(c['swap_kb'] for c in compilers)
  row['largest_compilers']=sorted(compilers,key=lambda c:c['rss_kb']+c['swap_kb'],reverse=True)[:8]
  try:
   d=subprocess.run(['dmesg','--level=err,warn'],capture_output=True,text=True,timeout=3).stdout
   row['oom']=[l for l in d.splitlines() if any(x in l.lower() for x in ('out of memory','oom-kill','killed process'))][-12:]
  except Exception:pass
  stream.write(json.dumps(row)+'\n');time.sleep(10)
