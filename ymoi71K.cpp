#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::max;
using std::max_element;
int* dp;
int* a;
int n;
int main(){
    scanf("%d",&n);
    a=(int*)malloc((n+1)*sizeof(int));
    memset(dp=(int*)malloc((n+1)*sizeof(int)),0,(n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i-1]+a[i],a[i]);
    }
    printf("%d\n",*max_element(dp,dp+n+1));
    return 0;
}