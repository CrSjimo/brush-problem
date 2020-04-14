#include<vector>
#include<cmath>
using std::vector;
using std::swap;
vector< vector<int> > G;
int* dep;
int** f;
int n,log2n;
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    f[u][0]=fa;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        dfs(v,u);
    }
}
void init(){
    log2n = (int)(log2(n)+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=log2n;j++){
            f[i][j]=f[f[i][j-1]][j-1];
        }
    }
}
int lca(int u,int v){
    if(dep[v]>dep[u])swap(u,v);
    for(int j=log2n;j>=0;j--){
        if(dep[v]<dep[f[u][j]]){
            u=f[u][j];  
        }
    }
    if(u==v)return u;
    for(int j=log2n;j>=0;j--){
        if(f[u][j]!=f[v][j]){
            u=f[u][j];v=f[v][j];
        }
    }
    return f[u][0];
}