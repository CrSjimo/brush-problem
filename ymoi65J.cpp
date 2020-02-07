#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::min;
int** a;
int n;
int minn = 0x19260817;
bool* vis;
void dfs(int i,int c){
    //printf("t:%d %d\n",i,c);
    if(i>n){
        minn = min(c,minn);
        //printf("min:%d\n",minn);
        return;
    }
    if(c>=minn)return;
    for(int j=1;j<=n;j++){
        if(vis[j])continue;
        vis[j]=true;
        dfs(i+1,c+a[i][j]);
        vis[j]=false;
    }
}
int main(){
    scanf("%d",&n);
    a = (int**)malloc((n+1)*sizeof(int*));for(int** p = a;p<=a+n;p++)*p = (int*)malloc((n+1)*sizeof(int*));
    vis = (bool*)malloc((n+1)*sizeof(bool));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    dfs(1,0);
    printf("%d\n",minn);
    return 0;
}