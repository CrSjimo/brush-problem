#include<cstdio>

typedef long long ll;

const int MAXN = 1e6+10;

bool np[MAXN];
int prime[MAXN];
int tot=0;
ll p1[MAXN];
ll d1[MAXN];

void euler_sieve(int x){
    for(int i=2;i<=x;i++){
        if(!np[i]){
            prime[++tot]=i;
            p1[i]=1LL*i*i;
            d1[i]=i+1;
        }
        for(int j=1;j<=tot&&i*prime[j]<=x;j++){
            int p=prime[j];
            np[i*p]=true;
            if(i%p==0){
                p1[i*p]=p1[i]*p;
                d1[i*p]=d1[i]*(p1[i*p]-1)/(p1[i]-1);
                break;
            }
            p1[i*p]=1LL*p*p;
            d1[i*p]=d1[i]*d1[p];
        }
    }
}
int main(){
    euler_sieve(MAXN);
    d1[1]=1;
    for(int i=1;i<=MAXN-5;i++){
        d1[i]+=d1[i-1];
    }
    int cas;scanf("%d",&cas);
    while(cas--){
        int n;scanf("%d",&n);
        printf("%lld\n",d1[n]);
    }
    return 0;
}