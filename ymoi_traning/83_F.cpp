#include<cstdio>

typedef long long ll;

const int MAXN = 40005;

int phi[MAXN];

bool not_prime[MAXN];
int prime[MAXN];
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
int main(){
    linearSievePrime(MAXN);
    for(int i=2;i<=MAXN;i++){
        phi[i]+=phi[i-1];
    }
    int n;scanf("%d",&n);
    printf("%d\n",phi[n-1]*2+1);
    return 0;
}