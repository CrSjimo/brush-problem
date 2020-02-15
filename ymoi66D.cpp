#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::max;
int main(){
    int ans=0;
    int* dp = (int*)calloc(sizeof(int),(1002));
    int* a = (int*)malloc((1002)*sizeof(int));
    int n=0;
    while(~scanf("%d",a+(++n)));
    int k=1;dp[k]=a[1];
    dp[0]=19260817;
    for(int i=2;i<=n;i++){
        int p = 0;
        for(int j=1;j<=k;j++){
            if(dp[j]>=a[i] && dp[j]<dp[p]){
                p=j;
            }
        }
        if(p==0){
            dp[++k]=a[i];
        }else{
            dp[p]=a[i];
        }
    }
    printf("%d\n",k);
    return 0;
}