#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using std::priority_queue;
using std::vector;
typedef long long ll;
ll* dis;
struct Edge{
    ll w;
    int v;
    Edge(){}
    Edge(ll w,int v){
        this->w=w;
        this->v=v;
    }
    bool operator<(const Edge& e)const{
        return w>e.w;
    }
};
int n,m;
vector< vector<Edge> > G;
void dijstra(int s){
    priority_queue<Edge> q;
    q.push(Edge(0,s));
    dis[s]=0;
    while(!q.empty()){
        Edge tmp=q.top();q.pop();
        int u=tmp.v;
        if(dis[u]<tmp.w)continue;
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(dis[e.v]>dis[u]+e.w){
                dis[e.v]=dis[u]+e.w;
                q.push(Edge(dis[e.v],e.v));
            }
        }
    }
}
int s,t;
int main(){
    scanf("%d%d",&n,&m);
    memset(dis=(ll*)malloc((n+1)*sizeof(ll)),0x7f,(n+1)*sizeof(ll));
    G.resize(n+1);
    while(m--){
        int u,v;ll w;
        scanf("%d%d%lld",&u,&v,&w);
        G[u].push_back(Edge(w,v));
        G[v].push_back(Edge(w,u));
    }
    scanf("%d%d",&s,&t);
    dijstra(s);
    printf("%lld\n",dis[t]);
    return 0;
}