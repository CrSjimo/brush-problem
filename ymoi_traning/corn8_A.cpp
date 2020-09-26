#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
using std::swap;
using std::vector;

template<typename T>T*&alloc(T*&a,size_t siz){
    return a=(T*)calloc(siz,sizeof(T));
}

struct Edge{
    int v,w;
    Edge(){}
    Edge(int v,int w){
        this->v=v;
        this->w=w;
    }
};

vector< vector<Edge> >G;

int** fa;
int* dis;
int* dep;
int n,log2n;
void dfs(int u,int p){
    dep[u]=dep[p]+1;
    for(int i=0;i<G[u].size();i++){
        Edge& e=G[u][i];
        if(e.v==p)continue;
        fa[e.v][0]=u;
        dis[e.v]=dis[u]+e.w;
        for(int j=1;j<=log2n;j++){
            fa[e.v][j]=fa[fa[e.v][j-1]][j-1];
        }
        dfs(e.v,u);
    }
}

void init(){
    log2n=(int)log2(n)+1;
    alloc(fa,n+1);
    for(int**p=fa;p<=fa+n;p++)alloc(*p,log2n);
    alloc(dis,n);
    alloc(dep,n);
    dfs(1,0);
}
 
inline int ddis(int u,int v,int z){
    return dis[u]+dis[v]-2*dis[z];
}
int query(int v,int d){
    // printf("test: %d %d\n",dis[v],d);
    if(dis[v]<=d)return v;
    for(int j=log2n;j>=0;j--){
        if(fa[v][j]&&dis[fa[v][j]]>d){
            v=fa[v][j];
        }
    }
    return fa[v][0];
}
#define OJ
int main(){
    #ifdef OJ
    freopen("visit.in","r",stdin);
    freopen("visit.out","w",stdout);
    #endif
    int m;scanf("%d%d",&n,&m);
    G.resize(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
    }
    init();
    // int u,v;
    // while(~scanf("%d%d",&u,&v)){
    //     printf("test: %d\n",lca(u,v));
    // }
    while(m--){
        int v,d;scanf("%d%d",&v,&d);
        printf("%d\n",query(v,d/2));
    }
    return 0;
}