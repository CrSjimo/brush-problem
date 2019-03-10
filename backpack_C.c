#include<stdio.h>
#include<string.h>
int dp[1010][1010],c[1010];
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        memset(dp,0,sizeof dp);
        memset(c,0,sizeof c);
        int money;
        for(int i=1;i<=n;i++)scanf("%d",c+i);
        scanf("%d",&money);
        for(int i=1;i<=n;i++){
            for(int j=0;j<money-5;j++){
                if(j>=c[i]){
                    dp[i][j]=max(dp[i-1][j-c[i]]+c[i],dp[i-1][j]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
                
            }
        }
        printf("%d",dp[n][money-5]);
    }
    
}