#include<stdio.h>
#include<string.h>
#include<utility>
#include<algorithm>
#include<queue>
struct Edge{
    int dist;
    int nextId;
    bool operator < (const Edge& e) const{
        return e.dist<dist;
    }
};
#define MAXN 1<<17
std::vector<Edge> map[MAXN];
struct Node{
    int dist;
    int next;
};
typedef std::queue<Node> Queue;
int n;
long long ago = 0;
void bfs(int maxdist){
    Node tmp;
    tmp.dist = 0;
    tmp.next = 1;
    Queue q;
    q.push(tmp);
    while(!q.empty()){
        Node t = q.front();
        q.pop();
        if(t.dist>maxdist)return;
        if(t.next == n){
            ago++;
        }
        int next = t.next;
        for(int i = 0;i<map[next].size();i++){
            Node nxt;
            nxt.dist = t.dist+map[next][i].dist;
            nxt.next = map[next][i].nextId;
            q.push(nxt);
        }
    }
}
namespace zdl{
    typedef std::priority_queue<Edge> Queue;
    bool visited[MAXN];
    #define graph map
    int list[MAXN];
    // int n,m;
    int ans;
    void bfs(int st,int ed){
        Queue q;
        Edge tmp,next;
        tmp.nextId = st;
        tmp.dist = 0;
        visited[st] = 1;
        list[st] = 0;
        q.push(tmp);
        while(!q.empty()){
            tmp = q.top();
            q.pop();
            int nextId=tmp.nextId;
            if(list[nextId]<tmp.dist){
                continue;
            }
            if(nextId == ed){
                return;
            }
            for(int i = 0;i<graph[nextId].size();i++){
                Edge nextEdge = graph[nextId][i];
                if(list[nextEdge.nextId] > list[nextId]+nextEdge.dist){
                    list[nextEdge.nextId] = list[nextId]+nextEdge.dist;
                    Edge e;
                    visited[nextEdge.nextId] = 1;
                    e.nextId = nextEdge.nextId;
                    e.dist = list[nextEdge.nextId];
                    q.push(e);
                }
            }
        }
    }
}
int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        int m,k,p;
        scanf("%d%d%d%d",&n,&m,&k,&p);
        for(int i = 0;i<n+10;i++){
            map[i].clear();
        }
        memset(zdl::list,0x3f,sizeof(zdl::list));
        memset(zdl::visited,0,sizeof(zdl::visited));
        for(int i = 0;i<m;i++){
            int x,y,d;
            scanf("%d%d%d",&x,&y,&d);
            Edge e;
            e.nextId = y;
            e.dist = d;
            map[x].push_back(e);
            e.nextId = x;
            map[x].push_back(e);
        }
        zdl::bfs(1,n);
        int dd = zdl::list[n];
        bfs(dd+k);
        printf("%lld\n",ago%p);
    }
    return 0;
}