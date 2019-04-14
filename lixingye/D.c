#include<stdio.h>
#include<string.h>
int n,h;
int a[105];
int b[105];
int dp[60000];
int min(int a,int b){
    return a<b?a:b;
}
int main(){
    memset(dp,0x79,sizeof(dp));
    scanf("%d%d",&n,&h);
    for(int i = 1;i<=n;i++){
        scanf("%d%d",b+i,a+i);
        dp[b[i]]=min(dp[b[i]],a[i]);
    }
    dp[0] = 0;
    for(int i = 1;i<=n;i++){
        for(int j = b[i];j<=h+5010;j++){
            dp[j] = min(dp[j],dp[j-b[i]]+a[i]);
        }//max(dp[i][j-c[i]]+h[i],dp[i-1][j])
    }
    int minn = 1<<20;
    for(int i = h;i<=h+5010;i++){
        minn = min(dp[i],minn);
    }
    printf("%d\n",minn);
    return 0;
}