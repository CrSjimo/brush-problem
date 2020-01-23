#include<stdio.h>
#include<vector>
std::vector< std::vector<int> > G;
std::vector<char> vis;
std::vector<int> dfn;
int minn=0x3f3f3f3f;
int dfs(int u,int num){
    if(vis[u]==1)return num-dfn[u];
    if(vis[u]==-1)return 0;
    vis[u]=1;
    for(int i=0;i<G[u].size();i++){
        int k=dfs(G[u][i],num+1);
        if(k){
            minn=std::min(minn,k);
            return minn;
        }
    }
    vis[u]=-1;
    dfn[u]=num;
    return 0;
}
int main(){
    int n;scanf("%d",&n);
    G.resize(n+5);
    vis.resize(n+5);
    dfn.resize(n+5);
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        G[i].push_back(k);
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        dfs(i,0);
    }
    printf("%d\n",minn);
    return 0;
}