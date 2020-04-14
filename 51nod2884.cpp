#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<cstring>
using std::priority_queue;
using std::queue;
using std::vector;
using std::min;

//#define int long long
typedef long long ll;
struct Edge{
    ll w;
    int v;
    bool flag;
    int id;
    Edge(){}
    Edge(ll w,int v){
        this->w=w;
        this->v=v;
    }
    Edge(ll w,int v,int id){
        this->w=w;
        this->v=v;
        this->id=id;
    }
    bool operator<(const Edge& e)const{
        return e.w>w;
    }
};
vector< vector<Edge> > G;
ll* dis;
int n,m,k;
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
int* pre;
void solve(){
    for(int u=1;u<=n;u++){
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(dis[u]+e.w == dis[e.v]&&!pre[e.v]){
                e.flag = true;
                pre[e.v]=e.id;
            }
        }
    }
}
void bfs(){
    queue<int> q;
    q.push(1);
    int cnt=0;
    while(!q.empty()&&cnt<k){
        int u=q.front();q.pop();
        if(u!=1){
            printf("%d ",pre[u]);
            cnt++;
        }
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(e.flag){
                q.push(e.v);
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    pre=(int*)calloc((n+1),sizeof(int));
    memset(dis=(ll*)malloc((n+1)*sizeof(ll)),0x7f,(n+1)*sizeof(ll));
    G.resize(n+1);
    for(int i=1;i<=m;i++){
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        G[u].push_back(Edge(w,v,i));
        G[v].push_back(Edge(w,u,i));
    }
    printf("%d\n",min(n-1,k));
    dijstra(1);
    solve();
    bfs();
    return 0;
}
