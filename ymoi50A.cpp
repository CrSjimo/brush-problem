#include<stdio.h>
#include<vector>
std::vector< std::vector<int> > dp;
std::vector< std::vector<int> > map;
int main(){
    int n;
    scanf("%d",&n);
    dp.resize(n+1);
    map.resize(n+1);
    for(int i=1;i<=n;i++){
        map[i].resize(i+1);
        dp[i].resize(i+1);
        for(int j = 1;j<=i;j++){
            scanf("%d",&dp[i][j]);
        }
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            dp[i][j] += std::max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    printf("%d\n",dp[1][1]);
    return 0;
}