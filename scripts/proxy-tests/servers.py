#!/usr/bin/env python3
"""Controlled HTTP CONNECT / SOCKS5 proxies for on-device routing verification.
Bind a trusted interface explicitly. Logs endpoint, protocol and auth outcome only;
never log credentials, authorization headers, URL paths or tunneled application data.
Credentials, when requested, are disposable test values: lumie-test / test-password.
"""
import argparse, asyncio, base64, json, socket, ssl, time
from urllib.parse import urlsplit
USER=b'lumie-test'; PASSWORD=b'test-password'

def event(protocol, outcome, host='', port=0):
    print(json.dumps(dict(time=time.time(),protocol=protocol,outcome=outcome,host=host,port=port)),flush=True)

async def pipe(reader, writer):
    try:
        while data:=await reader.read(65536):
            writer.write(data);await writer.drain()
    except (ConnectionError, asyncio.CancelledError):pass
    finally:writer.close()

async def bridge(client_r,client_w,host,port,initial=b''):
    upstream_r,upstream_w=await asyncio.wait_for(asyncio.open_connection(host,port),10)
    if initial:upstream_w.write(initial);await upstream_w.drain()
    return upstream_r,upstream_w

async def http(reader,writer,auth=False,fragment=False):
    try:
        raw=await asyncio.wait_for(reader.readuntil(b'\r\n\r\n'),15)
        lines=raw.split(b'\r\n');method,target,version=lines[0].split(b' ',2)
        headers={}
        for line in lines[1:]:
            if b':' in line:
                k,v=line.split(b':',1);headers[k.lower()]=v.strip()
        if auth and headers.get(b'proxy-authorization')!=b'Basic '+base64.b64encode(USER+b':'+PASSWORD):
            writer.write(b'HTTP/1.1 407 Proxy Authentication Required\r\nProxy-Authenticate: Basic realm="LumieTest"\r\nContent-Length: 0\r\nConnection: close\r\n\r\n')
            await writer.drain();event('http','auth-required');return
        if method==b'CONNECT':
            url=urlsplit('//'+target.decode());host=url.hostname;port=url.port or 443
            upstream_r,upstream_w=await bridge(reader,writer,host,port)
            writer.write(b'HTTP/1.1 200 Connection established\r\n\r\n');await writer.drain()
        else:
            url=urlsplit(target.decode());host=url.hostname;port=url.port or 80
            if not host or url.scheme!='http':raise ValueError('absolute HTTP target required')
            path=(url.path or '/')+('?' +url.query if url.query else '')
            filtered=[line for line in lines[1:] if line and not line.lower().startswith((b'proxy-authorization:',b'proxy-connection:'))]
            request=method+b' '+path.encode()+b' '+version+b'\r\n'+b'\r\n'.join(filtered)+b'\r\n\r\n'
            upstream_r,upstream_w=await bridge(reader,writer,host,port,request)
        event('http','routed',host,port)
        await asyncio.gather(pipe(reader,upstream_w),pipe(upstream_r,writer))
    except Exception as e:event('http',type(e).__name__)
    finally:writer.close()

async def send(writer,data,fragment):
    for chunk in (bytes([b]) for b in data) if fragment else [data]:
        writer.write(chunk);await writer.drain()
        if fragment:await asyncio.sleep(.005)

async def socks(reader,writer,auth=False,fragment=False):
    try:
        version,count=await asyncio.wait_for(reader.readexactly(2),15)
        methods=await reader.readexactly(count);method=2 if auth else 0
        if version!=5 or method not in methods:
            await send(writer,b'\x05\xff',fragment);event('socks5','unsupported-method');return
        await send(writer,bytes([5,method]),fragment)
        if auth:
            version,size=await reader.readexactly(2);user=await reader.readexactly(size)
            size=(await reader.readexactly(1))[0];password=await reader.readexactly(size)
            valid=version==1 and user==USER and password==PASSWORD
            await send(writer,bytes([1,0 if valid else 1]),fragment)
            event('socks5','auth-accepted' if valid else 'auth-rejected')
            if not valid:return
        version,command,reserved,kind=await reader.readexactly(4)
        if kind==3:host=(await reader.readexactly((await reader.readexactly(1))[0])).decode()
        elif kind==1:host=socket.inet_ntop(socket.AF_INET,await reader.readexactly(4))
        elif kind==4:host=socket.inet_ntop(socket.AF_INET6,await reader.readexactly(16))
        else:raise ValueError('address type')
        port=int.from_bytes(await reader.readexactly(2),'big')
        if version!=5 or command!=1 or reserved!=0:raise ValueError('connect request')
        upstream_r,upstream_w=await bridge(reader,writer,host,port)
        await send(writer,b'\x05\x00\x00\x01\x7f\x00\x00\x01\x00\x00',fragment)
        event('socks5','domain-routed' if kind==3 else 'ip-routed',host,port)
        await asyncio.gather(pipe(reader,upstream_w),pipe(upstream_r,writer))
    except Exception as e:event('socks5',type(e).__name__)
    finally:writer.close()

async def main(args):
    ctx=None
    if args.cert:
        ctx=ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER);ctx.load_cert_chain(args.cert,args.key)
    handler=socks if args.protocol=='socks5' else http
    server=await asyncio.start_server(lambda r,w:handler(r,w,args.auth,args.fragment),args.bind,args.port,ssl=ctx)
    event(args.protocol,'listening',args.bind,args.port)
    async with server:await server.serve_forever()
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--protocol',choices=['http','socks5'],required=True)
    p.add_argument('--bind',default='127.0.0.1');p.add_argument('--port',type=int,required=True)
    p.add_argument('--auth',action='store_true');p.add_argument('--fragment',action='store_true')
    p.add_argument('--cert');p.add_argument('--key');args=p.parse_args()
    if bool(args.cert)!=bool(args.key):p.error('--cert and --key must be supplied together')
    asyncio.run(main(args))
