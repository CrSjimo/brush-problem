#include<stdio.h>
#include<vector>
#include<algorithm>
void floyd(int n,std::vector< std::vector<int> >& dp){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]|=dp[i][k]&dp[k][j];
            }
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    std::vector< std::vector<int> > dp(n+5,std::vector<int>(n+5,0));
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        dp[x][y]=1;
    }
    floyd(n,dp);
    int ans = 0;
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=1;j<=n;j++){
            if(dp[i][j]||dp[j][i])cnt++;
        }
        if(cnt==n-1)ans++;
    }
    printf("%d\n",ans);
    return 0;
}