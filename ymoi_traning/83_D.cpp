#include<cstdio>
typedef long long ll;
ll MOD;

ll ksm(ll a,ll b){
    ll ans = 1;
    for(;b;a=(a*a)%MOD,b>>=1){
        if(b&1)ans=(ans*a)%MOD;
    }
    return ans;
}

int main(){
    ll a,b;
    scanf("%lld%lld%lld",&a,&b,&MOD);
    printf("%lld\n",ksm(a,b));
    return 0;
}