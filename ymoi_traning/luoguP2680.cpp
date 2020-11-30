#include<cstdio>
#include<cstdlib>
#include<vector>
#include<utility>
using std::min;
using std::max;
typedef std::pair<int,int> pii;
using std::make_pair;
using std::vector;
int n,m;
struct Edge{
    int v,w;
    Edge(){}
    Edge(int v,int w){
        this->v=v;
        this->w=w;
    }
};
vector< vector<Edge> >G;
struct Query{
    int u,v,zgz;
    Query(){}
    Query(int u,int v){
        this->u=u;this->v=v;
    }
    int dis();
};
vector<Query> queries;
int* dep;
int** fa;
int* dis;
template<typename T>inline T*&alloc(T*&a,size_t siz){
    return a=(T*)calloc(siz,sizeof(T));
}
void dfs(int u,int p){
    dep[u]=dep[p]+1;
    for(int i=0;i<G[u].size();i++){
        Edge& e=G[u][i];
        if(e.v==p)continue;
        fa[e.v][0]=u;
        dis[e.v]=dis[u]+e.w;
        for(int j=1;j<=20;j++){
            fa[e.v][j]=fa[fa[e.v][j-1]][j-1];
        }
        dfs(e.v,u);
    }
}
inline int lca(int u,int v){
    if(dep[u]<dep[v])u^=v^=u^=v;
    for(int j=20;j>=0;j--){
        if(dep[fa[u][j]]>=dep[v]){
            u=fa[u][j];
        }
    }
    if(u==v)return u;
    for(int j=20;j>=0;j--){
        if(fa[u][j]!=fa[v][j]){
            u=fa[u][j];v=fa[v][j];
        }
    }
    return fa[u][0];
}
inline bool edge_on_path(int u,int v,int eu,int ev,int zgz){
    if(dep[eu]<dep[ev])eu^=ev^=eu^=ev;
    if((lca(ev,zgz)==zgz&&lca(u,eu)==eu)||(lca(ev,zgz)==zgz&&lca(v,eu)==eu)){
        return true;
    }
    return false;
}
inline int calc_dis(int u,int v,int zgz){
    return dis[u]+dis[v]-2*dis[zgz];
}
inline int Query::dis(){
    return calc_dis(this->u,this->v,this->zgz);
}
void init_lca(){
    alloc(dep,n+1);
    alloc(fa,n+1);
    for(int i=0;i<=n;i++)alloc(fa[i],22);
    alloc(dis,n+1);
    dfs(1,0);
}
int ans = 0x3f3f3f3f;
void dfs_edge(int u,int p){
    for(int i=0;i<G[u].size();i++){
        Edge& e=G[u][i];
        if(e.v==p)continue;
        int maxn = -19260817;
        for(int j=1;j<=m;j++){
            int qu = queries[j].u,qv = queries[j].v;
            int d=queries[j].dis();
            if(edge_on_path(qu,qv,u,e.v,queries[j].zgz)){
                d-=e.w;
            }
            maxn=max(maxn,d);
        }
        ans=min(ans,maxn);
        dfs_edge(e.v,u);
    }
}
bool sub1 = true;
int main(){
    scanf("%d%d",&n,&m);
    G.resize(n+1);
    queries.resize(m+1);
    for(int i=1;i<=n-1;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
        if(!(v==u+1||u==v+1))sub1=false;
    }
    init_lca();
    for(int i=1;i<=m;i++){
        scanf("%d%d",&queries[i].u,&queries[i].v);
        queries[i].zgz = lca(queries[i].u,queries[i].v);
    }
    if(false){

    }else{
        dfs_edge(1,0);
    }
    // for(int i=1;i<=m;i++){
    //     int u,v,eu,ev;
    //     scanf("%d%d%d%d",&u,&v,&eu,&ev);
    //     int zgz = lca(u,v);
    //     printf("%d\n",edge_on_path(u,v,eu,ev,zgz));
    // }
    printf("%d\n",ans);
    return 0;
}