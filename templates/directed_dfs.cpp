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