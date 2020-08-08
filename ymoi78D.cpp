#include<cstdio>
#include<algorithm>
using std::max;
int a[256][256];
int f[256][256];
int dp[256];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            f[i][j]=f[i-1][j]+a[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=1;k<=m;k++){
                ans=max(ans,dp[k]=max(dp[k-1],0)+f[j][k]-f[i-1][k]);
            }
        }
    }
    if(ans==0)printf("No\n");
    else printf("%d\n",ans);
    return 0;
}/*
4 5
1 -2 3 -4 5
6 7 8 9 10
-11 12 13 14 -15
16 17 18 19 20
*/