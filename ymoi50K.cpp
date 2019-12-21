#include<stdio.h>
#include<vector>
long long ans = 0;
int x1,y1,x2,y2;
int n,m;
int op[4][2] = {{1,2},{1,-2},{2,1},{2,-1}};
void dfs(std::vector< std::vector<bool> >& vis,int i,int j){
    if(i==x2&&j==y2){
        ans++;
    }
    for(int k=0;k<3;k++){
        int ni = i+op[k][0];
        int nj = j+op[k][1];
        if(ni>=1&&ni<=n&&nj>=1&&nj<=m&&!vis[ni][nj]){
            vis[ni][nj] = true;
            dfs(vis,ni,nj);
            vis[ni][nj] = false;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    std::vector< std::vector<bool> > f(n+1,std::vector<bool>(m+1));
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    dfs(f,x1,y1);
    printf("%lld",ans);
    return 0;
}