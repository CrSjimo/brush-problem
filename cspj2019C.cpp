#include<stdio.h>
#include<vector>
#include<algorithm>
int cnt = 0;
int main(){
    int t,n,m;
    scanf("%d%d%d",&t,&n,&m);
    cnt=m;
    std::vector< std::vector<int> > cost(t+5,std::vector<int>(n+5));
    for(int i=1;i<=t;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    for(int i=1;i<t;i++){
        std::vector<int> dp(10010,-0x3f3f3f3f);
        dp[cnt]=cnt;
        for(int j=1;j<=n;j++){
            for(int k=cnt;k>=cost[i][j];k--){
                dp[k-cost[i][j]]=std::max(dp[k-cost[i][j]],dp[k]+cost[i+1][j]-cost[i][j]);
            }
        }
        cnt=*std::max_element(dp.begin(),dp.begin()+cnt+1);
    }
    printf("%d\n",cnt);
    return 0;
}