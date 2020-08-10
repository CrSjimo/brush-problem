#include<cstdio>
typedef long long ll;

ll ksm(ll a,ll b,ll MOD){
    ll ans = 1;
    for(;b;a=(a*a)%MOD,b>>=1){
        if(b&1)ans=(ans*a)%MOD;
    }
    return ans;
}
const int MAXN =11451400;

int phi[MAXN];

bool not_prime[MAXN];
int prime[MAXN];
int tot = 0;

void euler_sieve(int x){
    phi[1]=1;
    for(int i=2;i<=x;i++){
        if(!not_prime[i]){
            prime[++tot]=i;
            phi[i]=i-1;
        }
        for(int j=1;j<=tot&&i*prime[j]<=x;j++){
            not_prime[i*prime[j]]=true;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*(prime[j]);
                break;
            }
            phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
}
int f(int p){
    if(p==1)return 0;
    return ksm(2,phi[p]+f(phi[p]),p);
}
int main(){
    euler_sieve(MAXN);
    int cas;scanf("%d\n",&cas);
    while(cas--){
        int p;scanf("%d",&p);
        printf("%d\n",f(p));
    }
    return 0;
}