#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using std::sort;
using std::min;
using std::priority_queue;
using std::vector;
typedef long long ll;
struct Edge{
    int v;
    ll w;
    Edge(){}
    Edge(int v,ll w){
        this->v=v;this->w=w;
    }
    bool operator<(const Edge& e)const{
        return w>e.w;
    }

};
struct Edge2{
    int u, v, w;
    Edge2(){}
    Edge2(int u,int v,int w){
        if(u>v)u^=v^=u^=v;
        this->u=u;
        this->v=v;
        this->w=w;
    }
    bool operator<(const Edge2& e)const{
        if(u==e.u){
            if(v==e.v)return w<e.w;
            return v<e.v;
        }
        return u<e.u;
    }
    bool operator==(const Edge2& e)const{
        return u==e.u&&v==e.v&&w==e.w;
    }
}*G1li,*G2li;
typedef Edge Node;
vector< vector<Edge> >G1;
vector< vector<Edge> >G2;
ll* dis1;
ll* dis2;
void dij(vector< vector<Edge> >& G,ll* dis,int s){
    priority_queue<Node> q;
    dis[s]=0;
    q.push(Node(s,0));
    while(!q.empty()){
        Node tmp = q.top();q.pop();
        int u=tmp.v;
        if(tmp.w>dis[u])continue;
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(dis[e.v]>dis[u]+e.w){
                dis[e.v]=dis[u]+e.w;
                q.push(Node(e.v,dis[e.v]));
            }
        }
    }
}
template<typename T>T*&alloc(T*&a,size_t siz){
    return a=(T*)malloc(siz*sizeof(T));
}
template<typename T>T*&alloc(T*&a,size_t siz,int c){
    return memset(a=(T*)malloc(siz*sizeof(T)),c,siz*sizeof(T)),a;
}
template<typename T>vector<T>&alloc(vector<T>&a,size_t siz){
    return a.resize(siz),a;
}
int main(){
    freopen("late.in","r",stdin);
    freopen("late.out","w",stdout);
    int n,m1,m2;scanf("%d%d%d",&n,&m1,&m2);
    bool op1=true;
    alloc(G1,n+1);
    alloc(G2,n+1);
    alloc(dis1,n+1,0x3f);
    alloc(dis2,n+1,0x3f);
    alloc(G1li,m1+1);
    alloc(G2li,m2+1);
    for(int i=1;i<=m1;i++){
        int u,v;ll w;scanf("%d%d%lld",&u,&v,&w);
        G1[u].push_back(Edge(v,w));
        G1[v].push_back(Edge(u,w));
        G1li[i]=Edge2(u,v,w);
    }
    for(int i=1;i<=m2;i++){
        int u,v;ll w;scanf("%d%d%lld",&u,&v,&w);
        G2[u].push_back(Edge(v,w));
        G2[v].push_back(Edge(u,w));
        G2li[i]=Edge2(u,v,w);
    }
    if(m1!=m2)op1=false;
    else{
        sort(G1li+1,G1li+m1+1);
        sort(G2li+1,G2li+m2+1);
        for(int i=1;i<=m1;i++){
            if(!(G1li[i]==G2li[i])){
                op1=false;
                break;
            }
        }
    }
    if(!op1)dij(G1,dis1,1);
    dij(G2,dis2,n);
    int q;scanf("%d",&q);
    while(q--){
        double v;scanf("%lf",&v);
        if(op1){
            printf("%.1lf\n",1.0*dis2[1]/v);
            continue;
        }
        double ans = 1e18;
        for(int i=1;i<=n;i++){
            ans=min(ans,1.0*dis1[i]+1.0*dis2[i]/v);
        }
        printf("%.1lf\n",ans);
    }
    return 0;
}