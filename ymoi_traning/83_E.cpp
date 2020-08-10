#include<cstdio>
typedef long long ll;
ll MOD;
inline ll ksm(ll a,ll k){
    int ans=1;
    for(;k;a=(a*a)%MOD,k>>=1){
        if(k&1)ans=(ans*a)%MOD;
    }
    return ans;
}
int main(){
    ll n,m,k,x;
    scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
    MOD=n;
    printf("%lld\n",(x+ksm(10,k)*m)%n);
    return 0;
}
