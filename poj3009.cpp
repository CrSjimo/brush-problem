#include<cstdio>
#include<cstring>
int map[25][25];
int startI,startJ;
int dfs(int startI,int startJ,int dist){
    if(dist>10)return -1;

}
void input(int n,int m){
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == 2){
                startI = i;
                startJ = j;
            }
        }
    }
}
int main(){

}