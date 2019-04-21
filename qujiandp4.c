#include<stdio.h>
#include<string.h>
int dp[1010][1010];
char s[1010];
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    while(scanf("%s",s)){
        if(s[0] == 'e')break;
        memset(dp,0,sizeof(dp));
        int len = strlen(s);
        for(int c = 1;c<len;c++){
            for(int i = 0 ;i+c<len;i++){
                int j = i+c;
                if((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']')){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                for(int k = i;k<j;k++){
                    dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        }
        printf("%d\n",dp[0][len-1]);
    }
    return 0;
}