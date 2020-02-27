#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::max;
int a[25][25];
int dp[25][25];
int cumaxn;
void print(int i,int j){
    if(i==0)return;
    for(int k=0;k<=j;k++){
        if(cumaxn==dp[i-1][k]+a[i][j-k]){
            cumaxn=dp[i-1][k];
            print(i-1,k);
            printf("%d %d\n",i,j-k);
            break;
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int maxn = 0;
            for(int k=0;k<=j;k++){
                maxn=max(maxn,dp[i-1][k]+a[i][j-k]);
            }
            dp[i][j]=maxn;
        }
    }
    printf("%d\n",dp[n][m]);
    cumaxn=dp[n][m];
    print(n,m);
    return 0;
}