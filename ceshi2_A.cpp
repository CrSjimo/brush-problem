#include<stdio.h>
#include<algorithm>

int dp[3000010];
int c0[105];
int c[105];
int w[105];
int main(){
    int n,m = 0;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d%d%d",c+i,c0+i,w+i);
        m+=w[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=m;j++){
            if(j>=w[i]){
                dp[j] = std::min(dp[j]+c0[i],dp[j-w[i]]+c[i]);
            }else{
                dp[j] = dp[j]+c0[i];
            }
        }
    }
    printf("%d\n",dp[m]);
}