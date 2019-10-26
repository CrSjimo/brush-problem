#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
#define MAXN 10010
typedef struct Edge{
    int nextId;
    int dist;
    bool operator < (const Edge& e) const{
        return e.dist<dist;
    }
};
typedef std::priority_queue<Edge> Queue;
bool visited[MAXN];
std::vector<Edge> graph[MAXN];
int list[MAXN];
int edge[MAXN][MAXN];
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
struct ball{
    int x,y,z;
    ball(int a,int b,int c){
        x=a,y=b,z=c;
    }
    ball(){}
}balls[1010];
int n,h,r;
#include<math.h>
inline double dist(ball& a,ball& b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));
}
void check(int aid,int bid){
    ball& a = balls[aid];
    ball& b = balls[bid];
    if(dist(a,b)<=2*r){
        Edge e;
        e.dist = 0;
        e.nextId = bid;
        graph[aid].push_back(e);
        e.nextId = aid;
        graph[bid].push_back(e);
    }
}
bool canstart(int aid){
    ball& a = balls[aid];
    return a.z-r<=0;
}
bool canend(int aid){
    ball& a = balls[aid];
    return a.z+r>=h;
}
std::vector<int> starts;
std::vector<int> ends;
int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d%d",&n,&h,&r);
        for(int i = 0;i<n;i++){
            graph[i].clear();
        }
        starts.clear();
        ends.clear();
        for(int i = 0;i<n;i++){
            scanf("%d%d%d",&balls[i].x,&balls[i].y,&balls[i].z);
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                check(i,j);
            }
        }
        for(int i = 0;i<n;i++){
            bool stOk = canstart(i);
            bool edOk = canend(i);
            if(stOk&&edOk){
                printf("Yes\n");
                goto Next;
            }
            if(stOk){
                starts.push_back(i);
            }
            if(edOk){
                ends.push_back(i);
            }
        }
        for(int i = 0;i<starts.size();i++){
            for(int j = 0;j<ends.size();j++){
                memset(list,0x3f,sizeof(list));
                memset(visited,0,sizeof(visited));
                bfs(starts[i],ends[j]);
                if(visited[ends[j]]){
                    printf("Yes\n");
                    goto Next;
                }
            }
        }
        printf("No\n");
        Next:;
    }
    return 0;
}