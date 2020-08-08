#include<cstdio>
#include<cstdlib>
#include<cmath>

bool* not_prime;
int* prime;
int tot = 0;

bool isHuiwen(int x){
    int t=0,tmp=x;
    while(x){
        t*=10;
        t+=(x%10);
        x/=10;
    }
    return t==tmp;
}

void linearSievePrime(int x){
    for(int i=2;i<=x;i++){
        if(!not_prime[i])prime[++tot]=i;
        for(int j=1;j<=tot&&i*prime[j]<=x;j++){
            not_prime[i*prime[j]]=true;
            if(i%prime[j]==0)break;
        }
    }
}

int main(){
    int l,r;scanf("%d%d",&l,&r);
    prime=(int*)calloc(r*2/log(r),sizeof(int));
    not_prime=(bool*)calloc(r+10,sizeof(bool));
    linearSievePrime(r+4);
    for(int i=1;prime[i]<=r;i++){
        if(prime[i]<l)continue;
        if(isHuiwen(prime[i])){
            printf("%d\n",prime[i]);
        }
    }
    return 0;
}