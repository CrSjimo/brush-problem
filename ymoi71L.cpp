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
    for(int i=0;i<=n;i++){
        dp[i][i]=0;
        scanf("%d",a+i);
    }
    for(int j=1;j<=n;j++){
        for(int i=j;i>=1;i--){
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]);
            }
        }
    }
    printf("%lld\n",dp[1][n]);
    return 0;
}