#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
using std::priority_queue;
using std::vector;
int n,m,k;
struct Edge{
    int w,v;
    Edge(){}
    Edge(int w,int v){
        this->w=w;
        this->v=v;
    }
};
struct Node{
    int dis,v;
    Node(int dis,int v){
        this->dis=dis;
        this->v=v;
    }
    bool operator<(const Node& nd)const{
        return dis<nd.dis;
    }
};
vector< vector<Edge> > G;
vector< vector<Edge> > RG;
vector<int> dis;
void dij(int s){
    priority_queue<Node> q;
    dis[s]=0;
    q.push(Node(0,s));
    while(!q.empty()){
        Node u=q.top();q.pop();
        if(u.dis>dis[u.v])continue;
        for(int i=0;i<RG[u.v].size();i++){
            Edge e = RG[u.v][i];
            int v=e.v;
            if(dis[v]>dis[u.v]+e.w){
                dis[v]=dis[u.v]+e.w;
                q.push(Node(u.dis+1,v));
            }
        }
    }
}
struct cmp{
    bool operator()(const Node& nd1,const Node& nd2){
        return nd1.dis+dis[nd1.v]>nd2.dis+dis[nd2.v];
    }
};
vector<int> pathD;
void astar(int s,int t){
    priority_queue<Node,vector<Node>,cmp> q;
    q.push(Node(0,s));
    while(!q.empty()){
        Node u=q.top();q.pop();
        if(u.v == t){
            pathD.push_back(u.dis);
            if(pathD.size()>100)return;
        }
        for(int i=0;i<G[u.v].size();i++){
            Edge e = G[u.v][i];
            q.push(Node(u.dis+e.w,e.v));
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    G.resize(n+5);
    RG.resize(n+5);
    dis.resize(n+5);
    dis.assign(n+3,0x3f3f3f3f);
    while(m--){
        int x,y,d;
        scanf("%d%d%d",&x,&y,&d);
        if(x>y){
            G[x].push_back(Edge(d,y));
            RG[y].push_back(Edge(d,x));
        }else{
            RG[x].push_back(Edge(d,y));
            G[y].push_back(Edge(d,x));
        }
    }
    dij(1);
    astar(n,1);
    for(int i=1;i<=k;i++){
        if(i>pathD.size()){
            printf("-1\n");
        }else{
            printf("%d\n",pathD[i-1]);
        }
    }
    return 0;
}