#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::min;
using std::max;
int* a;
int* s;
int dp[405][405];
int pd[405][405];
int main(){
    int n;scanf("%d",&n);
    a=(int*)calloc((n+1),sizeof(int));
    s=(int*)calloc((2*n+1),sizeof(int));
     memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
        scanf("%d",a+i);
    }
    for(int i=1;i<=2*n-1;i++){
        dp[i][i]=0;
        s[i]=s[i-1]+a[(i-1)%n+1];
    }
    for(int i=2*n-1;i>=1;i--){
        for(int j=i+1;j<=2*n-1;j++){
            for(int k=i;k<=j-1;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+s[j]-s[i-1]);
                pd[i][j]=max(pd[i][j],pd[i][k]+pd[k+1][j]+s[j]-s[i-1]);
            }
        }
    }
    int maxn=dp[1][n];
    int minn=dp[1][n];
    for(int i=1;i<=n;i++){
        maxn=max(pd[i][i+n-1],maxn);
        minn=min(dp[i][i+n-1],minn);
    }
    printf("%d\n%d\n",minn,maxn);
    return 0;
}