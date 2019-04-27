#include <stdio.h>
#include <string.h>
int dp[2020][2020];
//huiwen zichuan
int a[2020];
int n;
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    while(~scanf("%d",&n) && n){
        for(int i = 1;i <= n;i++){
            scanf("%d",a+i);
            a[i+n] = a[i];
            dp[i][i] = dp[i+n][i+n] = 1;
        }
    
        for(int c = 2;c<=n;c++){
            for(int i = 1;i+c-1<=2*n;i++){
                int j = i+c-1;
                if(a[i] == a[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            ans = max(ans,max(dp[i][i+n-1],dp[i][i+n-2]+1));
        }
        printf("%d\n",ans);
    }
    return 0;
}