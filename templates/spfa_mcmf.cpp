#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
using std::vector;
using std::queue;
struct Edge{
    int u;
    int w;
    int v;
    int rev;
    Edge(){}
    Edge(int w,int v,int rev,int u){
        this->w=w;
        this->v=v;
        this->rev=rev;
        this->u=u;
    }
};
vector< vector<Edge> >G;
Edge** pre;
int* dis;
bool* inq;
int* cnt;
int n,s,t;
bool spfa(){
    queue<int> q;
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        inq[u]=false;
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(dis[e.v]>dis[u]+e.w){
                dis[e.v]=dis[u]+e.w;
                pre[e.v]=&e;
                if(!inq[e.v]){
                    q.push(e.v);
                    inq[e.v]=true;
                    if(++cnt[e.v]>n)return false;
                }
            }
        }
    }
    return true;
}
const int INF = 0x7f7f7f7f;
void mcmf(){
    while(spfa()){
        int minf = INF;
    }
}