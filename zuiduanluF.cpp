#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
#define MAXN 2080
typedef struct Edge{
    int nextId;
    int dist;
    bool operator < (const Edge& e) const{
        return e.dist<dist;
    }
};
typedef std::priority_queue<Edge> Queue;
// bool visited[MAXN];
std::vector<Edge> graph[MAXN];
int list[MAXN];
int edge[MAXN][MAXN];
int n,m;
int ans;
void bfs(int st,int ed){
    Queue q;
    Edge tmp,next;
    tmp.nextId = st;
    tmp.dist = 0;
    // visited[st] = 1;
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
                
                e.nextId = nextEdge.nextId;
                e.dist = list[nextEdge.nextId];
                q.push(e);
            }
        }
    }
}
int main(){
    while(~scanf("%d%d",&m,&n)){
        memset(list,0x3f,sizeof(list));
        // memset(visited,0,sizeof(visited));
        for(int i = 0;i<n;i++){
            graph[i].clear();
        }
        for(int i = 0;i<m;i++){
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            Edge e;
            e.dist = k;
            e.nextId = y;
            graph[x].push_back(e);
            e.nextId = x;
            graph[y].push_back(e);
        }
        //int start,end;
        //scanf("%d%d",&start,&end);
        bfs(1,n);
        printf("%d\n",list[n]);
    }
    return 0;
}