#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
char s[4],ss[4];
bool used[10][10];
struct Node{
    int x;
    int y;
    int dist;
};
//FUCK OP!!!!!!!!!!
const int op[8][2] = {-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2,-2,-1};
bool canDo(int x,int y){
    return (!used[x][y]) && x>=0 && x<8 && y>=0 && y<8;
}
typedef queue<Node> Queue;
int bfs(
    int fromX,int fromY,
    int toX,int toY
){
    // if(fromX-fromY == toX-toY)return 2;
    memset(used,0,sizeof(used));
    Queue q;
    Node tmp,next,nowNode;
    tmp.x = fromX;
    tmp.y = fromY;
    tmp.dist = 0;
    q.push(tmp);
    used[fromX][fromY] = 1;
    while(!q.empty()){
        nowNode = q.front();
        q.pop();
        if(nowNode.x == toX && nowNode.y == toY)return nowNode.dist;
        for(int i = 0;i<8;i++){
            next.x = nowNode.x + op[i][0];
            next.y = nowNode.y + op[i][1];
            if(next.x == toX && next.y == toY)return nowNode.dist + 1;
            if(!canDo(next.x,next.y))
                continue;
            next.dist = nowNode.dist + 1;
            used[next.x][next.y] = 1;
            q.push(next);
        }
    }
    return 0;
}
int main(){
    while(~scanf("%s%s",s,ss)){
        int fromX = s[0]-'a';
        int fromY = s[1]-'1';
        int toX = ss[0]-'a';
        int toY = ss[1]-'1';
        // printf("test:%d %d %d %d",fromX,fromY,toX,toY);
        printf(
            "To get from %c%c to %c%c takes %d knight moves.\n",
            s[0],s[1],ss[0],ss[1],
            bfs(fromX,fromY,toX,toY)
        );
    }
    return 0;
}