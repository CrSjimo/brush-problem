#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 1<<20
#define INF 0x3f3f3f3f
int dp[MAXN];
int max[MAXN];
int a[MAXN];
int main(){
    int m,n;
    while(~scanf("%d%d",&m,&n)){
        memset(dp,0,sizeof(dp));
        memset(max,0,sizeof(max));
        for(int i = 0;i<n;i++){
            scanf("%d",a+i);
        }
        int maxn = -INF;
        for(int i = 0;i<m;i++){
            maxn = -INF;
            for(int j = i;j<n;j++){
                dp[j] = std::max(dp[j-1]+a[j],max[j-1]+a[j]);
                max[j-1]=maxn;
                maxn = std::max(maxn,dp[j]);
            }
        }
        printf("%d\n",maxn);
    }
    return 0;
}