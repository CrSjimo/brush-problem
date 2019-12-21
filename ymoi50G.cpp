#include<stdio.h>
#include<vector>
const int MOD = 12345;
int main(){
    int n;
    scanf("%d",&n);
    std::vector< std::vector<int> > dp(n+1,std::vector<int>(2));
    dp[1][0]=9;//even
    dp[1][1]=1;//odd
    for(int i=2;i<=n;i++){
        int t = 9;
        if(i==n)t--;
        dp[i][0]=(dp[i-1][1]+t*dp[i-1][0])%MOD;
        dp[i][1]=(dp[i-1][0]+t*dp[i-1][1])%MOD;
    }
    printf("%d\n",dp[n][0]);
    return 0;
}