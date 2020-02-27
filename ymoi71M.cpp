#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::min;
typedef long long ll;
ll dp[505][505];
int a[505];
int main(){
    int n;scanf("%d",&n);
    n;
    memset(dp,0x3f,sizeof(dp));
    //a=(int*)malloc((n+1)*sizeof(int));
    // dp=(ll**)malloc((n+1)*sizeof(ll*));
    // for(ll** p=dp;p<=dp+n;p++)memset(*p=(ll*)malloc((n+1)*sizeof(ll)),0x3f,(n+1)*sizeof(ll));
    for(int i=1;i<=n;i++){
        dp[i][i+1]=0;
        scanf("%d",a+i);
    }
    for(int i=n-2;i>=1;i--){
        for(int j=i+2;j<=n;j++){
            for(int k=i+1;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         printf("%lld ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%lld\n",dp[1][n]);
    return 0;
}