#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<queue>
using std::priority_queue;
using std::min;
using std::vector;
typedef long long ll;
struct Edge{
    int v;
    ll w;
    Edge(){}
    Edge(int v,int w){
        this->v=v;this->w=w;
    }
    bool operator<(const Edge& e)const{
        return w>e.w;
    }
};
typedef Edge HeapNode;
vector< vector<Edge> >G;
ll* dis;
void dij(int s,int t){
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
    int n,m,s,l;scanf("%d%d%d%d",&n,&m,&s,&l);
    G.resize(n+1);
    memset(dis=(ll*)malloc((n+1)*sizeof(ll)),0x3f,(n+1)*sizeof(ll));
    while(m--){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
    }
    dij(s,l);
    printf("%lld\n",dis[l]);
}