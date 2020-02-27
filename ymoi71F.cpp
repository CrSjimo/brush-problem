#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::min;
using std::max;
int dp[10][10][10][10];
int a[10][10];
int n;
int main(){
    scanf("%d",&n);
    int x,y,k;
    while(~scanf("%d%d%d",&x,&y,&k) && x && y && k){
        a[x][y]=k;
    }
    for(int i1=1;i1<=n;i1++)for(int j1=1;j1<=n;j1++)for(int i2=1;i2<=n;i2++)for(int j2=1;j2<=n;j2++){
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
    printf("%d\n",dp[n][n][n][n]);
    return 0;
}