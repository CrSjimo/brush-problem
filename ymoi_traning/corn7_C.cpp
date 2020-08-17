#include<cstdio>
/* 30pts */
const int MAXN = 500010;
typedef long long ll;
// bool np[MAXN];
// int prime[MAXN];
// int tot=0;
// ll ans[MAXN][MAXN];
ll MOD;

ll phi[MAXN];

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
ll ksm(ll a,ll b){
    ll ans = 1;
    for(;b;a=(a*a)%MOD,b>>=1){
        if(b&1)ans=(ans*a)%MOD;
    }
    return ans;
}

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    int cas;scanf("%d%lld",&cas,&MOD);
    euler_sieve(MAXN-5);
    ll phimod = MOD-1;//TODO before 100pts fix this
    for(int i=1;i<=MAXN-5;i++){
        phi[i]=((phi[i]%phimod)+(phi[i-1]%phimod))%phimod;
    }
    while(cas--){
        int n;scanf("%d",&n);
        ll ans = 1;
        for(int d=1;d<=n;d++){
            // printf("test:%d %lld %lld\n",d,2*phi[n/d]-1,ksm(d,2*phi[n/d]-1));
            ans=(ans*ksm(d,2*phi[n/d]-1))%MOD;
        }
        printf("%lld\n",ans);
        
    }
    return 0;
}