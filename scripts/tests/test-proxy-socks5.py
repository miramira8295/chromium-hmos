#!/usr/bin/env python3
"""Run the actual patched SOCKS5 handshake methods against fragmented fake I/O.
The fixture is unmodified Chromium 157.0.8103.77 at 7d4508cbfffd289d7015f7703bce215d3ab123bf.
No network or HarmonyOS device is required; production methods are extracted only
AFTER applying the real migration diff. This tests wire bytes and state changes,
not a second Python implementation of the protocol.
"""
from pathlib import Path
import hashlib
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[2]
PATCH = ROOT / 'patches/migration-157/chromium.patch'
FIXTURE = Path(__file__).with_name('fixtures') / 'socks5_client_socket-157.cc'

def method(source, name):
    start = source.index('int SOCKS5ClientSocket::' + name + '(')
    end = source.index('\n}\n', start) + 3
    return source[start:end]

PREFIX = r'''
#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <memory>
#include <span>
#include <string>
#include <utility>
#include <vector>
#define DCHECK_EQ(a,b) assert((a)==(b))
namespace base {
template<class T> using span=std::span<T>;
template<class T, class... A> auto MakeRefCounted(A&&... a) {return std::make_shared<T>(std::forward<A>(a)...);}
}
constexpr int OK=0, ERR_CONNECTION_CLOSED=-100, ERR_SOCKS_CONNECTION_FAILED=-120,
              ERR_INVALID_AUTH_CREDENTIALS=-338;
struct VectorIOBuffer {std::vector<uint8_t> bytes;explicit VectorIOBuffer(std::vector<uint8_t> b):bytes(std::move(b)){} int size(){return bytes.size();}};
struct WrappedIOBuffer:VectorIOBuffer {template<size_t N> explicit WrappedIOBuffer(const std::array<uint8_t,N>& a):VectorIOBuffer({a.begin(),a.end()}){}};
struct DrainableIOBuffer {std::shared_ptr<VectorIOBuffer> b;int used=0;DrainableIOBuffer(std::shared_ptr<VectorIOBuffer> v,int):b(v){} int BytesRemaining(){return b->size()-used;}void DidConsume(int n){used+=n;}};
struct GrowableIOBuffer {std::vector<uint8_t> b;int pos=0;void SetCapacity(int n){b.resize(n);} int RemainingCapacity(){return b.size()-pos;}int offset(){return pos;}void set_offset(int n){pos=n;}auto span_before_offset(){return std::span<uint8_t>(b).first(pos);}};
enum class NetLogEventType {SOCKS_HOSTNAME_TOO_BIG,SOCKS_UNEXPECTEDLY_CLOSED_DURING_GREETING,SOCKS_UNEXPECTED_VERSION,SOCKS_UNEXPECTED_AUTH};
struct Log {template<class...T> void AddEvent(T...){}template<class...T>void AddEventWithIntParams(T...){}};
struct Destination {std::string host(){return "destination.example";}};
struct Socket {std::vector<uint8_t> sent;int limit=1;int Write(DrainableIOBuffer* b,int count,int,int){int n=std::min(count,limit);sent.insert(sent.end(),b->b->bytes.begin()+b->used,b->b->bytes.begin()+b->used+n);return n;}int Read(GrowableIOBuffer*,int,int){return -1;}};
class SOCKS5ClientSocket {public:
enum State {STATE_NONE,STATE_GREET_WRITE,STATE_GREET_WRITE_COMPLETE,STATE_GREET_READ,STATE_GREET_READ_COMPLETE,STATE_AUTH_WRITE,STATE_AUTH_WRITE_COMPLETE,STATE_AUTH_READ,STATE_AUTH_READ_COMPLETE,STATE_HANDSHAKE_WRITE};
static constexpr uint8_t kSOCKS5Version=5;
State next_state_=STATE_NONE;bool auth_required_=true;std::string auth_username_,auth_password_;
std::shared_ptr<DrainableIOBuffer> write_buf_;std::shared_ptr<GrowableIOBuffer> read_buf_;
std::unique_ptr<Socket> transport_socket_=std::make_unique<Socket>();Log net_log_;Destination destination_;int io_callback_=0,traffic_annotation_=0;
int DoGreetWrite();int DoGreetWriteComplete(int);int DoGreetReadComplete(int);
int DoAuthWrite();int DoAuthWriteComplete(int);int DoAuthRead();int DoAuthReadComplete(int);
void reply(uint8_t a,uint8_t b){read_buf_=std::make_shared<GrowableIOBuffer>();read_buf_->SetCapacity(2);read_buf_->b={a,b};}
};
static constexpr std::array<uint8_t,3> kSOCKS5GreetWriteData{5,1,0};
'''
MAIN = r'''
int main(){
  SOCKS5ClientSocket s;s.auth_username_="user";s.auth_password_="pass";
  // Every greeting write completes only one byte at a time.
  do {assert(s.DoGreetWriteComplete(s.DoGreetWrite())==OK);}while(s.next_state_==s.STATE_GREET_WRITE);
  assert((s.transport_socket_->sent==std::vector<uint8_t>{5,1,2}));
  s.reply(5,2);assert(s.DoGreetReadComplete(1)==OK);assert(s.next_state_==s.STATE_GREET_READ);
  assert(s.DoGreetReadComplete(1)==OK);assert(s.next_state_==s.STATE_AUTH_WRITE);
  do {assert(s.DoAuthWriteComplete(s.DoAuthWrite())==OK);}while(s.next_state_==s.STATE_AUTH_WRITE);
  assert((s.transport_socket_->sent==std::vector<uint8_t>{5,1,2,1,4,'u','s','e','r',4,'p','a','s','s'}));
  assert(s.auth_username_.empty()&&s.auth_password_.empty());
  s.reply(1,0);assert(s.DoAuthReadComplete(1)==OK);assert(s.next_state_==s.STATE_AUTH_READ);
  assert(s.DoAuthReadComplete(1)==OK);assert(s.next_state_==s.STATE_HANDSHAKE_WRITE);
  // Auth downgrade and unsupported method are always rejected.
  for(uint8_t method:{0,1,255}) {SOCKS5ClientSocket x;x.reply(5,method);assert(x.DoGreetReadComplete(2)==ERR_SOCKS_CONNECTION_FAILED);}
  SOCKS5ClientSocket noauth;noauth.auth_required_=false;noauth.reply(5,0);assert(noauth.DoGreetReadComplete(2)==OK);assert(noauth.next_state_==noauth.STATE_HANDSHAKE_WRITE);
  noauth.reply(5,2);assert(noauth.DoGreetReadComplete(2)==ERR_SOCKS_CONNECTION_FAILED);
  // Rejected password, wrong subnegotiation version, EOF and transport errors.
  s.reply(1,1);assert(s.DoAuthReadComplete(2)==ERR_INVALID_AUTH_CREDENTIALS);
  s.reply(5,0);assert(s.DoAuthReadComplete(2)==ERR_INVALID_AUTH_CREDENTIALS);
  s.reply(1,0);assert(s.DoAuthReadComplete(0)==ERR_CONNECTION_CLOSED);
  assert(s.DoAuthReadComplete(-77)==-77);assert(s.DoAuthWriteComplete(-77)==-77);
  assert(s.DoAuthWriteComplete(0)==ERR_CONNECTION_CLOSED);
  // RFC1929 limits count UTF-8 bytes rather than Unicode characters.
  for(int size:{0,256}) {SOCKS5ClientSocket x;x.auth_username_=std::string(size,'x');x.auth_password_="p";assert(x.DoGreetWrite()==ERR_INVALID_AUTH_CREDENTIALS);}
  SOCKS5ClientSocket edge;edge.auth_username_=std::string(255,'x');edge.auth_password_="\xc3\xa9";edge.transport_socket_->limit=1000;
  assert(edge.DoAuthWriteComplete(edge.DoAuthWrite())==OK);
  assert(edge.transport_socket_->sent[1]==255);assert(edge.transport_socket_->sent[257]==2);
  assert(edge.transport_socket_->sent[258]==0xc3&&edge.transport_socket_->sent[259]==0xa9);
}
'''

def main():
    assert hashlib.sha256(FIXTURE.read_bytes()).hexdigest() == '1c9cce1820cedd40675aae9097bcbd832f7bd18984c7e5abc6ba5a4b07a00f14'
    sections = ['diff --git '+s for s in PATCH.read_text().split('diff --git ')[1:]]
    patch = next(s for s in sections if s.startswith('diff --git a/net/socket/socks5_client_socket.cc '))
    with tempfile.TemporaryDirectory(prefix='proxy-socks-test-') as folder:
        root=Path(folder);p=root/'net/socket/socks5_client_socket.cc';p.parent.mkdir(parents=True);p.write_bytes(FIXTURE.read_bytes())
        subprocess.run(['git','init','-q'],cwd=root,check=True)
        subprocess.run(['git','apply','--whitespace=nowarn','-'],cwd=root,input=patch,text=True,check=True)
        source=p.read_text()
        names=['DoGreetWrite','DoGreetWriteComplete','DoGreetReadComplete','DoAuthWrite','DoAuthWriteComplete','DoAuthRead','DoAuthReadComplete']
        unit=root/'test.cc';unit.write_text(PREFIX+'\n'.join(method(source,n) for n in names)+MAIN)
        subprocess.run(['c++','-std=c++20','-Wall','-Wextra','-Werror',str(unit),'-o',str(root/'test')],check=True)
        subprocess.run([str(root/'test')],check=True)
    print('SOCKS5: fragmented I/O, RFC1929 framing, byte limits, rejection, EOF and downgrade tests passed')
if __name__=='__main__':main()
