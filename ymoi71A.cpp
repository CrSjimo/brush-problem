#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::min;
int* a;
int* s;
int dp[100][100];
int main(){
    int n;scanf("%d",&n);
    a=(int*)malloc((n+1)*sizeof(int));
    s=(int*)malloc((n+1)*sizeof(int));
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
        scanf("%d",a+i);
        s[i]=s[i-1]+a[i];
    }
    for(int i=n;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            for(int k=i;k<=j-1;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+s[j]-s[i-1]);
            }
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}