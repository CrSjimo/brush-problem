#include<cstdio>
#include<cstdlib>
#include<queue>
using std::queue;
#include<utility>
using std::pair;
using std::make_pair;
typedef std::pair<int,int> pii;
int a[15][15];
int n;
struct Node{
    int dis;
    pii v;
    Node(int dis,pii v){
        this->dis=dis;
        this->v=v;
    }
};
inline bool cando(int i,int j){
    return i>=1&&i<=n&&j>=1&&j<=n&&a[i][j]==0;
}
int op[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int bfs(pii s,pii t){
    queue<Node> q;
    q.push(Node(0,s));
    while(!q.empty()){
        Node u=q.front();q.pop();
        if(u.v.first == t.first && u.v.second == t.second){
            return u.dis;
        }
        a[u.v.first][u.v.second]=1;
        for(int k=0;k<8;k++){
            int ni = u.v.first+op[k][0];
            int nj = u.v.second+op[k][1];
            if(cando(ni,nj)){
                q.push(Node(u.dis+1,make_pair(ni,nj)));
            }
        }
    }
    printf("no way.");
    exit(0);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("%d\n",bfs(make_pair(1,1),make_pair(1,n)));
    return 0;
}