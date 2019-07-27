#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define MAXN 6010
std::vector<int> map[MAXN];
int dp[MAXN][2];
int w[MAXN];
void dfs(int i){
    dp[i][0] = 0;
    dp[i][1] = w[i];
    for(int j = 0;j<map[i].size();j++){
        int ch = map[i][j];
        dfs(ch);
        dp[i][0]+=std::max(dp[ch][0],dp[ch][1]);
        dp[i][1]+=dp[ch][0];
    }
}
bool notBoss[MAXN];
int main(){
    for(int i = 0;i<MAXN;i++){
        map[i].clear();
    }
    memset(dp,0,sizeof(dp));
    memset(notBoss,0,sizeof(notBoss));
    //printf("start\n");
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",w+i);
    }
    int l,k;
    while(~scanf("%d%d",&l,&k) && (l || k)){
        map[k].push_back(l);
        notBoss[l] |= 1;
    }
    for(int i = 1;i<=n;i++){
        if(!notBoss[i]){
            dfs(i);
            printf("%d\n",std::max(dp[i][0],dp[i][1]));
            return 0;
        }
    }
    return 0;
}