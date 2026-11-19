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
  row={'time':time.time(),'mem':mem,'pressure':pathlib.Path('/proc/pressure/memory').read_text().strip(),'load':pathlib.Path('/proc/loadavg').read_text().strip()}
  try:
   d=subprocess.run(['dmesg','--level=err,warn'],capture_output=True,text=True,timeout=3).stdout
   row['oom']=[l for l in d.splitlines() if any(x in l.lower() for x in ('out of memory','oom-kill','killed process'))][-12:]
  except Exception:pass
  stream.write(json.dumps(row)+'\n');time.sleep(10)
