#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
//1:. 0:# 2:S 3:E
int map[50][50][50];
struct Node{
    int dist;
    int x,y,z;
};
bool visited[50][50][50];
int op[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int bfs(Node start){
    std::queue<Node> q;
    q.push(start);
    while(!q.empty()){
        Node tmp = q.front();
        q.pop();
        if(map[tmp.x][tmp.y][tmp.z] == 3){
            return tmp.dist;
        }
        for(int i = 0;i<6;i++){
            int nx = tmp.x+op[i][0];
            int ny = tmp.y+op[i][1];
            int nz = tmp.z+op[i][2];
            // printf("%d %d %d %d %d %d\n",nx,ny,nz,tmp.dist,visited[nx][ny][nz],map[nx][ny][nz]);
            if(visited[nx][ny][nz])continue;
            // printf("cando1");
            if(map[nx][ny][nz]!=1 && map[nx][ny][nz]!=3)continue;
            // printf("cando2\n");
            Node next;
            next.dist = tmp.dist+1;
            next.x = nx;
            next.y = ny;
            next.z = nz;
            visited[nx][ny][nz] = 1;
            q.push(next);
            
        }
    }
    return -1;
}
int main(){
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c)&&(a||b||c)){
        memset(map,0,sizeof(map));
        memset(visited,0,sizeof(visited));
        int x,y,z;
        for(int i = 1;i<=a;i++){
            for(int j = 1;j<=b;j++){
                char s[50];
                scanf("%s",s+1);
                for(int k = 1;k<=c;k++){
                    switch(s[k]){
                        case '.':
                            map[i][j][k] = 1;
                            break;
                        case '#':
                            map[i][j][k] = 0;
                            break;
                        case 'S':
                            x = i;
                            y = j;
                            z = k;
                            map[i][j][k] = 2;
                            break;
                        case 'E':
                            map[i][j][k] = 3;
                    }
                }
            }
        }
        Node start;
        start.dist = 0;
        start.x = x;
        start.y = y;
        start.z = z;
        int ans = bfs(start);
        if(ans!=-1){
            printf("Escaped in %d minute(s).\n",ans);
        }else{
            printf("Trapped!\n");
        }
    }
    return 0;
}