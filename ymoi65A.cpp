#include<cstdio>
#include<cstdlib>
int map[10][10];
int ans = 0;
int n;
int op[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
bool vis[10][10];
inline bool cando(int x,int y){
    return x>=0&&x<n&&y>=0&&y<n&&map[x][y]==0&&!vis[x][y];
}
void dfs(int x,int y){
    //printf("t:%d %d\n",x,y);
    if(x==0&&y==n-1){
        ans++;
        //printf("ok\n");
        return;
    }
    for(int k=0;k<8;k++){
        int xx = x+op[k][0];
        int yy = y+op[k][1];
        if(cando(xx,yy)){
            vis[xx][yy]=true;
            dfs(xx,yy);
            vis[xx][yy]=false;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }
    vis[0][0]=true;
    dfs(0,0);
    printf("%d\n",ans);
    return 0;
}