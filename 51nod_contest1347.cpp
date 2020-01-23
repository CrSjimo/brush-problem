#include<stdio.h>
#include<vector>
#include<queue>
#include<utility>
struct Edge{
    int dis;
    int v;
    Edge(){}
    Edge(int dis,int v){
        this->dis = dis;
        this->v = v;
    }
    bool operator<(const Edge& e)const{
        return dis>e.dis;
    }
};
//std::vector< std::vector<Edge> > G;
std::vector<int> dis;
std::vector<Edge> cd;
inline int get_dis(Edge& p1,Edge& p2){
    int a=p1.dis-p2.dis,b=p1.v-p2.v;
    a=a>0?a:-a;b=b>0?b:-b;
    return a<b?a:b;
}
int n;
void dijstra(int s,int t){
    std::priority_queue<Edge> q;
    q.push(Edge(0,s));
    dis[s] = 0;
    while(!q.empty()){
        Edge tmp = q.top();q.pop();
        int u=tmp.v;
        if(u==t)return;
        if(dis[u]<tmp.dis)continue;
        for(int i = 1;i<=n;i++){
            if(i==u)continue;
            Edge e = Edge(get_dis(cd[u],cd[i]),i);
            if(dis[e.v]>dis[tmp.v]+e.dis){
                dis[e.v]=dis[tmp.v]+e.dis;
                e.dis = dis[e.v];
                q.push(e);
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    cd.resize(n+5);
    //G.resize(n+5);
    dis = std::vector<int>(n+5,0x3f3f3f3f);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&cd[i].dis,&cd[i].v);
    }
    int basis_dis = dis[n] = get_dis(cd[1],cd[n]);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<i;j++){
    //         int dis = get_dis(cd[j],cd[i]);
    //         if(dis>=basis_dis)continue;
    //         G[j].push_back(Edge(dis,i));
    //         G[i].push_back(Edge(dis,j));
    //     }
    // }
    dijstra(1,n);
    printf("%d\n",dis[n]);
    return 0;
}