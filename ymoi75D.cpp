#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<utility>
using std::pair;
using std::make_pair;
using std::priority_queue;
using std::vector;
using std::min;
double* dis;
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
vector< vector<Edge> > G;
void dij(int s,int t){
    priority_queue<Edge> q;
    q.push(Edge(0,s));dis[s]=0;
    while(!q.empty()){
        Edge tmp = q.top();q.pop();
        int u=tmp.v;
        if(u==t)return;
        if(dis[u]<tmp.dis)continue;
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(dis[e.v]>dis[u]+e.dis){
                dis[e.v]=dis[u]+e.dis;
                q.push(Edge(dis[e.v],e.v));
            }
        }
    }
}
typedef pair<double,double> plflf;
inline double calc(plflf p1,plflf p2){
    return sqrt(pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2));
}
vector<plflf> pts;
int main(){
    int n;scanf("%d",&n);
    G.resize(n+1);
    pts.resize(n+1);
    dis=(double*)malloc((n+1)*sizeof(double));
    for(int i=1;i<=n;i++){
        dis[i]=1926081719260817.0;
        scanf("%lf%lf",&pts[i].first,&pts[i].second);
    }
    int m;scanf("%d",&m);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        double d = calc(pts[u],pts[v]);
        G[u].push_back(Edge(d,v));
        G[v].push_back(Edge(d,u));
    }
    int s,t;scanf("%d%d",&s,&t);
    dij(s,t);
    printf("%.2lf\n",dis[t]);
    return 0;
}