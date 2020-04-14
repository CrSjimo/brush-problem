#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
using std::vector;
#include<queue>
#include<cmath>
#include<utility>
using std::pair;
using std::make_pair;
typedef pair<double,double> pdd;
using std::priority_queue;
struct Edge{
    double w;
    int v;
    Edge(){}
    Edge(double w,int v){
        this->w=w;this->v=v;
    }
    bool operator<(const Edge& e)const{
        return w>e.w;
    }
};
vector< vector<Edge> > G;
double* dis;
int* pre;
void dijstra(int s,int t){
    priority_queue<Edge> q;
    q.push(Edge(0,s));
    dis[s]=0;
    while(!q.empty()){
        Edge tmp=q.top();q.pop();
        int u=tmp.v;
        if(u==t)return;
        if(dis[u]<tmp.w)continue;
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(dis[e.v]>dis[u]+e.w){
                dis[e.v]=dis[u]+e.w;
                pre[e.v]=u;
                q.push(Edge(dis[e.v],e.v));
            }
        }
    }
}
pdd* points;
inline double calc(pdd p1,pdd p2){
    return sqrt(pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2));
}
int main(){
    int n;scanf("%d",&n);
    points=(pdd*)malloc((n+1)*sizeof(pdd));
    memset(dis=(double*)malloc((n+1)*sizeof(double)),0x7f,(n+1)*sizeof(double));
    G.resize(n+1);
    pre=(int*)calloc(n+1,sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&points[i].first,&points[i].second);
    }
    int m;scanf("%d",&m);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        double w=calc(points[u],points[v]);
        G[u].push_back(Edge(w,v));
        G[v].push_back(Edge(w,u));
    }
    int s,t;scanf("%d%d",&s,&t);
    dijstra(s,t);
    vector<int> st;
    for(int v=t;v;v=pre[v]){
        st.push_back(v);
    }
    printf("%.2lf\n",dis[t]);
    while(st.size()>1){
        printf("%d->",st.back());st.pop_back();
    }
    printf("%d\n",st.back());
    return 0;
}