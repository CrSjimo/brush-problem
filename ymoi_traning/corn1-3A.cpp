#include<cstdio>
const int MOD = 20011021;
typedef long long ll;
ll ksm(ll a,ll b){
    ll ans = 1;
    for(;b;(a*=a)%=MOD,b>>=1)if(b&1)(ans*=a)%=MOD;
    return ans;
}
int main(){
    freopen("corn.in","r",stdin);
    freopen("corn.out","w",stdout);
    ll n,k;scanf("%lld%lld",&n,&k);
    if(n==1)printf("%lld\n",k);
    else printf("%lld\n",(ksm(k-1,n)+(((n&1)?-1:1)*(k-1))%MOD)%MOD);
    return 0;
}