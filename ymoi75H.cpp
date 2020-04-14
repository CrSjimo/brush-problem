#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
using std::queue;
using std::vector;
int* dis;
bool* inq;
int* cnt;
struct Edge{
    int dis,v;
    Edge(){}
    Edge(int dis,int v){
        this->dis=dis;
        this->v=v;
    }
};
int n,m,s,l;
vector< vector<Edge> > G;
bool spfa(int s,int t){
    queue<Edge> q;
    q.push(Edge(0,s));
    inq[s]=1;
    dis[s]=0;
    while(!q.empty()){
        Edge tmp = q.front();q.pop();
        int u=tmp.v;
        inq[u]=false;
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(dis[e.v]>dis[u]+e.dis){
                dis[e.v]=dis[u]+e.dis;
                if(!inq[e.v]){
                    if(++cnt[e.v]>n)return false;;
                    inq[e.v]=true;
                    q.push(Edge(dis[e.v],e.v));
                }
            }
        }
    }
    return true;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&l);
    memset(dis=(int*)malloc((n+1)*sizeof(int)),0x3f,(n+1)*sizeof(int));
    inq=(bool*)calloc((n+1),sizeof(bool));
    cnt=(int*)calloc(n+1,sizeof(int));
    G.resize(n+1);
    while(m--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(Edge(w,v));
        G[v].push_back(Edge(w,u));
    }
    spfa(s,l);
    printf("%d\n",dis[l]);
    return 0;
}