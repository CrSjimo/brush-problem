#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int a[100005];
int dp[100005];
int src[100005];
int cas;
int n;
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int t=0;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
        }
        memset(dp,0,sizeof(dp));
        memset(src,0,sizeof(src));
        int maxn = -1001;
        int mr = 0;
        int ml =0;
        int tmp=0;
        for(int i=1;i<=n;i++){
            if(dp[i-1]>0){
                src[i] = src[i-1];
            }else{
                src[i] = i;
            }
            dp[i] = max(dp[i-1],0)+a[i];
            if(maxn<dp[i]){
                mr = i;
            }
            maxn = max(maxn,dp[i]);
        }
        printf("Case %d:\n%d %d %d\n\n",++t,maxn,src[n],mr);
    }
    return 0;
}