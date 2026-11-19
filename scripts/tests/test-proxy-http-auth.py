#!/usr/bin/env python3
"""Exercise the patched Chromium identity selector, with fake auth/cache I/O.
Pinned upstream fixtures are patched by the production migration diff first.
This verifies credential routing, not HTTP transport (covered on-device).
"""
from pathlib import Path
import subprocess
import tempfile
ROOT = Path(__file__).resolve().parents[2]
FIXTURES = Path(__file__).with_name('fixtures')
PREFIX = r'''
#include <cassert>
#include <cstdint>
#include <memory>
#include <string>
#define DCHECK(x) assert(x)
#define DCHECK_CALLED_ON_VALID_THREAD(x) ((void)0)
struct AuthCredentials { std::u16string user, password; void Set(std::u16string u,std::u16string p){user=u;password=p;} };
struct HttpAuth {enum Target {AUTH_SERVER,AUTH_PROXY};enum Source {IDENT_SRC_URL,IDENT_SRC_EXTERNAL,IDENT_SRC_REALM_LOOKUP,IDENT_SRC_DEFAULT_CREDENTIALS};};
struct Endpoint {std::string protocol="http",hostname="proxy.example";uint16_t number=8080;const std::string& scheme()const{return protocol;}const std::string& host()const{return hostname;}uint16_t port()const{return number;}};
struct Url {bool embedded=false;bool has_username(){return embedded;}};
void GetIdentityFromURL(Url,std::u16string* u,std::u16string* p){*u=u"website-user";*p=u"website-password";}
struct Handler {bool explicit_allowed=true,default_allowed=false;bool AllowsExplicitCredentials(){return explicit_allowed;}bool AllowsDefaultCredentials(){return default_allowed;}std::string realm(){return "realm";}int auth_scheme(){return 0;}};
class HttpAuthCache {public:
'''
CACHE_TAIL = r'''
struct Entry {AuthCredentials value;const AuthCredentials& credentials(){return value;}};
Entry* Lookup(const Endpoint&,HttpAuth::Target,const std::string&,int,int){return nullptr;}
private:
std::string shell_proxy_scheme_,shell_proxy_host_;uint16_t shell_proxy_port_=0;AuthCredentials shell_proxy_credentials_;
};
class HttpAuthController {public:
HttpAuth::Target target_=HttpAuth::AUTH_PROXY;Url auth_url_;bool embedded_identity_used_=false,shell_proxy_identity_used_=false,default_credentials_used_=false;
struct Identity {bool invalid=true;HttpAuth::Source source=HttpAuth::IDENT_SRC_URL;AuthCredentials credentials;} identity_;
Endpoint auth_scheme_host_port_;int network_anonymization_key_=0;
HttpAuthCache* http_auth_cache_;std::unique_ptr<Handler> handler_=std::make_unique<Handler>();
explicit HttpAuthController(HttpAuthCache* c):http_auth_cache_(c){}
bool SelectNextAuthIdentityToTry();
};
'''
MAIN = r'''
int main(){
  HttpAuthCache cache;AuthCredentials saved;saved.Set(u"proxy-user",u"proxy-password");
  cache.SetShellProxyCredentials("http","proxy.example",8080,saved);
  // A 407 at the exact endpoint receives the proxy identity once.
  HttpAuthController good(&cache);assert(good.SelectNextAuthIdentityToTry());
  assert(good.identity_.credentials.password==u"proxy-password");
  good.identity_.invalid=true;assert(!good.SelectNextAuthIdentityToTry());
  // A website 401 at even that exact same host:port receives no proxy secret.
  HttpAuthController origin(&cache);origin.target_=HttpAuth::AUTH_SERVER;
  assert(!origin.SelectNextAuthIdentityToTry());assert(origin.identity_.credentials.password.empty());
  origin.auth_url_.embedded=true;assert(origin.SelectNextAuthIdentityToTry());
  assert(origin.identity_.credentials.password==u"website-password");
  for(int field=0;field<3;++field){HttpAuthController wrong(&cache);
    if(field==0)wrong.auth_scheme_host_port_.protocol="https";
    if(field==1)wrong.auth_scheme_host_port_.hostname="other.example";
    if(field==2)wrong.auth_scheme_host_port_.number=8081;
    assert(!wrong.SelectNextAuthIdentityToTry());assert(wrong.identity_.credentials.password.empty());}
  HttpAuthController forbidden(&cache);forbidden.handler_->explicit_allowed=false;
  assert(!forbidden.SelectNextAuthIdentityToTry());
  HttpAuthCache isolated;HttpAuthController test_context(&isolated);
  assert(!test_context.SelectNextAuthIdentityToTry());
  cache.SetShellProxyCredentials("https","proxy.example",443,saved);
  HttpAuthController tls(&cache);tls.auth_scheme_host_port_.protocol="https";tls.auth_scheme_host_port_.number=443;
  assert(tls.SelectNextAuthIdentityToTry());
}
'''
def main():
    sections=['diff --git '+s for s in (ROOT/'patches/migration-157/chromium.patch').read_text().split('diff --git ')[1:]]
    with tempfile.TemporaryDirectory(prefix='proxy-http-auth-') as folder:
        root=Path(folder)
        subprocess.run(['git','init','-q'],cwd=root,check=True)
        for name in ['http_auth_controller.cc','http_auth_cache.h']:
            target='net/http/'+name;p=root/target;p.parent.mkdir(parents=True,exist_ok=True)
            p.write_bytes((FIXTURES/name.replace('.','-157.',1)).read_bytes())
            patch=next(s for s in sections if s.startswith('diff --git a/'+target+' '))
            subprocess.run(['git','apply','--whitespace=nowarn','-'],input=patch,text=True,cwd=root,check=True)
        cache=(root/'net/http/http_auth_cache.h').read_text()
        methods=cache[cache.index('  void SetShellProxyCredentials('):cache.index('  class NET_EXPORT Entry')]
        source=(root/'net/http/http_auth_controller.cc').read_text()
        start=source.index('bool HttpAuthController::SelectNextAuthIdentityToTry()')
        selector=source[start:source.index('\n}\n',start)+3]
        p=root/'test.cc';p.write_text(PREFIX+methods+CACHE_TAIL+selector+MAIN)
        subprocess.run(['c++','-std=c++20','-Wall','-Wextra','-Werror',str(p),'-o',str(root/'test')],check=True)
        subprocess.run([str(root/'test')],check=True)
    print('HTTP auth: 407 endpoint binding, 401 isolation, scheme/host/port mismatch, single attempt and context isolation passed')
if __name__=='__main__':main()
