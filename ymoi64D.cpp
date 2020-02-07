#include<cstdio>
#include<queue>
#include<vector>
#include<utility>

using namespace std;

typedef pair<int,int> pii;
int op[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
void bfs(pii s,vector< vector<int> >& G){
    queue<pii> q;
    q.push(s);
    while(!q.empty()){
        pii p = q.front();q.pop();
        G[p.first][p.second] = 1;
        for(int k=0;k<4;k++){
            int i = p.first+op[k][0];
            int j = p.second+op[k][1];
            if(i<0||i>=n||j<0||j>=m)continue;
            if(G[i][j]==0){
                q.push(make_pair(i,j));
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    vector< vector<int> > G(n+5,vector<int>(m+5));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int k;scanf("%d",&k);
            G[i][j]=!k;
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(G[i][j]==0){
                G[i][j]=1;
                bfs(make_pair(i,j),G);
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}