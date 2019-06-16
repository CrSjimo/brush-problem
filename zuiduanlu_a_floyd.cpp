#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 256
#define INF 0x3f3f3f3f
int dp[MAXN][MAXN];
void floyd(int n){
    for(int k = 0;k<n;k++){
        for(int i = 0 ;i<n;i++){
            for(int j = 0;j<n;j++){
                if(dp[i][k] != INF && dp[k][j] != INF)
                    dp[i][j] = std::min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
}
int n,m;
int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(dp,0x3f,sizeof(dp));
        for(int i = 0;i<n;i++){
            dp[i][i] = 0;
        }
        int x,y,k;
        while(m--){
            scanf("%d%d%d",&x,&y,&k);
            if(dp[x][y] > k){
                dp[x][y] = k;
                dp[y][x] = k;
            }
        }
        floyd(n);
        int start,end;
        scanf("%d%d",&start,&end);
        printf("%d\n",(dp[start][end] == INF)?-1:dp[start][end]);
    }
    return 0;
}