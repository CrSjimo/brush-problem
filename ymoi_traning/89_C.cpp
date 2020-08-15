#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using std::queue;
int n,m,p;
int gate[12][12][12][12];
int key[12][12];
bool vis[12][12][1<<11];

struct Node{
    int x,y;
    int S;
    int d;
    Node(int x,int y,int S,int d){
        this->x=x;
        this->y=y;
        this->S=S;
        this->d=d;
    }
};
int op[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int bfs(){
    queue<Node> q;
    q.push(Node(1,1,0,0));
    vis[1][1][0]=1;
    while(!q.empty()){
        Node t=q.front();q.pop();
        if(t.x==n&&t.y==m){
            return t.d;
        }
        int nS=t.S;
        nS|=(key[t.x][t.y]);
        for(int k=0;k<4;k++){
            int nx=t.x+op[k][0],ny=t.y+op[k][1];
            if(vis[nx][ny][nS])continue;
            if(nx<=0||ny<=0||nx>n||ny>m)continue;
            int g=gate[t.x][t.y][nx][ny];
            if(g==-1||(nS&(1<<g))){
                q.push(Node(nx,ny,nS,t.d+1));
                vis[nx][ny][nS]=1;
            }
        }
    }
    return -1;
}
int main(){
    memset(gate,-1,sizeof(gate));
    scanf("%d%d%d",&n,&m,&p);
    int k;scanf("%d",&k);
    while(k--){
        int x1,x2,y1,y2,g;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&g);
        gate[x1][y1][x2][y2]=gate[x2][y2][x1][y1]=g;
    }
    scanf("%d",&k);
    while(k--){
        int x,y,g;
        scanf("%d%d%d",&x,&y,&g);
        key[x][y]|=(1<<g);
    }
    printf("%d\n",bfs());
    return 0;
}
