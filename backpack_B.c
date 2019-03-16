#include <stdio.h>
#define MAX_N 3500
#define MAX_M 13000
int dp[MAX_M];
int w[MAX_N];
int c[MAX_N];
int n,m;
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d%d",w+i,c+i);
    }
    for(int i=0;i<n;i++){
        for(int j=m;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
        }
    }
    printf("%d\n",dp[m]);
    return 0;
}