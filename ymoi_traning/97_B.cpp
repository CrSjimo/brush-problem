#include<cstdio>
#include<cstdlib>
#include<queue>
using std::queue;
#include<vector>
using std::vector;
struct Edge{
    int v,w;
    Edge(){}
    Edge(int v,int w){
        this->v=v;
        this->w=w;
    }
};
vector< vector<Edge> >G;
double* dis;
bool* inq;
int* cnt;
int n;
bool spfa(int s,double delta){
    queue<int> q;
    q.push(s);
    dis[s]=0;
    inq[s]=true;
    while(!q.empty()){
        int u=q.front();q.pop();
        inq[u]=false;
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(dis[e.v]>dis[u]+(e.w-delta)){
                dis[e.v]=dis[u]+(e.w-delta);
                if(!inq[e.v]){
                    q.push(e.v);
                    cnt[e.v]++;
                    inq[e.v]=true;
                    if(cnt[e.v]>n){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
double binary(double l,double r){
    double mid=(l+r)/2;
}
int main(){
    int m;scanf("%d%d",&n,&m);
}