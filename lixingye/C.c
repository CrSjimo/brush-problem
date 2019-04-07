#include<stdio.h>
int t,m;
int dp[1010];
int w[105],c[105];
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    scanf("%d%d",&t,&m);
    for(int i = 1;i<=m;i++){
        scanf("%d%d",w+i,c+i);
    }
    for(int i = 1;i<=m;i++){
        for(int j = t;j>=w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]]+c[i]);
        }
    }
    printf("%d\n",dp[t]);
    return 0;
}