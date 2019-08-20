#include<stdio.h>
#include<algorithm>
#include<string.h>
#define INF 0x3f3f3f3f
int dp[110][110];
int a[110];
int suma[110];
int main(){
    int cas;
    int sac = 0;
    scanf("%d",&cas);
    while(cas--){
        int n;
        scanf("%d",&n);
	    memset(dp,0,sizeof(dp));
        for(int i = 1;i<=n;i++){
            scanf("%d",a+i);
        }
        for(int i = 1;i<=n;i++){
            suma[i] = a[i]+suma[i-1];
        }
        for(int i = 1;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                dp[i][j]= INF;
            }
        }
        for(int c = 1;c<=n;c++){
            for(int i = 1;i+c<=n;i++){
                int j = i+c;
                for(int kk = i;kk<=j;kk++){
                    int k = kk-i+1;//題目中的k
                    int change = (k-1)*a[i]+dp[i+1][i+k-1]+dp[i+k][j]+k*(suma[j]-suma[i+k-1]);
                    dp[i][j] = std::min(dp[i][j],change);
                }
            }
        }
        printf("Case #%d: %d\n",++sac,dp[1][n]);
    }
    return 0;
}
