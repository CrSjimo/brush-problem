#include<cstdio>
#include<vector>
#include<queue>
using std::vector;
using std::priority_queue;
struct Edge{
    int dis;
    int v;
    Edge(){}
    Edge(int dis,int v){
        this->dis=dis;this->v=v;
    }
    bool operator<(const Edge& e)const{
        return dis<e.dis;
    }
};
vector<int> dis;
vector< vector<Edge> > G;
vector<bool> inq;
vector<int> cnt;
int n,m;
bool spfa(int s){
    priority_queue<Edge> q;
    q.push(Edge(0,s));
    dis[s]=0;inq[s]=true;
    while(!q.empty()){
        Edge tmp = q.top();q.pop();
        int u = tmp.v;
        inq[u] = false;
        for(int i=0;i<G[u].size();i++){
            Edge& e = G[u][i];
            if(dis[e.v]>dis[u]+e.dis){
                dis[e.v]=dis[u]+e.dis;
                if(!inq[e.v]){
                    inq[e.v]=true;
                    q.push(Edge(dis[e.v],e.v));
                    cnt[e.v]++;
                    if(cnt[e.v]>n)return false;
                }
            }
        }
    }
    return true;
}
std::vector<char> vis;
bool r = true;
bool dfs(int u){
    vis[u]=true;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].v;
        if(!vis[v])dis[v]=dis[u]+G[u][i].dis,dfs(v);
        else if(dis[v]!=dis[u]+G[u][i].dis)r=false;
    }
}
inline void add_edge(int x,int y,int dis){
    G[x].push_back(Edge(dis,y));
}
int a,b;
int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d%d",&a,&b,&m);
        n=a+b;
        dis.resize(n+10);dis.assign(n+5,0);
        G.resize(n+10);G.assign(n+5,std::vector<Edge>());
        inq.resize(n+10);cnt.resize(n+10);
        inq.assign(n+5,false);cnt.resize(n+5,0);
        vis.resize(n+10);vis.assign(n+5,0);
        while(m--){
            int k,x,y;
            scanf("%d%d%d",&x,&y,&k);
            add_edge(x,y+a,k);add_edge(y+a,x,-k);
        }
        for(int i=1;i<=n;i++){
            add_edge(0,i,0);
        }
        for(int i=0;i<=n;i++){
            if(!vis[i])dfs(i);
        }
        if(!r){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }
    
    return 0;
}