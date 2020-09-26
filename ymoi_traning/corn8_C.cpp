#include<cstdio>
#include<cstdlib>
#include<set>
#include<algorithm>
#include<map>
using std::map;
using std::lower_bound;
using std::sort;
typedef std::multiset<int,std::greater<int> > Set;
Set s;
const int MAXN=300005;
char type[4];
char op[4];
int _rev(int x,int& ans){
    if(!x)return 0;
    ans*=10;
    ans+=x%10;
    _rev(x/10,ans);
}
int rev(int x){
    int ans=0;
    _rev(x,ans);
    return ans;
}
namespace BIT{
    int a[MAXN];
    void update(int i,int val){
        for(;i<=MAXN-3;i+=(i&-i)){
            a[i]+=val;
        }
    }
    int query(int i){
        int ans=0;
        for(;i;i-=(i&-i)){
            ans+=a[i];
        }
        return ans;
    }
}
map<int,int> mp;
int _tot=0;
inline int h(int i){
    return mp[i]?mp[i]:mp[i]=++_tot;
}
#define OJ
int main(){
    #ifdef OJ
    freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);
    #endif
    int n;scanf("%d%s",&n,type);
    if(n<=20000){
        for(int i=1;i<=n;i++){
            scanf("%s",op);
            if(op[0]=='I'){
                int k;scanf("%d",&k);
                s.insert(k);
            }else if(op[0]=='D'){
                int k;scanf("%d",&k);
                s.erase(s.find(k));
            }else if(op[0]=='R'){
                int k;scanf("%d",&k);
                Set::iterator p=s.find(k);
                int i=1;
                while(p!=s.begin()){
                    p--;
                    i++;
                }
                printf("%d\n",i);
            }else if(op[0]=='K'){
                int k;scanf("%d",&k);
                Set::iterator p=s.begin();
                for(int i=1;i<k;i++){
                    p++;
                }
                printf("%d\n",*p);
            }else if(op[0]=='E'){
                Set tmp;
                for(Set::iterator p=s.begin();p!=s.end();p++){
                    int _=rev(*p);
                    tmp.insert(_);
                    // printf("test: %d\n",_);
                }
                s=tmp;
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            scanf("%s",op);
            if(op[0]=='I'){
                int k;scanf("%d",&k);
                BIT::update(k,1);
            }else if(op[0]=='D'){
                int k;scanf("%d",&k);k=h(k);
                BIT::update(k,-1);
            }else if(op[0]=='R'){
                int k;scanf("%d",&k);k=h(k);
                printf("%d\n",BIT::query(k));
            }
        }
    }
    return 0;
}