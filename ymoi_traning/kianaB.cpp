#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using std::max;
const int MAXN = 3e5+10;
int dp[MAXN];
int maxp[MAXN];
int* a;
int n,m;
inline int h(int i,int c){
    return ((i-1+c-n)%n+n)%n+1;
}
int main(){
    freopen("garland.in","r",stdin);
    freopen("garland.out","w",stdout);
    scanf("%d%d",&n,&m);
    a=(int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    int ans=-19260817;
    for(int c=n;c<=2*n-1;c++){
        int maxn=-19260817;
        for(int i=1;i<=m;i++){
            maxn=-19260817;
            for(int j=i+1;j<=n;j++){
                dp[j]=max(dp[j-1]+a[h(j,c)],maxp[j-1]+a[h(j,c)]);
                maxp[j-1]=maxn;
                maxn=max(maxn,dp[j]);
            }
        }
        ans=max(ans,maxn);
        memset(dp,0,sizeof(dp));
        memset(maxp,0,sizeof(maxp));
    }
    printf("%d\n",ans);
    return 0;
}