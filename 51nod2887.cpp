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
int n;
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
    scanf("%d",&n);
    int N = (n-1)*(n-1)+1;
    init(N);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int w;scanf("%d",&w);

            //connect V dir
            if(i==n){
                //do nothing
            }else if(j==1){
                int u=N,v=(i-1)*(n-1)+j;
                add2edge(u,v,w);
            }else if(j==n){
                int u=i*(n-1),v=0;
                add2edge(u,v,w);
            }else{
                int u=(i-1)*(n-1)+j-1,v=u+1;
                add2edge(u,v,w);
            }

            //connect H dir

            if(j==n){
                //do nothing
            }else if(i==1){
                int u=0,v=(i-1)*(n-1)+j;
                add2edge(u,v,w);
            }else if(i==n){
                int u=(i-2)*(n-1)+j,v=N;
                add2edge(u,v,w);
            }else{
                int u=(i-2)*(n-1)+j,v=(i-1)*(n-1)+j;
                add2edge(u,v,w);
            }
        }
    }
    dij(0,N);
    printf("%d\n",dis[N]);
    return 0;
}