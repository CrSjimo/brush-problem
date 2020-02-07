#include<cstdio>
#include<cstdlib>
int n,c;
int* a;
int* p;
bool* vis;
void dfs(int i,int sum){
    if(sum>c)return;
    if(sum == c){
        for(int j = 1;j<i;j++){
            printf("%d ",p[j]);
        }
        printf("\n");
        exit(0);
    }
    if(i>n)return;
    for(int j=1;j<=n;j++){
        if(!vis[j]){
            vis[j]=true;
            p[i]=a[j];
            dfs(i+1,sum+a[j]);
            vis[j]=false;
        }
    }
}
int main(){
    scanf("%d%d",&n,&c);
    a = (int*)malloc((n+1)*sizeof(int));
    p = (int*)malloc((n+1)*sizeof(int));
    vis = (bool*)malloc((n+1)*sizeof(bool));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    dfs(1,0);
    printf("No Solution!\n");
    return 0;
}