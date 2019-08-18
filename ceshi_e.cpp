#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
double dp[250][250];
double cd[250][2];
double calc(double x1,double y1,double x2,double y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
int main(){
    int n;
    int cas = 0;
    while(~scanf("%d",&n) && n){
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<n;i++){
            scanf("%lf%lf",cd[i],cd[i]+1);
        }
        printf("Scenario #%d\n",++cas);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<=i;j++){
                dp[i][j] = dp[j][i] = calc(cd[i][0],cd[i][1],cd[j][0],cd[j][1]);
            }
        }
        for(int k = 0;k<n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    dp[i][j] = std::min(dp[i][j],std::max(dp[i][k],dp[k][j]));
                }
            }
        }
        printf("Frog Distance = %.3lf\n\n",dp[0][1]);
    }
    return 0;
}
