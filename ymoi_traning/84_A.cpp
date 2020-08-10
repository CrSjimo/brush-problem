#include<cstdio>

const int MAXN = 114514;

bool np[MAXN];
int prime[MAXN];
int tot=0;

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

bool num[100010];

int main(){
    euler_sieve(MAXN-5);
    int l,r;
    scanf("%d%d",&l,&r);
    for(int i=1;i<=tot;i++){
        int p=prime[i];
        int t=(l/p)*p;
        if(t<l)t+=p;
        if(t==p)t+=p;
        for(int j=t;j<=r;j+=p){
            num[j-l]=1;
        }
    }
    int ans=0;
    if(l==1)num[0]=1;
    for(int i=l;i<=r;i++){
        ans+=(!num[i-l]);
    }
    printf("%d\n",ans);
    return 0;
}