#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<queue>
using std::vector;
using std::priority_queue;
struct Edge{
    int w,v;
    bool operator<(const Edge& e)const{
        return w>e.w;
    }
    Edge(int w,int v){
        this->w=w;
        this->v=v;
    }
};
int n,m;
vector< vector<Edge> >G;
int* dis;
bool* vis;
int prim(int s){
    int ans=0;
    priority_queue<Edge> q;
    dis[s]=0;
    int cnt=0;
    q.push(Edge(0,s));
    while(!q.empty()&&cnt<n){
        Edge tmp=q.top();q.pop();
        int u=tmp.v;
        if(vis[u])continue;
        vis[u]=true;
        ans+=tmp.w;cnt++;
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(!vis[e.v]&&dis[e.v]>e.w){
                dis[e.v]=e.w;
                q.push(Edge(dis[e.v],e.v));
            }
        }
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    G.resize(n+1);
    memset(dis=(int*)malloc((n+1)*sizeof(int)),0x3f,(n+1)*sizeof(int));
    vis=(bool*)calloc((n+1),sizeof(bool));
    while(m--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(Edge(w,v));
        G[v].push_back(Edge(w,u));
    }
    printf("%d\n",prim(1));
    return 0;
}