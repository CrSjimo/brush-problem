#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::min;
int** dp;
int* s;
int main(){
    int n;scanf("%d",&n);
    dp=(int**)malloc((n+1)*sizeof(int*));
    for(int**p=dp;p<=dp+n;p++){
        memset(*p=(int*)malloc((n+1)*sizeof(int)),0x3f,(n+1)*sizeof(int));
    }
    s=(int*)calloc(n+1,sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",s+i);
        dp[i][i]=0;
        s[i]+=s[i-1];
    }
    for(int c=1;c<n;c++){
        for(int l=1;l+c<=n;l++){
            int r=l+c;
            for(int k=l;k<r;k++){
                dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+s[r]-s[l-1]);
            }
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}