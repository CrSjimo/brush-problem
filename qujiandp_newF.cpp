#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 0x3f3f3f3f
int dp[110][110];
int ddp[110];
int main(){
    char s1[110],s2[110];
    while(~scanf("%s%s",s1,s2)){
        memset(dp,0,sizeof(dp));
        int len = strlen(s1);
        for(int i = 0;i<len;i++){
            for(int j = i;j<len;j++){
                dp[i][j] = j-i+1;
            }
        }
        for(int i = len-2;i>=0;i--){
            for(int j = i+1;j<len;j++){
                dp[i][j] = dp[i+1][j]+1;
                for(int k = i+1;k<=j;k++){
                    if(s2[i]==s2[k]){
                        dp[i][j] = std::min(dp[i][j],dp[i+1][k-1]+dp[k][j]);
                    }
                }
            }
        }
        for(int i = 0;i<len;i++){
            ddp[i] = dp[0][i];
            if(s1[i]==s2[i]){
                ddp[i]=(i==0)?0:ddp[i-1];
            }
            for(int j = 0;j<i;j++){
                ddp[i] = std::min(ddp[i],ddp[j]+dp[j+1][i]);
            }
        }
        printf("%d\n",ddp[len-1]);
    }
}