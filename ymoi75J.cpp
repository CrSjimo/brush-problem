#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<vector>
#include<queue>
using std::min_element;
using std::vector;
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
vector<Edge> G[53];
int dis[53];
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
inline int hash(char s){
    return islower(s)?s-'a'+1:s-'A'+27;
}
inline char unhash(int k){
    return k<27?'a'+k-1:'A'+k-27;
}
int main(){
    memset(dis,0x3f,sizeof(dis));
    int m;scanf("%d",&m);
    while(m--){
        char us[4],vs[4];
        int k;
        scanf("%s%s%d",us,vs,&k);
        int u=hash(*us),v=hash(*vs);
        G[u].push_back(Edge(k,v));
        G[v].push_back(Edge(k,u));
    }
    dijstra(52);
    int* minptr=min_element(dis+27,dis+52);
    printf("%c %d\n",unhash(minptr-dis),*minptr);
    return 0;
}