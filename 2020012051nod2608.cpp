#include<stdio.h>
#include<vector>
std::vector< std::vector<int> > G;
std::vector<char> vis;
bool dfs(int u){
    if(vis[u]==1)return false;
    if(vis[u]==-1)return true;
    vis[u]=1;
    for(int i=0;i<G[u].size();i++){
        if(!dfs(G[u][i]))return false;
    }
    vis[u]=-1;
    return true;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    G.resize(n+5);
    vis.resize(n+5);
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        if(!dfs(i)){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}