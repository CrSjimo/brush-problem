#include <stdio.h>
#include <string.h>
int n;
#define M 10010
int dp[M];
int cnt[M];
int next[M];
int result[M];
int a[4]={1,5,10,25};
int main(){
    int m[5];
    while(
        ~scanf("%d%d%d%d%d",&n,m,m+1,m+2,m+3) 
        &&
        (n||m[0]||m[1]||m[2]||m[3])
    ){  
        memset(dp,0,sizeof(dp));
        
        memset(result,0,sizeof(result));
        memset(next,0,sizeof(next));
        dp[0]=1;
        for(int i=0;i<4;i++){
            memset(cnt,0,sizeof(cnt));
            for(int j=a[i];j<=n;j++){
                if(
                    cnt[j-a[i]]<m[i] && //这种情况能买得起
                    dp[j-a[i]] != 0 && //且不为零
                    dp[j-a[i]] > dp[j]-1 //还要比现在多花一枚硬币要大
                ){
                    dp[j] = dp[j-a[i]]+1;
                    cnt[j] = cnt[j-a[i]]+1;
                    next[j] = j-a[i];
                }
            }
            
        }
        if(dp[n] == 0){
            printf("Charlie cannot buy coffee.\n");
            continue;
        }
        //好像有种kmp的感觉
        //干就完了,不知道能不能行
        for(int i = n;i;i=next[i]){
            result[i-next[i]]+=1;
        }
        printf(
            "Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",
            result[a[0]],
            result[a[1]],
            result[a[2]],
            result[a[3]]
        );
    }
    return 0;
}