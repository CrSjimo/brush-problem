#include<cstdio>
#include<cstdlib>
#include<queue>
using std::queue;
struct Node{
    int dis;
    int v;
    Node(int dis,int v){
        this->dis=dis;
        this->v=v;
    }
};
bool vis[100005];
int bfs(int s,int t){
    queue<Node> q;
    q.push(Node(0,s));
    while(!q.empty()){
        Node u=q.front();q.pop();
        if(u.v<0)continue;
        if(u.v>100000)continue;
        if(vis[u.v])continue;
        if(u.v==t){
            return u.dis;
        }
        vis[u.v]=1;
        q.push(Node(u.dis+1,u.v+1));
        q.push(Node(u.dis+1,u.v-1));
        q.push(Node(u.dis+1,2*u.v));
    }
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d\n",bfs(n,k));
    return 0;
}