#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
using std::queue;
using std::vector;
int* dis;
int* cur;
struct Edge{
    int c;
    int v;
    int rev;
    Edge(int c,int v,int rev){
        this->c=c;this->v=v;this->rev=rev;
    }
};
vector< vector<Edge> > G;
inline void addedge(int c,int u,int v){
    G[u].push_back(Edge(c,v,G[v].size()));
    G[v].push_back(Edge(0,u,G[u].size()-1));
}
void bfs(){

}