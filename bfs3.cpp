#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define MAXN 100000
bool visited[100010];
struct Node{
    int x;
    int dist;
};
typedef queue<Node> Queue;
void addNode(Queue &q,Node n){
    if(n.x>=0 && n.x<=MAXN && !visited[n.x]){
        //printf("test:%d\n",n.x);
        q.push(n);
        visited[n.x] = 1;
    }
}
int bfs(int f,int t){
    Queue q;
    Node tmp;
    tmp.x = f;
    tmp.dist = 0;
    visited[f] = 1;
    q.push(tmp);
    while(!q.empty()){
        Node tmp = q.front();
        q.pop();
        if(tmp.x == t){
            return tmp.dist;
        }
        Node next;
        next.dist = tmp.dist + 1;

        next.x = tmp.x+1;
        addNode(q,next);

        next.x = tmp.x-1;
        addNode(q,next);

        next.x = tmp.x*2;
        addNode(q,next);
    }
    return -1;
}
int main(){
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        memset(visited,0,sizeof(visited));
        printf("%d\n",bfs(n,k));
    }
    return 0;
}