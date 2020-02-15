#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
using std::priority_queue;
using std::vector;
int n,m;
double k;
struct Edge{
    double w;
    int v;
    Edge(){}
    Edge(double w,int v){
        this->w=w;
        this->v=v;
    }
};
struct Node{
    double dis;
    int v;
    Node(double dis,int v){
        this->dis=dis;
        this->v=v;
    }
    bool operator<(const Node& nd)const{
        return dis<nd.dis;
    }
};
vector< vector<Edge> > G;
vector< vector<Edge> > RG;
vector<double> dis;
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
int cnt = 0;
void astar(int s,int t){
    priority_queue<Node,vector<Node>,cmp> q;
    q.push(Node(0,s));
    while(!q.empty()){
        Node u=q.top();q.pop();
        if(u.v == t){
            //printf("t:%lf\n",u.dis);
            if((k-=u.dis) < 0)return;
            cnt++;
            continue;
        }
        for(int i=0;i<G[u.v].size();i++){
            Edge e = G[u.v][i];
            q.push(Node(u.dis+e.w,e.v));
        }
    }
}
int main(){
    scanf("%d%d%lf",&n,&m,&k);
    G.resize(n+5);
    RG.resize(n+5);
    dis.resize(n+5);
    dis.assign(n+3,0x3f3f3f3f);
    while(m--){
        int x,y;
        double d;
        scanf("%d%d%lf",&x,&y,&d);
        G[x].push_back(Edge(d,y));
        RG[y].push_back(Edge(d,x));
    }
    dij(n);
    astar(1,n);
    printf("%d\n",cnt);
    return 0;
}