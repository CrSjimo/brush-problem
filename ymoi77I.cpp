#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<queue>
#include<utility>
#include<cmath>
using std::make_pair;
typedef std::pair<double,double> PT;
using std::vector;
using std::priority_queue;
struct Edge{
    double w;int v;
    bool operator<(const Edge& e)const{
        return w>e.w;
    }
    Edge(double w,int v){
        this->w=w;
        this->v=v;
    }
};
int n;
vector< vector<Edge> >G;
double* dis;
bool* vis;
vector<PT> p;
inline double calc(PT& p1,PT& p2){
    return sqrt(pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2));
}
double prim(int s){
    double ans=0;
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
        for(int v=1;v<=n;v++){
            double w;
            if(!vis[v]&&dis[v]>(w=calc(p[u],p[v]))){
                dis[v]=w;
                q.push(Edge(w,v));
            }
        }
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    G.resize(n+1);
    p.resize(n+1);
    memset(dis=(double*)malloc((n+1)*sizeof(double)),0x7f,(n+1)*sizeof(double));
    vis=(bool*)calloc((n+1),sizeof(bool));
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&p[i].first,&p[i].second);
    }
    printf("%.2lf\n",prim(1));
    return 0;
}