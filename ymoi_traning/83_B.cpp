#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::lower_bound;

typedef long long ll;

const int MAXN = 20000010;

ll phi[MAXN];

bool not_prime[MAXN];
int prime[MAXN];
int pi[MAXN];
int tot = 0;

void linearSievePrime(int x){
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

int MAGIC_NUMBERS[3]={19260817,114514,1919810};

int main(){
    linearSievePrime(MAXN);
    for(int i=2;i<=MAXN;i++){
        pi[i]=pi[i-1]+=(!not_prime[i]);
        phi[i]+=phi[i-1];
    }
    int n;scanf("%d",&n);
    while(n--){
        int k;scanf("%d",&k);
        printf("%d %lld %d\n",pi[k],phi[k],MAGIC_NUMBERS[k%3]);
    }
    return 0;
}
