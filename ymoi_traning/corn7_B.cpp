#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cstring>
#include<vector>
#include<set>
using std::set;
using std::min;
using std::vector;
using std::queue;
int w[104];
int k[104];
vector<int> G[104];
int n,m;
int dp[104][1<<15];
void dfs(int u,int fa){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==fa)continue;
        dfs(v,u);
        for(int S=0;S<(1<<(m+1));S++){
            for(int T=0;T<(1<<(m+1));T++){
                dp[u][S|T]=min(dp[u][S]+dp[v][T],dp[u][S|T]);
            }
        }
    }
}
int main(){
    memset(dp,0x3f,sizeof(dp));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",k+i);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",w+i);
    }
    for(int i=1;i<=n-1;i++){
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        dp[i][1<<k[i]]=w[i];
    }
    dfs(1,-1);
    int ans=0x7fffffff;
    printf("%d\n",dp[1][(1<<(m+1))-1]);
    return 0;
}