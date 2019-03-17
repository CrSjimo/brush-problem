#include<stdio.h>
#include<string.h>
int dp[1010][1010],w[1010],c[1010];
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int t;
    scanf("%d",&t);
    for(;t>0;t--){
        memset(dp,0,sizeof dp);
        memset(w,0,sizeof w);
        memset(c,0,sizeof c);
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",c+i);
        for(int i=1;i<=n;i++)scanf("%d",w+i);
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(j>=w[i]){
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        printf("   ");
        for(int i=0;i<=m;i++){
            printf("%2d|",i);
        }
        printf("\n");
        for(int i=0;i<=n;i++){
            printf("%2d|",i);
            for(int j=0;j<=m;j++){
                printf("%2d|",dp[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}