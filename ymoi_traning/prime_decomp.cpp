#include<cstdio>
#include<cstdlib>

const int MAXN = 11451;
int prime[MAXN];
bool np[MAXN];
int tot=0;

void sieve(int x){
    for(int i=2;i<=x;i++){
        if(!np[x]){
            prime[++tot]=x;
        }else{
            for(int j=1;j<=tot&&i*prime[j]<=x;j++){
                int p=prime[j];
                np[i*p]=true;
                if(i%p==0)break;
            }
        }
    }
}

int pwr[MAXN];

void decomp(int x){
    for(int i=1;i<=tot&&prime[i]*prime[i]<=x;i++){
        int p=prime[i];
        while(x%p==0){
            pwr[p]++;
            x/=p;
        }
    }
    if(x>1)pwr[x]++;
}

int main(){
    sieve(MAXN-5);
    int n;scanf("%d",&n);
    for(int i=2;i<=n;i++){
        decomp(i);
    }
    for(int i=1;i<=tot&&prime[i]<=n;i++){
        int p=prime[i];
        if(pwr[p]){
            printf("%d %d\n",p,pwr[p]);
        }
    }
    return 0;
}