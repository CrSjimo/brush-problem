#include<cstdio>
#include<cstdlib>
int n,r;
int* a;
bool* vis;
void dfs(int i){
    if(i>r){
        for(int j=1;j<=r;j++){
            printf("%d ",a[j]);
        }
        printf("\n");
        return;
    }
    for(int j=a[i-1]+1;j<=n;j++){
        if(!vis[j]){
            vis[j]=1;
            a[i]=j;
            dfs(i+1);
            vis[j]=0;
        }
    }
}
int main(){
    scanf("%d%d",&n,&r);
    a = (int*)malloc((r+1)*sizeof(int));
    vis = (bool*)malloc((n+1)*sizeof(bool));
    dfs(1);
    return 0;
}