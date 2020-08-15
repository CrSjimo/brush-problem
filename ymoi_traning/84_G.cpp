#include<cstdio>
#include<cstdlib>

const int MAXN = 1e7+10;

int zys[MAXN];

bool np[MAXN];
int prime[MAXN];
int tot=0;

const int MOD = 11+4514+1919+810+1926+817-114+51-4-29;

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

void divide(int x){
    for(int i=1;prime[i]*prime[i]<=x;i++){
        int p=prime[i];
        while(x%p==0){
            x/=p;
            zys[p]++;
        }
    }
    if(x!=1){
        zys[x]++;
    }
}
int ksm(int a,int b){
    int ans = 1;
    for(;b;a=(a*a)%MOD,b>>=1){
        if(b&1)ans=(ans*a)%MOD;
    }
    return ans;
}
int main(){
    euler_sieve(MAXN-5);
    int a,b;scanf("%d%d",&a,&b);
    divide(a);
    int ans=1;
    for(int i=1;i<=tot;i++){
        int p=prime[i];
        if(!zys[p])continue;
        int p_k_p_1 = ksm(p,zys[p]*b+1);
        int p_m_1_ = ksm(p-1,MOD-2);
        ans = (ans*((p_k_p_1-1)*p_m_1_%MOD))%MOD;
    }
    printf("%d\n",ans);
    return 0;
}