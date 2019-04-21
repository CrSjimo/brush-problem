#include<stdio.h>
#include<string.h>
int dp[1010][1010];
int pth[1010][1010];
char s[1010];
#define FROM_SUBSEQ -1
void digui(int i,int j){
    if(i>j)return;
    if(i == j){
        if(s[i] == '(' || s[i] == ')'){
            printf("()");
        }else{
            printf("[]");
        }
    }else if(pth[i][j] == FROM_SUBSEQ){
        printf("%c",s[i]);
        digui(i+1,j-1);
        printf("%c",s[j]);
    }else{
        digui(i,pth[i][j]);
        digui(pth[i][j]+1,j);
    }
}
int main(){
    scanf("%s",s);
    int len = strlen(s);
    memset(dp,127,sizeof(dp));
    for(int i = 0;i<len;i++){
        dp[i][i] = 1;
    }
    for(int i = 0;i<len-1;i++){
        int j = i+1;
        if(
            (s[i] == '(' && s[j] == ')')
            ||
            (s[i] == '[' && s[j] == ']')
        ){
            dp[i][j] = 0;
        }else{
            dp[i][j] = dp[i][i] + dp[j][j];
        }
    }
    for(int i = 0;i<len;i++){
        for(int j = i+1;j<len;j++){
            if(
                (s[i] == '(' && s[j] == ')')
                ||
                (s[i] == '[' && s[j] == ']')
            ){
                dp[i][j] = dp[i+1][j-1];
                pth[i][j] = FROM_SUBSEQ;
            }
            for(int k = i;k<j;k++){
                if(dp[i][j]>dp[i][k]+dp[k+1][j]){
                    dp[i][j] = dp[i][k]+dp[k+1][j];
                    pth[i][j] = k;
                }
            }
        }
    }
    for(int i = 0;i<len;i++){
        for(int j = 0;j<len;j++){
            printf("%d ",pth[i][j]);
        }
        printf("\n");
    }
   //digui(0,len-1);
    printf("\n");
    return 0;
}