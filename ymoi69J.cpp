#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::min;
int* a;
int* b;
int* dp;
int main(){
    int n;scanf("%d",&n);
    a=(int*)malloc((n+1)*sizeof(int));
    b=(int*)malloc((n+1)*sizeof(int));
    dp=(int*)calloc((n+1),sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i=1;i<=n-1;i++){
        scanf("%d",b+i);
    }
    dp[1]=a[1];
    for(int i=2;i<=n;i++){
        dp[i]=min(dp[i-1]+a[i],dp[i-2]+b[i-1]);
    }
    printf("%d\n",dp[n]);
    return 0;
}