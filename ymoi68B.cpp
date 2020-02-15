#include<cstdio>
#include<cstdlib>
#include<utility>
using std::pair;
using std::make_pair;
typedef pair<char,char> pii;
#include<queue>
#include<cstring>
using std::queue;
int vis[110][110];
struct Node{
    int dis;
    pii v;
    Node(int dis,pii v){
        this->dis=dis;
        this->v=v;
    }
};
char op[12][2]={{-2,-2},{-2,-1},{-2,1},{-2,2},{-1,-2},{-1,2},{1,-2},{1,2},{2,-2},{2,-1},{2,1},{2,2}};
inline bool cando(char i,char j){
    return i>=0&&i<=100&&j>=0&&j<=100&&vis[i][j]==-1;
}
int dis1=-1,dis2=-1;
queue<Node> q;
void bfs(pii s1,pii s2){
    q.push(Node(0,make_pair<char,char>(1,1)));
    while(!q.empty()){
        Node u=q.front();q.pop();
        if(vis[s1.first][s1.second]>0 && vis[s2.first][s2.second]>0){
            printf("%d\n%d\n",vis[s1.first][s1.second],vis[s2.first][s2.second]);
            exit(0);
        }
        for(int k=0;k<12;k++){
            char ni = u.v.first+op[k][0];
            char nj = u.v.second+op[k][1];
            if(cando(ni,nj)){
                vis[ni][nj]=u.dis+1;
                q.push(Node(u.dis+1,make_pair(ni,nj)));
            }
        }
    }
}
int main(){
    int a,b,c,d;
    pii s1,s2;
    memset(vis,255,sizeof(vis));
    scanf("%d%d%d%d",&a,&b,&c,&d);
    s1.first=a;s1.second=b;s2.first=c;s2.second=d;
    bfs(s1,s2);
    return 0;
}
