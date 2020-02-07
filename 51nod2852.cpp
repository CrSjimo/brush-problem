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
            if(dis[e.v]<dis[u]+e.dis){
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
inline void add_edge(int x,int y,int dis){
    G[x].push_back(Edge(dis,y));
}
int main(){
    scanf("%d%d",&n,&m);
    dis.resize(n+10);dis.assign(n+5,-1);
    G.resize(n+10);
    inq.resize(n+10);cnt.resize(n+10);
    while(m--){
        int k,x,y;
        scanf("%d%d%d",&k,&x,&y);
        if(k==1){
            add_edge(x,y,0);
            add_edge(y,x,0);
        }else if(k==2){
            add_edge(x,y,1);
        }else if(k==3){
            add_edge(y,x,0);
        }else if(k==4){
            add_edge(y,x,1);
        }else if(k==5){
            add_edge(x,y,0);
        }
    }
    for(int i=1;i<=n;i++){
        add_edge(0,i,1);
    }
    bool r = spfa(0);
    if(!r){
        printf("-1\n");
    }else{
        long long ans = 0;
        for(int i=1;i<=n;i++){
            //printf("t:%d\n",dis[i]);
            ans+=dis[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}