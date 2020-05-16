#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
using std::priority_queue;
int* dis;
using std::vector;
struct Edge{
    int w,v;
    Edge(int w,int v){
        this->w=w;
        this->v=v;
    }
    bool operator<(const Edge& e)const{
        return w>e.w;
    }
};
vector< vector<Edge> > G;
void dij(int s,int t){
    priority_queue<Edge> q;
    q.push(Edge(0,s));
    dis[s]=0;
    while(!q.empty()){
        Edge tmp = q.top();q.pop();
        int u=tmp.v;
        if(tmp.w>dis[u])continue;
        if(u==t)return;
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(dis[e.v]>dis[u]+e.w){
                dis[e.v]=dis[u]+e.w;
                q.push(Edge(dis[e.v],e.v));
            }
        }
    }
}
int n,m;
inline void add2edge(int u,int v,int w){
    //printf("test:%d %d %d\n",u,v,w);
    G[u].push_back(Edge(w,v));
    G[v].push_back(Edge(w,u));
}
inline void init(int N){
    memset(dis=(int*)malloc((N+1)*sizeof(int)),0x3f,(N+1)*sizeof(int));
    G.resize(N+1);
}
int main(){
    scanf("%d%d",&n,&m);
    init(2*(n-1)*(m-1)+1);
    //row edge
    for(int j=1;j<=m-1;j++){
        int w;scanf("%d",&w);
        int u=2*j;
        int v=0;
        add2edge(u,v,w);
    }
    for(int i=2;i<=n-1;i++){
        for(int j=1;j<=m-1;j++){
            int w;scanf("%d",&w);
            int u=2*(m-1)*(i-1)+2*j;
            int v=u-2*(m-1)-1;
            add2edge(u,v,w);
        }
    }
    for(int j=1;j<=m-1;j++){
        int w;scanf("%d",&w);
        int u=2*(m-1)*(n-2)+2*j-1;
        int v=2*(n-1)*(m-1)+1;
        add2edge(u,v,w);
    }

    //col edge
    for(int i=1;i<=n-1;i++){

        if(m>1){
            int w;scanf("%d",&w);
            int u=(i-1)*2*(m-1)+1;
            int v=2*(n-1)*(m-1)+1;
            add2edge(u,v,w);
        }else{
            int w;scanf("%d",&w);
            int u=0;
            int v=1;
            add2edge(u,v,w);
        }
        for(int j=2;j<=m-1;j++){
            int w;scanf("%d",&w);
            int v=(i-1)*2*(m-1)+2*j-1;
            int u=v-1;
            add2edge(u,v,w);
        }
        if(m>1){
            int w;scanf("%d",&w);
            int u=i*2*(m-1);
            int v=0;
            add2edge(u,v,w);
        }
    }
    
    //lt-rb edge
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m-1;j++){
            int w;scanf("%d",&w);
            int u=(i-1)*2*(m-1)+2*j-1;
            int v=u+1;
            add2edge(u,v,w);
        }
    }
    dij(0,2*(n-1)*(m-1)+1);
    printf("%d\n",dis[2*(n-1)*(m-1)+1]);
    return 0;
}