#include<cstdlib>
#include<cstdio>
#include<iostream>
using std::cin;
#include<string>
typedef std::string buffer;
#include<map>
using std::map;
int T=0;
map<buffer,int> mp;
map<int,buffer> _mp;
inline int hash(buffer buf){
    if(!mp.count(buf)){
        _mp[++T]=buf;
        return mp[buf]=T;
    }else{
        return mp[buf];
    }
}
inline buffer _hash(int x){
    return _mp[x];
}
namespace Bcj{ //stricted parent-child bond
    int* f;
    inline void init(int n){
        f=(int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;i++)f[i]=i;
    }
    int find(int x){
        return f[x]==x?x:f[x]=find(f[x]);
    }
    inline void update(int child,int parent){
        f[find(child)]=find(parent);
    }
}
int currentParent;
int main(){
    buffer buf;
    Bcj::init(50005);
    while(cin>>buf){
        char k=buf[0];buf=buf.substr(1);
        if(k=='$')return 0;
        if(k=='#'){
            currentParent=hash(buf);
        }else if(k=='+'){
            Bcj::update(hash(buf),currentParent);
        }else if(k=='?'){
            buffer anc = _hash(Bcj::find(hash(buf)));
            printf("%s %s\n",buf.c_str(),anc.c_str());
        }
    }
    return 0;
}/*
#George
+Rodney
#Arthur
+Gareth
+Walter
#Gareth
+Edward
?Edward
?Walter
?Rodney
?Arthur
$
*/
