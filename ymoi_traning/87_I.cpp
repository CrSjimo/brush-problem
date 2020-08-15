#include<cstdio>
#include<cstdlib>
#include<vector>
using std::max;
using std::vector;
int dp[3030][3030];
int siz[3030];
int val[3030];
vector< vector<int> >G;
void dfs(int u){
    dp[u][1]=val[u];siz[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        dfs(v);
        for(int k=siz[u];k>=1;k--){
            for(int j=1;j<=siz[v];j++){
                dp[u][k+j]=max(dp[u][k+j],dp[u][k]+dp[v][j]);
            }
        }
        siz[u]+=siz[v];
    }
}
int main(){
    int n,m;scanf("%d%d",&n,&m);
    G.resize(n+5);
    for(int i=1;i<=n;i++){
        int p,k;scanf("%d%d",&p,&val[i]);
        G[p].push_back(i);
    }
    dfs(0);
    printf("%d\n",dp[0][m+1]);
    return 0;
}