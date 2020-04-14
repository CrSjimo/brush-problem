#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
using std::vector;
using std::priority_queue;
struct Edge{
    double dis;
    int v;
    Edge(){}
    Edge(double dis,int v){
        this->dis=dis;
        this->v=v;
    }
    bool operator<(const Edge& e)const{
        return dis>e.dis;
    }
};
const double INF=192608171926.1926;
vector< vector<Edge> > G;
double* dis;
int n,m;
void dij(int s,int t){
    priority_queue<Edge> q;
    q.push(Edge(1.0,s));
    dis[s]=1.0;
    while(!q.empty()){
        Edge tmp = q.top();q.pop();
        int u=tmp.v;
        if(tmp.dis>dis[u])continue;
        if(u==t)return;
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(dis[e.v]>dis[u]*e.dis){
                dis[e.v]=dis[u]*e.dis;
                q.push(Edge(dis[e.v],e.v));
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    G.resize(n+1);
    dis=(double*)malloc((n+1)*sizeof(double));
    for(int i=0;i<=n;i++)dis[i]=INF;
    while(m--){
        int x,y;
        double d;
        scanf("%d%d%lf",&x,&y,&d);
        d=1.0/(1-(d/100.0));
        G[x].push_back(Edge(d,y));
        G[y].push_back(Edge(d,x));
    }
    int s,t;
    scanf("%d%d",&s,&t);
    dij(s,t);
    printf("%.8lf\n",dis[t]*100);
    return 0;
}