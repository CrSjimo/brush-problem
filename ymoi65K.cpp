#include<cstdio>
#include<cstdlib>
int* p;
int n,ans=0;
void dfs(int i){
    if(i==n){
        //for(int j=1;j<=n;j++)printf("%d ",p[j]);
        //printf("\n");
        ans++;
        return;
    }
    for(int j=1;j<=3;j++){
        if(j!=p[i-1] || p[i]!=p[i-2]){
            p[i+1]=j;
            dfs(i+1);
        }
    }
}
int main(){
    scanf("%d",&n);
    p = (int*)malloc((n+5)*sizeof(int))+2;
    p[-2] = 1926;
    p[-1] = 8;
    p[0] = 17;
    dfs(0);
    printf("%d\n",ans);
    return 0;
}