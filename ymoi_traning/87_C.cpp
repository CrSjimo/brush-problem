#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
const int MAXN = 114514>>2;
int dp[MAXN];
int a[MAXN];
int main(){
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    int cas;scanf("%d",&cas);
    while(cas--){
        int n;scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
        }
        sort(a+1,a+n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=a[i];j<=a[n];j++){
                dp[j]+=dp[j-a[i]];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            // printf("test: %d %d\n",a[i],dp[a[i]]);
            if(dp[a[i]]==1)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}