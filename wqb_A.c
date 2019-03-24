#include<stdio.h>
#include<string.h>
long long dp[30010];
int a[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
int main(){
    double n1;
    while(~scanf("%lf",&n1)&&n1){
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int n = (int)(100*n1);
        for(int i=0;i<11;i++){
            for(int j=a[i];j<=n;j++){
                dp[j]+=dp[j-a[i]];
            }
        }
        printf("%6.2f%17lld\n",n1,dp[n]);
    }
    return 0;
}