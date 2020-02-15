#include<cstdio>
#include<cstdlib>
int n,m;
char** a;
#include<queue>
using std::queue;
#include<utility>
using std::pair;
using std::make_pair;
typedef pair<int,int> pii;
inline bool cando(int i,int j){
    return i>=1&&i<=n&&j>=1&&j<=m&&a[i][j]!='0';
}
int op[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int ans = 0;
void bfs(pii s){
    queue<pii> q;
    q.push(s);
    while(!q.empty()){
        pii u = q.front();q.pop();
        a[u.first][u.second]='0';
        for(int k=0;k<4;k++){
            int ni = u.first+op[k][0];
            int nj = u.second+op[k][1];
            if(cando(ni,nj)){
                q.push(make_pair(ni,nj));
            }
        }
    }
    ans++;
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("\n");
    a = (char**)malloc((n+1)*sizeof(char*));
    for(char** p=a;p<=a+n;p++)*p=(char*)malloc((m+1)*sizeof(char));
    for(int i=1;i<=n;i++){
        scanf("%s",a[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]!='0')bfs(make_pair(i,j));
        }
    }
    printf("%d\n",ans);
    return 0;
}