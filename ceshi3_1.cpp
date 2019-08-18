#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 0x3f3f3f3f
long long dp[100010][3];
long long ddp[100010][3];
bool noCanDo(int j,int k){
    if(j == 1)return false;
    if(j == 0&&k == 2)return true;
    if(j == 2&&k == 0)return true;
    return false;
}
int n;
namespace d{
    void p(){
        for(int i = 1;i<n;i++){
            for(int j = 0;j<3;j++){
                long long maxn = -INF;
                long long minn = INF;
                for(int k = 0;k<3;k++){
                    if(noCanDo(j,k))continue;
                    maxn = std::max(dp[i-1][k],maxn);
                    minn = std::min(ddp[i-1][k],minn);
                }
                bool is0 = 0;
                if(dp[i][j] == 0)is0 = 1;
                dp[i][j]+=maxn;
                ddp[i][j]+=minn;
                if(is0){
                    long long ago = -ddp[i][j];
                    ddp[i][j] = -dp[i][j];
                    dp[i][j] = ago;
                }
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%lld%lld%lld",&dp[i][0],&dp[i][1],&dp[i][2]);
        ddp[i][0] = dp[i][0];
        ddp[i][1] = dp[i][1];
        ddp[i][2] = dp[i][2];
    }
    d::p();
    printf("%lld\n",*std::max_element(dp[n-1],dp[n-1]+3));
    return 0;
}