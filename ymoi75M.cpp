#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using std::priority_queue;
using std::vector;
using std::max_element;
int* dis;
struct Edge{
    int w,v;
    Edge(){}
    Edge(int w,int v){
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
int main(){
    scanf("%d%d",&n,&m);
    memset(dis=(int*)malloc((n+1)*sizeof(int)),0x3f,(n+1)*sizeof(int));
    G.resize(n+1);
    for(int u=1;u<=n;u++){
        for(int v=1;v<=n;v++){
            int w;scanf("%d",&w);
            if(w){
                G[u].push_back(Edge(w,v));
                G[v].push_back(Edge(w,u));
            }
        }
    }
    dijstra(m);
    for(int i=1;i<=n;i++){
        if(i==m)continue;
        printf("%d\n",dis[i]==0x3f3f3f3f?0:dis[i]);
    }
    return 0;
}