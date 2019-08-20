#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstdio>
char s[1010];
int dp[1010][1010];
int pth[1010][1010];
void digui(int l,int r){
    if(l>r){
        return;
    }
    if(l==r){
        if(s[l]=='('||s[l]==')')printf("()");
        else if(s[l]=='['||s[l]==']')printf("[]");
        // printf("<%d>",l);
        return;
    }
    if(pth[l][r] == -1){
        printf("%c",s[l]);
        digui(l+1,r-1);
        printf("%c",s[r]);
    }else{
        //printf("{%d,%d}",l,pth[l][r]);
        digui(l,pth[l][r]);
        //printf("{%d,%d}",pth[l][r]+1,r);
        digui(pth[l][r]+1,r);
    }
}
int main(){
    // memset(dp,0x3f,sizeof(dp));
    // memset(pth,-1,sizeof(pth));
    scanf("%s",s);
    int len = strlen(s);
    for(int i = 0;i<len;i++){
        dp[i][i] = 1;
    }
    for(int k = 1;k<len;k++){
        for(int i = 0;i+k<len;i++){
            int j = i+k;
            dp[i][j]=0x3f3f3f3f;
            printf("%d ",dp[i][j]);
            if((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']')){
                dp[i][j] = dp[i+1][j-1];
                pth[i][j] = -1;
            }
            for(int l = i;l<j;l++){
                printf("%d %d\n",dp[i][l],dp[l+1][j]);
                if(dp[i][l]+dp[l+1][j]<dp[i][j]){
                    dp[i][j] = dp[i][l]+dp[l+1][j];
                    pth[i][j] = l;
                }
            }
            
        }
    }
    digui(0,len-1);
    printf("\n");
    return 0;
}