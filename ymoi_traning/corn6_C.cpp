#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
using std::vector;
#include<queue>
using std::priority_queue;
using std::min;
typedef long long ll;
struct Edge{
    int v;
    ll w;
    Edge(){}
    Edge(int v,ll w){
        this->v=v;
        this->w=w;
    }
    bool operator<(const Edge& e)const{
        return w>e.w;
    }
};
typedef Edge HeapNode;
vector< vector<Edge> >G;
ll* dis1;
ll* dis2;
void dij(int s,int t,ll* dis){
    priority_queue<HeapNode> q;
    q.push(HeapNode(s,0));
    dis[s]=0;
    while(!q.empty()){
        HeapNode tmp=q.top();q.pop();
        int u=tmp.v;
        if(u==t)return;
        if(tmp.w>dis[u])continue;
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(dis[e.v]>dis[u]+e.w){
                dis[e.v]=dis[u]+e.w;
                q.push(HeapNode(e.v,dis[e.v]));
            }
        }
    }
}
int main(){
    int s,t;
    int n,m;scanf("%d%d%d%d",&n,&m,&s,&t);
    G.resize(n+1);
    dis1=(ll*)malloc((n+1)*sizeof(ll));
    memset(dis1,0x3f,(n+1)*sizeof(ll));
    dis2=(ll*)malloc((n+1)*sizeof(ll));
    memset(dis2,0x3f,(n+1)*sizeof(ll));
    while(m--){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
    }
    dij(s,t,dis1);
    dij(t,s,dis2);
    printf("%lld\n0\n",dis1[t]);
    return 0;
}