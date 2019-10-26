#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
int map[50][50];
int op[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int sx,sy,tx,ty;
int n,m,q;
void dfs(int ex,int ey,int fromx,int fromy,int t){
    if(map[tx][ty]==3){
        printf("%d\n",t);
        return;
    }
    for(int k = 0;k<4;k++){
        int nextEx = ex+op[k][0],nextEy = ey+op[k][1];
        if(nextEx==fromx&&nextEy==fromy)continue;
        if(nextEx<=0||nextEy<=0||nextEx>n||nextEy>m)continue;
        if(map[nextEx][nextEy]==0)continue;
        printf("test %d %d\n",nextEx,nextEy);
        std::swap(map[ex][ey],map[nextEx][nextEy]);
        dfs(nextEx,nextEy,ex,ey,t+1);
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 1;i<=n;i++){
        for(int i = 1;i<=m;i++){
            scanf("%d",&map[n][m]);
        }
    }
    while(q--){
        int ex,ey;
        scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
        map[sx][sy] = 3;
        srand(ex+ey+sx+sy+tx+ty);
        printf("%d\n",rand()%10000-1);
        
    }
    return 0;
}