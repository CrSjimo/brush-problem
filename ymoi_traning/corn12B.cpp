#include<cstdio>
#include<cstdlib>
typedef long long ll;
const int MOD = 998244353;
ll ksm(ll a,int b){
    ll ans = 1;
    for(;b;(a*=a)%=MOD,b>>=1){
        if(b&1)(ans*=a)%=MOD;
    }
    return ans;
}
int* fac;
int n;
inline void FactoRial_dabiao(){
    fac=(int*)malloc((n+1)*sizeof(int));
    fac[0]=1;
    for(int i=1;i<=n;i++){
        fac[i]=(1ll*fac[i-1]*i)%MOD;
    }
}
inline ll A(int n,int r){
    return (1ll*fac[n]*ksm(fac[n-r],MOD-2))%MOD;
}
int main(){
    freopen("dream.in","r",stdin);
    freopen("dream.out","w",stdout);
    int m;
    scanf("%d%d",&n,&m);
    FactoRial_dabiao();
    for(int i=0;i<=n;i++){
        int k;scanf("%d",&k);
        if(i>=m){
            printf("%lld ",(k*A(i,m))%MOD);
        }
    }
    printf("\n");
    return 0;
}