#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<cstring>
using std::queue;
using std::vector;
using std::min;
typedef long long ll;
int* dis;
int* cur;
int n;
const int INF=0x3f3f3f3f;
struct Edge{
    ll c;
    int v;
    int rev;
    Edge(int c,int v,int rev){
        this->c=c;this->v=v;this->rev=rev;
    }
};
vector< vector<Edge> > G;
inline void addedge(ll c,int u,int v){
    G[u].push_back(Edge(c,v,G[v].size()));
    G[v].push_back(Edge(0,u,G[u].size()-1));
}
bool bfs(int s,int t){
    memset(dis,-1,(n+1)*sizeof(int));
    queue<int> q;
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i].v;
            if(dis[v]!=-1||G[u][i].c<=0)continue;
            dis[v]=dis[u]+1;
            q.push(v);
            if(v==t)return true;
        }
    }
    return dis[t]!=-1;
}
ll dfs(int u,int t,ll a){
    if(u==t||a==0){
        return a;
    }
    ll flow = 0;
    for(int& i=cur[u];i<G[u].size();i++){
        Edge& e=G[u][i];
        ll f;
        if(dis[e.v]==dis[u]+1 && (f=dfs(e.v,t,min(e.c,a)))>0){
            flow+=f;a-=f;
            e.c-=f;G[e.v][e.rev].c+=f;
            if(a==0)break;
        }
    }
    return flow;
}
ll dinic(int s,int t){
    ll flow=0;
    while(bfs(s,t)){
        for(int i=1;i<=n;i++){
            cur[i]=0;
        }
        flow+=dfs(s,t,INF);
    }
    return flow;
}
void init(){
    G.resize(n+1);
    cur=(int*)malloc((n+1)*sizeof(int));
    dis=(int*)malloc((n+1)*sizeof(int));
}
int main(){
    int m;
    scanf("%d%d",&n,&m);
    int S=n+1;
    int T=n+2;
    n+=2;
    init();
    for(int i=1;i<=n-2;i++){
        int k;scanf("%d",&k);
        if(k==1){
            addedge(1,S,i);
        }else{
            addedge(1,i,T);
        }
    }
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        addedge(1,u,v);
        addedge(1,v,u);
    }
    // for(int u=1;u<=n;u++){
    //     printf("%d: ",u);
    //     for(int i=0;i<G[u].size();i++){
    //         int v=G[u][i].v;
    //         printf("%d ",v);
    //     }
    //     printf("\n");
    // }
    printf("%lld\n",dinic(S,T));
    return 0;
}