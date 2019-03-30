#include<stdio.h>
#include<stdbool.h>
int c[2];
int w[110];
bool taken[110];
int dp[1010][1010];
int n;
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,c,c+1);
        for(int i = 1;i<=n;i++){
            scanf("%d",w+i);
        }
        for(int i = 1;i <= n;i++){
            if(taken[i])continue;
            for(int j = 0;j<=c[0];j++){
                if(j>=w[i]){
                    if(dp[i-1][j] < dp[i-1][j-w[i]]+w[i]){
                        taken[i] = 1;
                    }
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+w[i]);
                }else{
                    dp[i][j] = dp[i-1][j];
                } 
            }
        }
    }
}