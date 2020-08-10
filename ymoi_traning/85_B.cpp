#include<cstdio>

typedef long long ll;

int MOD;

ll ksm(ll a,ll k){
    ll ans=1;
    for(;k;a=(a*a)%MOD,k>>=1){
        if(k&1)ans=(ans*a)%MOD;
    }
    return ans;
}

void exgcd(int a,int b,int& x,int& y){
    if(b==0){
        x=1;y=0;
    }else{
        int _x,_y;
        exgcd(b,a%b,_x,_y);
        x=_y;y=_x-(a/b)*_y;
    }
}

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

void task1(int y,int z,int p){
    MOD = p;
    printf("%lld\n",ksm(y,z));
}

void task2(int y,int z,int p){
    int ccp = gcd(y,p);
    if(z%ccp){
        printf("Orz, I cannot find x!\n");
        return;
    }
    int x,trash;
    exgcd(y,p,x,trash);
    printf("%d\n",x*(z/ccp));
}

void task3(int y,int z,int p){
    printf("19260817\n");
}

int main(){
    int cas,k;
    scanf("%d%d",&cas,&k);
    while(cas--){
        int y,z,p;scanf("%d%d%d",&y,&z,&p);
        if(k==1){
            task1(y,z,p);
        }else if(k==2){
            task2(y,z,p);
        }else{
            task3(y,z,p);
        }
    }
    return 0;
}

