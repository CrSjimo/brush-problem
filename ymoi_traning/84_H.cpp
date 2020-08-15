#include<cstdio>
typedef long long ll;
const int MAXN=114514;
ll f[MAXN];
bool np[MAXN];
int prime[MAXN];
int tot=0;

void euler_sieve(int x){
    f[1]=1;
    for(int i=2;i<=x;i++){
        if(!np[i]){
            prime[++tot]=i;
            f[i]=f[i-1];
        }
        for(int j=1;j<=tot&&i*prime[j]<=x;j++){
            int p=prime[j];
            np[i*p]=1;
            f[i*p]=f[i]+f[p];
            if(i%p==0){
                break;
            }
        }
    }
}
int main(){
    euler_sieve(MAXN-5);
    int cas;scanf("%d",&cas);
    while(cas--){
        int n;scanf("%d",&n);
        ll ans=0;
        int flag=1;
        for(int i=1;i<=n;i++){
            int p,k;scanf("%d%d",&p,&k);
            flag&=(p&1);
            ans+=f[p]*k;
        }
        printf("%lld\n",ans+flag);
    }
    return 0;
}