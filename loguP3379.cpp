#include<cstdio>
#include<cstdlib>
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
        if(v==fa)continue;
        dfs(v,u);
    }
}
void init(int s){
    dfs(s,0);
    for(int j=1;j<=log2n;j++){
        for(int i=1;i<=n;i++){
            f[i][j]=f[f[i][j-1]][j-1];
        }
    }
}
int lca(int u,int v){
    if(dep[v]>dep[u])swap(u,v);
    for(int j=log2n;j>=0;j--){
        if(dep[v]<=dep[f[u][j]]){
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
int main(){
    int m,s;scanf("%d%d%d",&n,&m,&s);
    log2n = (int)(log2(n)+1);
    G.resize(n+1);
    dep=(int*)calloc(n+1,sizeof(int));
    f=(int**)malloc((n+1)*sizeof(int*));
    for(int**p=f;p<=f+n;p++)*p=(int*)calloc((log2n+1),sizeof(int));
    for(int i=1;i<=n-1;i++){
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    init(s);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        printf("%d\n",lca(u,v));
    }
    return 0;
}