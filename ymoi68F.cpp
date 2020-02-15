#include<cstdio>
#include<cstdlib>
#include<utility>
using std::pair;
using std::make_pair;
typedef pair<char,char> pii;
#include<queue>
#include<cstring>
#include<cstring>
using std::queue;
int m,n,m1,m2;
int a[35][35];
int v[35][35];
struct Node{
    int dis;
    pii v;
    Node(int dis,pii v){
        this->dis=dis;
        this->v=v;
    }
};
inline bool cando(int i,int j){
    return i>=1&&i<=m&&j>=1&&j<=n&&v[i][j]==-1&&a[i][j]==1;
}
int op[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};
void bfs(pii s,pii t){
    queue<Node> q;
    q.push(Node(0,s));
    while(!q.empty()){
        Node u=q.front();q.pop();
        if(v[t.first][t.second]>0){
            return;
        }
        for(int k=0;k<4;k++){
            int ni = u.v.first+op[k][0]*m1;
            int nj = u.v.second+op[k][1]*m2;
            
            if(cando(ni,nj)){
                v[ni][nj]=u.dis+1;
                q.push(Node(u.dis+1,make_pair(ni,nj)));
            }
        }
        for(int k=0;k<4;k++){
            int ni = u.v.first+op[k][0]*m2;
            int nj = u.v.second+op[k][1]*m1;
            if(cando(ni,nj)){
                v[ni][nj]=u.dis+1;
                q.push(Node(u.dis+1,make_pair(ni,nj)));
            }
        }
    }
}
int main(){
    scanf("%d%d%d%d",&m,&n,&m1,&m2);
    memset(v,255,sizeof(v));
    pii s,t;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==3){
                s.first=i,s.second=j;
            }else if(a[i][j]==4){
                t.first=i,t.second=j;
                a[i][j]=1;
            }
        }
    }
    v[s.first][s.second]=0;
    bfs(s,t);
    printf("%d\n",v[t.first][t.second]);
    return 0;
}