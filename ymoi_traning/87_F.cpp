#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::max;
long long dp[1+14+5+14][19+19+8-10];
int root[1+14+5+14][19+19+8-10];
int a[19+26+8-17];
void dfs(int l,int r){
    if(l>r)return;
    printf("%d ",root[l][r]);
    dfs(l,root[l][r]-1);
    dfs(root[l][r]+1,r);
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        root[i][i]=i;
        dp[i][i-1]=dp[i+1][i]=1;
        dp[i][i]=a[i];
    }
    for(int c=1;c<n;c++){
        for(int l=1;l+c<=n;l++){
            int r=l+c;
            for(int k=l;k<=r;k++){
                if(dp[l][r]<dp[l][k-1]*dp[k+1][r]+a[k]){
                    dp[l][r]=dp[l][k-1]*dp[k+1][r]+a[k];
                    root[l][r]=k;
                }
            }
        }
    }
    printf("%lld\n",dp[1][n]);
    dfs(1,n);
    printf("\n");
    return 0;
}