#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define MAXN 400
int op[5][2] = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};
int timeToDie[MAXN+10][MAXN+10];
struct Node{
    int x,y;
    int t;
};
typedef queue<Node> Queue;
bool inRange(int x,int y){
    return (x>=0 && x<=MAXN && y>=0 && y<=MAXN);
}
int bfss(){
    if(timeToDie[0][0] == -1)return 0;
    if(timeToDie[0][0] == 0)return -1;
    Queue q;
    Node tmp;
    tmp.x = tmp.y = tmp.t = 0;
    q.push(tmp);
    while(!q.empty()){
        Node tmp = q.front();
        q.pop();
        Node next;
        next.t = tmp.t + 1;
        for(int i = 1;i<5;i++){
            next.x = tmp.x + op[i][0];
            next.y = tmp.y + op[i][1];
            if(!inRange(next.x,next.y))continue;
            // printf("test:%d %d %d %d\n",next.x,next.y,next.t,timeToDie[next.x][next.y]);
            if(timeToDie[next.x][next.y] == -1)return next.t;
            if(next.t >= timeToDie[next.x][next.y])  continue;
            q.push(next);
            timeToDie[next.x][next.y] = next.t;
        }
    }
    return -1;
}
void init(int n){
    for(int i = 0;i<=MAXN;i++){
        for(int j = 0;j<=MAXN;j++){
            timeToDie[i][j] = -1;
        }
    }
    // printf("%d\n",timeToDie[0][0]);
    for(int i = 0;i<n;i++){
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        for(int j = 0;j<5;j++){
            // printf("%d%d\n",op[j][0],op[j][1]);
            int newX = x + op[j][0];
            int newY = y + op[j][1];
            if(!inRange(newX,newY))continue;
            timeToDie[newX][newY] = ((timeToDie[newX][newY]) == -1)?t:min(timeToDie[newX][newY],t);
            // printf("test:%d %d %d\n",newX,newY,timeToDie[newX][newY]);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    init(n);
    printf("%d\n",bfss());
    return 0;
}