#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define MAXN 10010
std::vector<int> map[MAXN];
struct Edge{
    int pre;
    int i,j;
    int w;
    Edge(int pre,int i,int j,int w){
        this->i = i;
        this->j = j;
        this->w = w;
        this->pre = pre;
    }
    Edge(){};
} a[MAXN];
int dp[MAXN][2];
int pre[MAXN];
void dfs(int i,int p){
    int ans = 0;
    
}
int main(){
    int n;
    // memset(pre,-1,sizeof(pre));
    // printf("%d",pre[0]);
    while(~scanf("%d",&n)){
        memset(dp,0,sizeof(dp));
        memset(pre,-1,sizeof(pre));
        int ecnt = 0; 
        for(int i = 2;i<=n;i++){
            int w,j;
            scanf("%d%d",&j,&w);
            a[ecnt] = Edge(pre[i],i,j,w);
            pre[i] = ecnt++;
            a[ecnt] = Edge(pre[j],j,i,w);
            pre[i] = ecnt++;
        }
        for(int i = 1;i<=n;i++){
            printf("%d\n",dfs(i,-1));
        }
    }
    return 0;
}