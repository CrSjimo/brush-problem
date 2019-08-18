#include<stdio.h>
#include<string.h>
int dp[1010],w[1010],c[1010];
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int t;
    scanf("%d",&t);
    for(;t>0;t--){
        memset(dp,0,sizeof dp);
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",c+i);
        for(int i=1;i<=n;i++)scanf("%d",w+i);
        for(int i=1;i<=n;i++){
            for(int j=w[i];j<=m;j++){
                    dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}