#include<cstdio>
#include<cstdlib>
#include<cstring>
int** a;
int* dp;
int* pre;
int main(){
    int n;scanf("%d",&n);
    dp = (int*)malloc((n+1)*sizeof(int));
    pre = (int*)malloc((n+1)*sizeof(int));
    memset(dp,0x3f,(n+1)*sizeof(int));
    a = (int**)malloc((n+1)*sizeof(int*));
    for(int** p=a;p<=a+n;p++)*p=(int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)a[i][j]=0x3f3f3f3f;
        }
    }
    dp[n]=0;
    for(int i=n-1;i>=1;i--){
        for(int v=i+1;v<=n;v++){
            if(a[i][v]==0x3f3f3f3f)continue;
            if(dp[i]>a[i][v]+dp[v]){
                dp[i]=a[i][v]+dp[v];
                pre[i]=v;
            }
        }
    }
    printf("minlong=%d\n",dp[1]);
    for(int i=1;i;i=pre[i]){
        printf("%d ",i);
    }
    printf("\n");
    return 0;
}