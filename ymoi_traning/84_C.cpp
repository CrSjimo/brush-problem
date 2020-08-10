#include<cstdio>

typedef long long ll;

const int MAXN = 19260817+1919810;

bool np[MAXN];
int prime[MAXN];
int tot=0;
ll p0[MAXN];
ll p1[MAXN];
ll d0[MAXN];
ll d1[MAXN];

void euler_sieve(int x){
    for(int i=2;i<=x;i++){
        if(!np[i]){
            prime[++tot]=i;
            p0[i]=1;
            p1[i]=1LL*i*i;
            d0[i]=2;
            d1[i]=i+1;
        }
        for(int j=1;j<=tot&&i*prime[j]<=x;j++){
            int p=prime[j];
            np[i*p]=true;
            if(i%p==0){
                p0[i*p]=p0[i]+1;
                d0[i*p]=d0[i]*(p0[i*p]+1)/(p0[i]+1);
                p1[i*p]=p1[i]*p;
                d1[i*p]=d1[i]*(p1[i*p]-1)/(p1[i]-1);
                break;
            }
            p0[i*p]=1;
            p1[i*p]=1LL*p*p;
            d0[i*p]=d0[i]*d0[p];
            d1[i*p]=d1[i]*d1[p];
        }
    }
}
int main(){
    euler_sieve(MAXN);
    int cas;scanf("%d",&cas);
    while(cas--){
        int op,n;scanf("%d%d",&op,&n);
        printf("%lld\n",op?d1[n]:d0[n]);
    }
    return 0;
}