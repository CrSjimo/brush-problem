#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
std::vector< std::vector<int> > dp;
int n;
void floyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][k]!=0x3f3f3f3f&&dp[k][j]!=0x3f3f3f3f){
                    dp[i][j]=std::min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
    }
}
int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        int d;
        scanf("%d%d",&n,&d);
        dp = std::vector< std::vector<int> >(n+5,std::vector<int>(n+5,0x3f3f3f3f));
        for(int i = 0;i<n;i++){
            dp[i][i]=0;
        }
        for(int i=0;i<n;i++){
            std::string s;
            std::cin>>s;
            for(int j=0;j<n;j++){
                dp[i][j]=(s[j]=='Y'?1:dp[i][j]);
            }
        }
        floyd();
        int maxn = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]!=0x3f3f3f3f){
                    maxn=std::max(maxn,dp[i][j]);
                }else{
                    printf("-1\n");
                    goto match;
                }
            }
        }
        maxn*=d;
        printf("%d\n",maxn);
        match:;
    }
    return 0;
}