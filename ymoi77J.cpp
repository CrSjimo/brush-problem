#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using std::sort;
using std::vector;
using std::priority_queue;
double dis[420];
struct Edge{
    double w;
    int v;
    Edge(double w,int v){
        this->w=w;
        this->v=v;
    }
    bool operator<(const Edge& e)const{
        return w>e.w;
    }
};
vector<Edge> G[420];
struct P{
    double x,y;
    int id;
    P(){}
    P(double x,double y,int id){
        this->x=x;
        this->y=y;
        this->id=id;
    }
    double operator-(const P& p)const{
        return sqrt(pow(x-p.x,2)+pow(y-p.y,2));
    }
};
void dij(int s,int t){
    priority_queue<Edge> q;
    q.push(Edge(0,s));
    dis[s]=0;
    while(!q.empty()){
        Edge tmp=q.top();q.pop();
        int u=tmp.v;
        if(u==t)return;
        if(tmp.w>dis[u])continue;
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(dis[e.v]>dis[u]+e.w){
                dis[e.v]=dis[u]+e.w;
                q.push(Edge(dis[e.v],e.v));
            }
        }
    }
}
P a[420][4];
int cost[420];
int n,q,sa,ta;
void preprod(){
    for(int i=1;i<=n;i++){
        vector<Edge> tmp;
        P& A = a[i][0];
        P& B = a[i][1];
        P& C = a[i][2];
        P& D = a[i][3];
        tmp.push_back(Edge(A-B,0));
        tmp.push_back(Edge(B-C,1));
        tmp.push_back(Edge(C-A,2));
        sort(tmp.begin(),tmp.end());
        if(tmp[0].v==0){//AB
            D.x = A.x+B.x-C.x;
            D.y = A.y+B.y-C.y;
        }else if(tmp[0].v==1){//BC
            D.x = B.x+C.x-A.x;
            D.y = B.y+C.y-A.y;
        }else if(tmp[0].v==2){//AC
            D.x = A.x-B.x+C.x;
            D.y = A.y-B.y+C.y;
        }
        //printf("test: %d %lf %lf\n",i,D.x,D.y);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<4;j++){
            for(int k=j+1;k<4;k++){
                int u=i*4+j;
                int v=i*4+k;
                double w=a[i][j]-a[i][k];
                G[u].push_back(Edge(w*cost[i],v));
                G[v].push_back(Edge(w*cost[i],u));
            }
        }
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            for(int k=0;k<4;k++){
                for(int l=0;l<4;l++){
                    int u=i*4+k;
                    int v=j*4+l;
                    double w=a[i][k]-a[j][l];
                    G[u].push_back(Edge(w*q,v));
                    G[v].push_back(Edge(w*q,u));
                }
            }
        }
    }
}
void init(){
    for(int i=0;i<n*4+10;i++){
        dis[i]=0x3f3f3f3f;
        G[i].clear();
    }
}
int main(){
    int cas;scanf("%d",&cas);
    while(cas--){
        scanf("%d%d%d%d",&n,&q,&sa,&ta);
        init();
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                scanf("%lf%lf",&a[i][j].x,&a[i][j].y);
            }
            scanf("%d",&cost[i]);
        }
        preprod();
        int s=1,t=2;
        for(int i=0;i<4;i++){
            G[s].push_back(Edge(0,sa*4+i));
            G[ta*4+i].push_back(Edge(0,t));
        }
        dij(s,t);
        printf("%.2lf\n",dis[t]);
    }
    return 0;
}