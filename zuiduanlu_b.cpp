#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
#define MAXN 10010
// #define DEBUG_MODE
typedef struct Edge{
    int nextId;
    int dist;
    bool operator < (const Edge& e) const{
        return e.dist<dist;
    }
};
char pname[MAXN][40];
int indexOf(char* str,int& len){
    for(int i = 0;i<len;i++){
        if(!strcmp(pname[i],str))return i;
    }
    strcpy(pname[len++],str);
    return len-1;
}
typedef std::priority_queue<Edge> Queue;
bool visited[MAXN];
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
int main(){
    while(~scanf("%d",&m) && ~m){
        n = 0;
        memset(list,0x3f,sizeof(list));
        memset(visited,0,sizeof(visited));
        int start,end;
        char startname[40],endname[40];
        scanf("%s%s",startname,endname);
        start=indexOf(startname,n);
        end = indexOf(endname,n);
        #ifdef DEBUG_MODE
        printf("%d %d\n",start,end);
        #endif
        for(int i = 0;i<200;i++){
            graph[i].clear();
        }
        for(int i = 0;i<m;i++){
            int x,y,k;
            char xn[40],yn[40];
            scanf("%s%s%d",xn,yn,&k);
            x = indexOf(xn,n);
            y = indexOf(yn,n);
            #ifdef DEBUG_MODE
            printf("%d %d %d\n",x,y,k);
            #endif
            Edge e;
            e.dist = k;
            e.nextId = y;
            graph[x].push_back(e);
            e.nextId = x;
            graph[y].push_back(e);
        }
        // for(int i = 0;i<n;i++){
        //     printf("%d\n",indexOf(pname[i],n));
        // }
        bfs(start,end);
        printf("%d\n",(visited[end])?list[end]:-1);
    }
    return 0;
}