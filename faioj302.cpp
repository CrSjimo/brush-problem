#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
using std::vector;
using std::priority_queue;
struct Edge{
    int dis;
    int v;
    Edge(){}
    Edge(int dis,int v){
        this->dis=dis;
        this->v=v;
    }
    bool operator<(const Edge& e)const{
        return dis>e.dis;
    }
};
const int INF = 0x3f3f3f3f;
vector< vector<Edge> > G;
int* dis;
int n,m;
void dij(int s,int t){
    priority_queue<Edge> q;
    q.push(Edge(0,s));
    dis[s]=0;
    while(!q.empty()){
        Edge tmp = q.top();q.pop();
        int u=tmp.v;
        if(tmp.dis>dis[u])continue;
        if(u==t)return;
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(dis[e.v]>dis[u]+e.dis){
                dis[e.v]=dis[u]+e.dis;
                q.push(Edge(dis[e.v],e.v));
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    int s,t;
    scanf("%d%d",&s,&t);
    G.resize(n+1);
    dis=(int*)malloc((n+1)*sizeof(int));
    for(int i=0;i<=n;i++)dis[i]=INF;
    while(m--){
        int x,y;
        int d;
        scanf("%d%d%d",&x,&y,&d);
        G[x].push_back(Edge(d,y));
        G[y].push_back(Edge(d,x));
    }
    dij(s,t);
    printf("%d\n",dis[t]);
    return 0;
}