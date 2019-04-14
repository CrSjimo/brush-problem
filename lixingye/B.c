#include<stdio.h>
int n,m;
int dp[30010];
int w[100];
int c[100];
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;i++){
        scanf("%d%d",w+i,c+i);
        c[i]*=w[i];
    }
    for(int i = 1;i<=m;i++){
        for(int j = n;j>=w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]]+c[i]);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}