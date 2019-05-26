#include<cstdio>
#include<cstring>
int map[25][25];
int startI,startJ;
int op[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int stepAns = 11;
int n,m;
void dfs(int startI,int startJ,int dist){
    if(dist>10 || dist > stepAns)return;
    for(int k = 0;k<4;k++){
        int nowI = startI;
        int nowJ = startJ;
        while(nowI >= 0 && nowI < m && nowJ >= 0 && nowJ < n){
            if(map[nowI][nowJ] == 0){
                nowI += op[k][0];
                nowJ += op[k][1];
            }else if(map[nowI][nowJ] == 3){
                 if (dist + 1 < stepAns) {
                    stepAns = dist + 1;
                }
                break;
            }else if(map[nowI][nowJ] == 1){
                if (!(nowI - op[k][0] == startI && nowJ - op[k][1] == startJ)) {
                    map[nowI][nowJ] = 0;
                    dfs(nowI - op[k][0],nowJ - op[k][1],dist + 1);
                    map[nowI][nowJ] = 1;
                }
                break;
            }
        }
    }
}
#define minStep stepAns
#define room map
#define H m
#define W n
const int direc[4][2] = {
    { 0, -1 },
    { 1,0 },
    { 0, 1 },
    { -1 ,0 },
};
void dfss(const int& row, const int& col, int step) {
    if (step >= 10 || step > minStep) {
        return;
    }
    for (int d = 0; d < 4; ++d) {
        int cRow = row;
        int cCol = col;
        while (cRow >= 0 && cRow < H && cCol >= 0 && cCol < W) {
            switch (room[cRow][cCol]) {
            case 0: {
                cRow += direc[d][1];
                cCol += direc[d][0];
                break;
            }
            case 3: {
                if (step + 1 < minStep) {
                    minStep = step + 1;
                }
                cRow = -1;
                break;
            }
            case 1: {
                if (!(cRow - direc[d][1] == row && cCol - direc[d][0] == col)) {
                    room[cRow][cCol] = 0;
                    dfs(cRow - direc[d][1], cCol - direc[d][0], step + 1);
                    room[cRow][cCol] = 1;
                }
                cRow = -1;
                break;
            }
            default: {
                break;
            }
            }
        }
    }
}
void input(int n,int m){
    memset(map,0,sizeof(map));
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == 2){
                startI = i;
                startJ = j;
                map[i][j] = 0;
            }
        }
    }
}

int main(){
    while(~scanf("%d%d",&n,&m)&&n&&m){
        input(n,m);
        stepAns = 11;
        dfs(startI,startJ,0);
        printf("%d\n",(stepAns>10)?-1:stepAns);
    }
    return 0;
}