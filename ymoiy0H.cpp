#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::max;
int* w;
int* v;
int* dp;
int main(){
    int n,m;scanf("%d%d",&m,&n);
    dp=(int*)calloc((m+1),sizeof(int));
    w=(int*)malloc((n+1)*sizeof(int));
    v=(int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++)scanf("%d%d",w+i,v+i);
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]*w[i]);
        }
    }
    printf("%d\n",dp[m]);
    return 0;
}