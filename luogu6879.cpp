#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::min;
using std::max;
inline int& min_to(int& a,int b){
    return a=min(a,b);
}
const int MAXN = 205;
int t[MAXN];
int a[MAXN];
int dp[MAXN][MAXN][MAXN][2];
signed main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)scanf("%d",t+i);
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0][0]=dp[0][0][0][1]=0;
    a[n+1]=m;
    for(int c=0;c<n;c++){
        for(int l=0;l<=n;l++){
            int r=c-l;
            for(int i=0;i<=n;i++){
                if(dp[l][r][i][0]!=0x3f3f3f3f){
                    int tNow = dp[l][r][i][0];
                    int time0 = tNow+a[n-l+1]-a[n-l];
                    int time1 = tNow+m-(a[n-l+1]-a[r+1]);
                    bool canGet0 = time0 <= t[n-l];
                    bool canGet1 = time1 <= t[r+1];
                    min_to(dp[l+1][r][i+canGet0][0],time0);
                    min_to(dp[l][r+1][i+canGet1][1],time1);
                }
                if(dp[l][r][i][1]!=0x3f3f3f3f){
                    int tNow = dp[l][r][i][1];
                    int time1 = tNow+a[r+1]-a[r];
                    int time0 = tNow+m-(a[n-l]-a[r]);
                    bool canGet0 = time0 <= t[n-l];
                    bool canGet1 = time1 <= t[r+1];
                    min_to(dp[l+1][r][i+canGet0][0],time0);
                    min_to(dp[l][r+1][i+canGet1][1],time1);
                }
            }
        }
    }
    int ans = 0;
    for(int l=0;l<=n;l++)for(int r=0;r<=n;r++)for(int i=0;i<=n;i++){
        if(dp[l][r][i][0]!=0x3f3f3f3f || dp[l][r][i][1]!=0x3f3f3f3f)
            ans=max(ans,i);
    }
    printf("%d\n",ans);
    return 0;
}