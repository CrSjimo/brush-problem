#include<stdio.h>
#include<string.h>
int a[1010];
int dp[1010];
int src[1010];
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
        }
        int maxn = 0;
        for(int i=1;i<=n;i++){
            int mnax = 0;
            int maxid = -1;
            for(int j=1;j<i;j++){
                if(a[j]<a[i]){
                    if(mnax<dp[j]){
                        maxid = src[j];
                    }
                    mnax = max(mnax,dp[j]);
                }
                dp[i] = mnax+1;
                if(dp[i]>maxn){
                    
                }
                maxn = max(dp[i],maxn);
            }
        }
    }
}