#include<cstdio>
#include<cstdlib>
int a[256][256];
int dp[256][256];
int n,r;
inline int query(int x1,int y1,int x2,int y2){
    return dp[x2][y2]+dp[x1-1][y1-1]-dp[x1-1][y2]-dp[x2][y1-1];
}
int main(){
    scanf("%d%d",&n,&r);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        int x1=i-r>=1?i-r:1;
        int x2=i+r<=n?i+r:n;
        for(int j=1;j<=n;j++){
            int y1=j-r>=1?j-r:1;
            int y2=j+r<=n?j+r:n;
            printf("%d ",query(x1,y1,x2,y2));
        }
        printf("\n");
    }
    return 0;
}