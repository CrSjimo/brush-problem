#include<cstdio>
#include<cstdlib>
#include<queue>
using std::queue;
int* a;
bool* vis;
struct Node{
    int v;
    int dis;
    Node(int dis,int v){
        this->dis = dis;
        this->v = v;
    }
};
int n;
int bfs(int s,int t){
    queue<Node> q;
    q.push(Node(0,s));
    while(!q.empty()){
        Node e = q.front();q.pop();
        int u = e.v;
        vis[u]=1;
        if(u == t)return e.dis;
        int v;
        v = u + a[u];
        if(!vis[v]&&v>=1&&v<=n){
            q.push(Node(e.dis+1,v));
        }
        v = u - a[u];
        if(!vis[v]&&v>=1&&v<=n){
            q.push(Node(e.dis+1,v));
        }
    }
    return -1;
}
int main(){
    int s,t;
    scanf("%d%d%d",&n,&s,&t);
    a = (int*)malloc((n+1)*sizeof(int));
    vis = (bool*)malloc((n+1)*sizeof(bool));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    printf("%d\n",bfs(s,t));
    return 0;
}