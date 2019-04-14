#include<stdio.h>
#include<string.h>
char s1[1010],s2[1010];
int dp[1010][1010];
char pth[1010][1010];
#define IS_SUBSEQ_ITEM 0
#define IS_DP_J 1
#define IS_DP_I -1
void digui(int i,int j){
    if(i == 0 && j == 0){
        return;
    }
    // printf("%d %d\n",i,j);
    if(pth[i][j] == IS_DP_J){
        digui(i-1,j);
        // printf("%d %d\n",i,j);
        printf("%c",s1[i-1]);
    }else if(pth[i][j] == IS_DP_I){
        digui(i,j-1);
        // printf("%d %d\n",i,j);
        printf("%c",s2[j-1]);
    }else{
        digui(i-1,j-1);
        // printf("%d %d\n",i,j);
        printf("%c",s2[j-1]);
    }
}
int main(){
    while(~scanf("%s%s",s1,s2)){
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        for(int i = 0;i<=len1;i++)pth[i][0] = IS_DP_J;
        for(int j = 0;j<=len2;j++)pth[0][j] = IS_DP_I;
        for(int i = 1;i<=len1;i++){
            for(int j = 1;j<=len2;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    pth[i][j] = IS_SUBSEQ_ITEM;
                }else{
                    if(dp[i-1][j] > dp[i][j-1]){
                        dp[i][j] = dp[i-1][j];
                        pth[i][j] = IS_DP_J;
                    }else{
                        dp[i][j] = dp[i][j-1];
                        pth[i][j] = IS_DP_I;
                    }
                }
            }
        }
        digui(len1,len2);
        printf("\n");
        memset(dp,0,sizeof(dp));
        memset(pth,0,sizeof(pth));
    }
    return 0;
}