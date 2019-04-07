#include<stdio.h>
#include<string.h>
int n,h;
int a[105];
int b[105];
int dp[50010];
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
        for(int j = b[i];j<=2*h;j++){
            dp[j] = min(dp[j],dp[j-b[i]]+a[i]);
        }
    }
    int minn = 1<<30;
    for(int i = h;i<=2*h;i++){
        minn = min(dp[h],minn);
    }
    printf("%d\n",minn);
    return 0;
}