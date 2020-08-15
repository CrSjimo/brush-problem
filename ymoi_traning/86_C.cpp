#include<cstdio>
#include<set>
using std::multiset;
typedef long long ll;

const int MAXN = 114514;

ll a[MAXN],p[MAXN],b[MAXN],aa[MAXN];
int n,m;

ll exgcd(ll a,ll b,ll& x,ll& y){
    if(b==0){
        x=1,y=0;
        return a;
    }else{
        ll _x,_y;
        ll ccp=exgcd(b,a%b,_x,_y);
        x=_y,y=_x-(a/b)*_y;
        return ccp;
    }
}

inline ll vnmod(ll x,ll mod){
    return (x%mod+mod)%mod;
}

ll exCRT(){
    ll ans=aa[1],M=p[1];
    for(int i=2;i<=n;i++){
        ll c=vnmod(aa[i]-ans,p[i]);
        ll x,y;
        int ccp=exgcd(M,p[i],x,y);
        if(c%ccp)return -1;
        ll t=p[i]/ccp;
        x=x*c/ccp%t;
        ans+=M*x;
        M*=t;
        ans=vnmod(ans,M);
    }
    return ans;
}

int main(){
    freopen("dragon.in","r",stdin);
    freopen("dragon.out","w",stdout);
    int cas;scanf("%d",&cas);
    while(cas--){
        multiset<ll> ms;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%lld",a+i);
        }
        for(int i=1;i<=n;i++){
            scanf("%lld",p+i);
        }
        for(int i=1;i<=n;i++){
            scanf("%lld",b+i);
        }
        for(int i=1;i<=m;i++){
            ll k;scanf("%lld",&k);
            ms.insert(k);
        }
        for(int i=1;i<=n;i++){
            multiset<ll>::iterator it = ms.upper_bound(a[i]);
            if(it!=ms.begin())it--;
            ms.insert(b[i]);
            b[i]=(*it);
            ms.erase(it);
        }
        for(int i=1;i<=n;i++){
            ll x,y;
            ll ccp=exgcd(b[i],p[i],x,y);
            if(a[i]%ccp){
                printf("-1\n");
                goto next;
            }
            ll mod = p[i]/=ccp;
            aa[i]=((x%mod)*(a[i]/ccp)%mod)%mod;
        }
        printf("%lld\n",exCRT());
        next:;
    }
}