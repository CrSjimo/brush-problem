#include<cstdio>
#include<utility>
#include<queue>
using std::queue;
using std::pair;
using std::make_pair;
typedef pair<int,int> pii;
int map[10][10];
int op[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int bfs(pii s){
    int ans = 0;
    //bool reach[4] = {0,0,0,0};
    bool reside = true;
    queue<pii> q;
    q.push(s);
    while(!q.empty()){
        ans++;
        pii e = q.front();q.pop();
        for(int k=0;k<4;k++){
            int i = e.first + op[k][0];
            int j = e.second + op[k][1];
            if(i<0||i>=10||j<0||j>=10){
                reside = false;
                continue;
            }
            if(map[i][j]==1){
                //reach[k]=1;
            }else if(map[i][j]==0){
                map[i][j]=2;
                q.push(make_pair(i,j));
            }
        }
    }
    if(reside){
        return ans;
    }
    return 0;
}
int main(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            scanf("%d",&map[i][j]);
        }
    }
    int ans = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(map[i][j]==0){
                map[i][j]=2;
                ans+=bfs(make_pair(i,j));
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}