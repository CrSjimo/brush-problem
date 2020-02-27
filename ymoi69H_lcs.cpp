#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::max;
char a[260],b[260];
int dp[260][260];
int main(){
    scanf("%s%s",a+1,b+1);
    int n = strlen(a+1);
    int m = strlen(b+1);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}