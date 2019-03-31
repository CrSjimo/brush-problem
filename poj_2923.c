#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int c[2];
int w[110];
bool taken[110];
int dp[1010][1010];
int n;
int max(int a,int b){
    return a>b?a:b;
}
struct node{
    int c;
    struct node* next;
};
int main(){
    int t;
    scanf("%d",&t);
    int sss = 0;
    while(t--){
        scanf("%d%d%d",&n,c,c+1);
        for(int i = 1;i<=n;i++){
            scanf("%d",w+i);
        }
        int cnt = n;
        int times = 0;
        while(n)
        {
            for(int cars = 0;cars<2;cars++){
                memset(dp,0,sizeof(dp));
                memset(taken,0,sizeof(taken));
                for(int i = 1;i <= n;i++){
                    for(int j = 0;j<=c[cars];j++){
                        if(j>=w[i]){
                            if(dp[i-1][j] < dp[i-1][j-w[i]]+w[i]){
                                taken[i] = 1;
                            }
                            dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+w[i]);
                        }else{
                            dp[i][j] = dp[i-1][j];
                        } 
                    }
                }
                for(int i = 1;i<=n;i++){
                    if(taken[i]){
                        for(int k = i;k<n;k++){
                            w[k] = w[k+1];
                            n--;
                        }
                    }
                }
                printf("test%d\n",times);
            }
            times++;
        }
        printf("Scenario #%d:\n%d\n\n",++sss,times);
    }
}