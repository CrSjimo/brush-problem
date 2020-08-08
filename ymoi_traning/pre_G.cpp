#include<cstdio>
#include<cstdlib>
#include<cstring>
int dp[260][260];
inline int max(int a,int b){return a>b?a:b;}
int lcs(char* s1,char* s2){
    int l1=strlen(s1+1),l2=strlen(s2+1);
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(s1[i]==s2[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[l1][l2];
}
char s1[260],s2[260];
int main(){
    scanf("%s%s",s1+1,s2+1);
    printf("%d\n",lcs(s1,s2));
    return 0;
}