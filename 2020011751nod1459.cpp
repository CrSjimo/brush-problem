#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
struct Edge{
    int dis;
    int v;
    Edge(){}
    Edge(int dis,int v){
        this->dis=dis;this->v=v;
    }
};
bool operator<(const Edge& e1,const Edge& e2){
    return e1.dis<e2.dis;
}
std::vector< std::vector<Edge> > G;
std::vector<int> dis;
std::vector<int> bounds;
std::vector<int> anses;
void dij(int s,int t){
    std::priority_queue<Edge> q;
    dis[s]=0;anses[s]=bounds[s];
    q.push(Edge(0,s));
    while(!q.empty()){
        Edge tmp = q.top();q.pop();
        int u = tmp.v;
        //if(u==t)return;
        if(dis[u]<tmp.dis)continue;
        for(int i=0;i<G[u].size();i++){
            Edge e = G[u][i];
            if(dis[e.v]>dis[u]+e.dis){
				dis[e.v]=dis[u]+e.dis;
				e.dis = dis[e.v];
                anses[e.v]=anses[u]+bounds[e.v];
				q.push(e);
			}else if(dis[e.v]==dis[u]+e.dis && anses[e.v]<anses[u]+bounds[e.v]){
                anses[e.v]=anses[u]+bounds[e.v];
                e.dis = dis[e.v];
                q.push(e);
            }
        }
    }
}
int main(){
    int n,m,s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    G.resize(n+5);
    bounds.resize(n+5);
    dis=std::vector<int>(n+5,0x3f3f3f3f);
    anses.resize(n+5);
    for(int i=0;i<n;i++){
        scanf("%d",&bounds[i]);
    }
    for(int i=0;i<m;i++){
        int x,y,d;
        scanf("%d%d%d",&x,&y,&d);
        G[x].push_back(Edge(d,y));
        G[y].push_back(Edge(d,x));
    }
    dij(s,t);
    printf("%d %d\n",dis[t],anses[t]);
    return 0;

}