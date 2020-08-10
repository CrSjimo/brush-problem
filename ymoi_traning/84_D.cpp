#include<cstdio>

typedef long long ll;

const int MAXN = 19260817+1919810;

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

int main(){
    euler_sieve(MAXN-5);
    for(int i=1;i<=MAXN-5;i++){
        phi[i]+=phi[i-1];
    }
    int n;scanf("%d",&n);
    ll ans = 0;
    for(int d=1;d<=n;d++){
        ans+=d*phi[n/d];
    }
    printf("%lld\n",ans*2-1LL*n*(n+1)/2);
    return 0;
}