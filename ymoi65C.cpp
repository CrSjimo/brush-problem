#include<cstdio>
#include<cstdlib>
int* a;
int n;
int ans=0;
void dfs(int s,int t){
    //printf("t:%d %d\n",s,t);
    if(s==0){
        //printf("%d=",n);
        for(int j=1;j<t-1;j++){
            printf("%d+",a[j]);
        }
        printf("%d\n",a[t-1]);
        ans++;
        return;
    }
    for(int j=a[t-1];j<=s;j++){
        //printf("ttt:%d %d\n",j,n);
        if(j < n){
            //printf("tt:%d\n",j);
            a[t]=j;
            s-=j;
            dfs(s,t+1);
            s+=j;
        }
    }
}
int main(){
    scanf("%d",&n);
    a = (int*)malloc((n+1)*sizeof(int));
    *a = 1;
    dfs(n,1);
    //printf("total=%d\n",ans);
    return 0;
}