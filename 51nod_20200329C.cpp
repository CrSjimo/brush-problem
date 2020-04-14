#include<cstdio>
#include<cstdlib>
#include<vector>
using std::max;
using std::vector;
vector<int>G[1005];
bool available[1005];
bool vis[1005];
bool is[1005];
int ind[1005];
int outd[1005];

int T = 0;
int n=0,m;
void dfs(int u){
    vis[u]=true;
    if(ind[u]!=outd[u])is[T]=false;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!vis[v])dfs(v);
    }
}
int main(){
    scanf("%d",&m);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        available[u]=available[v]=true;
        outd[u]++;ind[v]++;
        n=max(max(n,u),v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!available[i])continue;
        ans+=max(ind[i],outd[i]);
        if(!vis[i]){
            is[++T]=true;
            dfs(i);
            if(is[T])ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}