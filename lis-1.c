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
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            scanf("%d",dp+i);
        }
        int maxn = -1001;
        int mr = 1;
        int ml =1;
        int tmp=1;
        for(int i=1;i<=n;i++){
            // dp[i] = max(dp[i-1],0)+a[i];
            if(dp[i-1] > 0){
                dp[i]+=dp[i-1];
            }else{
                tmp =i;
            }
            if(maxn<dp[i]){
                mr = i;
                ml = tmp;
            }
            maxn = max(maxn,dp[i]);
        }
        printf("Case %d:\n%d %d %d\n",++t,maxn,ml,mr);
        if(cas)printf("\n");
    }
    return 0;
}