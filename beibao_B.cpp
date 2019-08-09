#include<stdio.h>
#include<string.h>
#include<algorithm>
int dp[50010];
int w[15],c[15];
int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        int x,y;
        scanf("%d%d",&x,&y);
        int n;
        scanf("%d",&n);
        for(int i = 0;i<n;i++){
            scanf("%d%d",w+i,c+i);
            w[i]/=1000;
        }
        for(int d = 0;d<y;d++){
            memset(dp,0,sizeof(dp));
            int a = x/1000;
            for(int i = 0;i<n;i++){
                for(int j = w[i];j<=a;j++){
                    dp[j] = std::max(dp[j-w[i]]+c[i],dp[j]);
                }
            }
            x+=dp[a];
        }
        printf("%d\n",x);
    }
    return 0;
}