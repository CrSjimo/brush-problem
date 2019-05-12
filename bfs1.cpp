#include<cstdio>
#include<cstring>
#include<queue>
int n,a,b;
int num[220];
bool visited[220];
struct Node{
    int id;
    int dist;
};
typedef std::queue<Node> Queue;
void addNewNode(Queue &q,int nodeId,int nodeDist){
    if(nodeId <= n && nodeId >0 && !visited[nodeId]){
        Node tmp;
        tmp.id = nodeId;
        tmp.dist = nodeDist;
        q.push(tmp);
        visited[nodeId] = 1;
    }
}
int bfs(int* num,int startPos,int endPos){
    Queue q;
    memset(visited,0,sizeof(visited));
    Node tmp;
    tmp.id = startPos;
    tmp.dist = 0;
    visited[startPos] = 1;
    while(!q.empty()){
        Node nowNode = q.front();
        int nowId = nowNode.id;
        int nowDist = nowNode.dist;
        if(nowId == endPos)return nowDist;
        q.pop();
        addNewNode(q,nowId + num[nowId],nowDist + 1);
        addNewNode(q,nowId - num[nowId],nowDist + 1);
    }
    return -1;
}
int main(){
    while(std::scanf("%d",&n) && n){
        std::scanf("%d%d",&a,&b);
        for(int i = 1;i<=n;i++){
            std::scanf("%d",num+i);
        }
        std::printf("%d\n",bfs(num,a,b));
    }
    return 0;
}