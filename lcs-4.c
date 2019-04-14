#include<stdio.h>
#include<string.h>
char s1[1010],s2[1010];
int dp[1010][1010];
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    while(~scanf("%s%s",s1+1,s2+1)){
        int len1 = strlen(s1+1);
        int len2 = strlen(s2+1);
        for(int i = 1;i<=len1;i++){
            for(int j = 1;j<=len2;j++){
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // for(int i = 1;i<=len1;i++){
        //     for(int j = 1;j<=len2;j++){
        //         printf("%d ",dp[i][j]);
        //     }
        //     printf("%d\n");
        // }
        printf("%d\n",dp[len1][len2]);
        memset(dp,0,sizeof(dp));
    }
    return 0;
}