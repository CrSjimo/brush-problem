#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>
using std::max;
using std::max_element;
using std::unique;
using std::queue;
using std::vector;
struct Edge{
    bool type;
    int v;
    Edge(){}
    Edge(bool type,int v){
        this->type=type;
        this->v=v;
    }
};
vector< vector<Edge> >G;
vector< vector<int> >G1;
int* w;
int n,m,k,a,b,wa,wb;
int* ind;
int* f;
void dfs(int s,int u,int d){
    if(d==a){
        G[s].push_back(Edge(false,u));
        ind[u]++;
    }else if(d==b){
        G[s].push_back((Edge(true,u)));
        return;
    }
    for(int i=0;i<G1[u].size();i++){
        int v=G1[u][i];
        dfs(s,v,d+1);
    }
}
void dfs2(int u){
    for(int i=0;i<G[u].size();i++){
        Edge& e=G[u][i];
        int v=e.v;
        int cost=e.type?wb:wa;
        f[v]=max(f[v],f[u]+w[v]-cost);
        dfs2(v);
    }
}
int main(){
    scanf("%d%d%d%d%d%d%d",&n,&m,&k,&a,&b,&wa,&wb);
    G.resize(m+1);
    G1.resize(m+1);
    w=(int*)calloc((m+1),sizeof(int));
    f=(int*)calloc((m+1),sizeof(int));
    ind=(int*)calloc((m+1),sizeof(int));
    for(int i=1;i<=n;i++){
        int u,t;scanf("%d%d",&u,&t);
        w[u]=t;
    }
    for(int i=1;i<=k;i++){
        int u,v;scanf("%d%d",&u,&v);
        G1[u].push_back(v);
    }
    for(int i=1;i<=m;i++){
        dfs(i,i,0);
    }
    dfs2(1);
    printf("%d\n",*max_element(f+1,f+m+1));
    return 0;
}