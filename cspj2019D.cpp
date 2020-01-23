#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
typedef struct Edge{
    int nextId;
    int dist;
    bool operator < (const Edge& e) const{
        return e.dist<dist;
    }
};
typedef std::queue<Edge> Queue;
std::vector< std::vector<Edge> > graph;
std::vector<int> list[2];
std::vector<bool> cando[2];
int n,m,q;
int ans;
void bfs(int st){
    Queue q;
    Edge tmp,next;
    tmp.nextId = st;
    tmp.dist = 0;
    cando[0][st]=true;
    list[0][st]=0;
    q.push(tmp);
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        int u=tmp.nextId;
        int d=tmp.dist;
        for(int i = 0;i<graph[u].size();i++){
            Edge nextEdge = graph[u][i];
            if(!cando[(d+1)&1][nextEdge.nextId]){
                cando[(d+1)&1][nextEdge.nextId]=1;
                list[(d+1)&1][nextEdge.nextId]=d+1;
                Edge e;
                e.nextId=graph[u][i].nextId;
                e.dist=d+1;
                q.push(e);
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    graph.resize(n+5);
    list[0]=std::vector<int>(n+5,0x3f3f3f3f);
    list[1]=std::vector<int>(n+5,0x3f3f3f3f);
    cando[0].resize(n+5);
    cando[1].resize(n+5);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        Edge e;
        e.dist = 1;
        e.nextId = y;
        graph[x].push_back(e);
        e.nextId = x;
        graph[y].push_back(e);
    }
    bfs(1);
    if(graph[1].size()==0){
        while(q--){
            int tmp;scanf("%d%d",&tmp,&tmp);
            printf("No\n");
        }
    }else{
        while(q--){
            int k,l;
            scanf("%d%d",&k,&l);
            if(cando[l&1][k]&&l>=list[l&1][k]){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }
    return 0;
}