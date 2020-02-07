#include<cstdio>
#include<vector>
#include<utility>
using std::vector;
bool vis[15][15];
int n;
int ans = 0;
inline bool cando(int x,int y){
    return x>0&&x<=n&&y>0&&y<=n&&!vis[x][y];
}
int op[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
void dfs(int i,int x,int y){
    //printf("t:%d %d\n",x,y);
    if(i == n*n){
        ans++;
        return;
    }
    for(int k=0;k<8;k++){
        int nx = x+op[k][0];
        int ny = y+op[k][1];
        if(cando(nx,ny)){
            vis[nx][ny] = true;
            dfs(i+1,nx,ny);
            vis[nx][ny] = false;
        }
    }
}
int main(){
    scanf("%d",&n);
    vis[1][1]=true;
    dfs(1,1,1);
    printf("%d\n",ans);
    return 0;
}