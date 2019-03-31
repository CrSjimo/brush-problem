#include<stdio.h>
#include<string.h>
int a[1010];
int dp[1010];
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(a[j]<a[i]){
                    dp[i] = max(dp[i],dp[j]+a[i]);
                }
            }
        }
        int ans = -1;
        for(int i=1;i<=n;i++){
            ans = max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}