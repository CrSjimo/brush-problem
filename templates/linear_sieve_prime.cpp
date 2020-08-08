#include<cstdio>
#include<cstdlib>

bool* not_prime;
int* prime;
int tot = 0;

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

}