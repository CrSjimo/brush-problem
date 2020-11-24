#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
using std::vector;
struct Edge{
    int v, w;
    Edge(){}
    Edge(int v,int w){
        this->v=v;
        this->w=w;
    }
};
int p,dis=0;
vector< vector<Edge> > G;
bool* vis;
void dfs(int u,int d){
    vis[u]=1;
    if(d>dis){
        dis=d;
        p=u;
    }
    for(int i=0;i<G[u].size();i++){
        Edge& e=G[u][i];
        if(vis[e.v])continue;
        dfs(e.v,d+e.w);
    }
}
int main(){
    freopen("WA.in","r",stdin);
    freopen("WA.out","w",stdout);
    int n,m;scanf("%d%d",&n,&m);
    G.resize(n+1);
    vis=(bool*)calloc((n+1),sizeof(bool));
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
    }
    
        dfs(1,0);
        memset(vis,0,(n+1)*sizeof(bool));
        dis=0;
        dfs(p,0);
    
    printf("%.2lf\n",1.0*dis/2);
    return 0;
}