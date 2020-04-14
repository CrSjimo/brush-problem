#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
using std::vector;
using std::min;
#include<queue>
using std::priority_queue;
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
vector< vector<Edge> > G;
int* dis;
int* cows;
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
    int c,n,m;
    scanf("%d%d%d",&c,&n,&m);
    cows=(int*)calloc(n+1,sizeof(int));
    dis=(int*)malloc((n+1)*sizeof(int));
    G.resize(n+1);
    while(c--){
        int k;scanf("%d",&k);
        cows[k]++;
    }
    while(m--){
        int x,y,k;
        scanf("%d%d%d",&x,&y,&k);
        G[x].push_back(Edge(k,y));
        G[y].push_back(Edge(k,x));
    }

    int minn=19260817;
    for(int i=1;i<=n;i++){
        memset(dis,0x3f,(n+1)*sizeof(int));
        dijstra(i);
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=dis[i]*cows[i];
        }
        minn=min(sum,minn);
    }
    printf("%d\n",minn);
    return 0;
}