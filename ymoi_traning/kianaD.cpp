#include<cstdio>
#include<cstdlib>
typedef long long ll;
ll* a;
int main(){
    freopen("running.in","r",stdin);
    freopen("running.out","w",stdout);
    int n,k;scanf("%d%d",&n,&k);
    a=(ll*)malloc((n+1)*sizeof(ll));
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    ll ans=0;
    if(k==1){
        for(int i=1;i<=n;i++){
            ans+=a[i]*(i-1);
            ans-=a[i]*(n-i);
        }
    }else{
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans+=(a[j]-a[i])/k;
                // printf("test: %d %d\n",j,i);
            }
            // printf("testt: %d\n",i);
        }
    }
    printf("%lld\n",ans);
    return 0;
}