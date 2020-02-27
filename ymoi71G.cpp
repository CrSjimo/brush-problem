#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::min;
using std::max;
int dp[51][51][51][51];
int a[51][51];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    int x,y,k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i1=1;i1<=n;i1++)for(int j1=1;j1<=m;j1++)for(int i2=1;i2<=n;i2++)for(int j2=1;j2<=m;j2++){
        dp[i1][j1][i2][j2]=max(
            max(
                dp[i1-1][j1][i2-1][j2],
                dp[i1][j1-1][i2][j2-1]
            ),
            max(
                dp[i1][j1-1][i2-1][j2],
                dp[i1-1][j1][i2][j2-1]
            )
        );
        int *a1=&a[i1][j1];
        int *a2=&a[i2][j2];
        if(a1==a2){
            dp[i1][j1][i2][j2]+=*a1;
        }else{
            dp[i1][j1][i2][j2]+=(*a1+*a2);
        }
    }
    printf("%d\n",dp[n][m][n][m]);
    return 0;
}