#include <stdio.h>
#include<string.h>
#define MAX_N 110
#define MAX_M 100010
int dp[MAX_M];
int w[MAX_N];
int c[MAX_N];
int n,m;
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    while(~scanf("%d",&n)){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            scanf("%d%d",c+i,w+i);
        }
        scanf("%d",&m);
        for(int i=0;i<n;i++){
            for(int j=w[i];j<=m;j++){
                dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}