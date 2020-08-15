#include<cstdio>
#include<cstdlib>
const int MAXN = 1e7+10;

bool np[MAXN];
int prime[MAXN];
int tot=0;

int MOD;

void euler_sieve(int x){
    for(int i=2;i<=x;i++){
        if(!np[i]){
            prime[++tot]=i;
        }
        for(int j=1;j<=tot&&i*prime[j]<=x;j++){
            int p=prime[j];
            np[i*p]=true;
            if(i%p==0){
                break;
            }
        }
    }
}
typedef long long ll;
int ksm(ll a,int b){
    ll ans = 1;
    for(;b;a=(a*a)%MOD,b>>=1){
        if(b&1)ans=(ans*a)%MOD;
    }
    return (int)ans;
}

int pt[MAXN];
int pm1t[MAXN];
int fact[MAXN];

int main(){
    euler_sieve(MAXN-5);
    int cas;scanf("%d%d",&cas,&MOD);
    pt[1]=pm1t[1]=fact[1]=1;;
    for(int i=2,j=0;i<=MAXN-5;i++){
        fact[i]=(1LL*fact[i-1]*i)%MOD;
        if(i==prime[j+1]){
            j++;
            pt[i]=(1LL*pt[i-1]*prime[j])%MOD;
            pm1t[i]=(1LL*pm1t[i-1]*(prime[j]-1))%MOD;
        }else{
            pt[i]=pt[i-1];
            pm1t[i]=pm1t[i-1];
        }
    }
    // for(int i=1;i<=20;i++){
    //     printf("%d-test: %d %d %d\n",i,pt[i],pm1t[i],fact[i]);
    // }
    while(cas--){
        int N,M;scanf("%d%d",&N,&M);
        int N_fac = fact[N];
        int Pi_p_ = ksm(pt[M],MOD-2);
        int Pi_pm1 = pm1t[M];
        int ans = (((1LL*N_fac*Pi_p_)%MOD)*Pi_pm1)%MOD;
        printf("%d\n",ans);
    }
    return 0;
}