#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::max;
int n,m;
int* f;
int* dp;
int main(){
    scanf("%d%d",&n,&m);m--;
    dp=(int*)calloc(m+1,sizeof(int));
    memset(f=(int*)malloc((m+1)*sizeof(int)),128,(m+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int k;scanf("%d",&k);
            f[j]=max(f[j],k);
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        ans=max(ans,dp[i]=max(dp[i-1],0)+f[i]);
    }
    printf("%d\n",ans);
    return 0;
}/*
3 6
-50 -47 36 -30 -23
17 -19 -34 -13 -8
-42 -3 -43 34 -45
*/
