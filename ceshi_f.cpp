#include<stdio.h>
#include<string.h>
#include<algorithm>
int dp[300000];
int a[7];
int w[300000];
int main(){
    for(
        int cas = 0;
        ~scanf("%d%d%d%d%d%d",a+1,a+2,a+3,a+4,a+5,a+6) && (a[1] || a[2] || a[3] || a[4] || a[5] || a[6]);
    ){
        int amount = 0;
        memset(dp,0,sizeof(dp));
        memset(w,0,sizeof(w));
        printf("Collection #%d:\n",++cas);
        for(int i = 1;i<=6;i++){
            amount+=(i*a[i]);
        }
        if(amount%2){
            printf("Can't be divided.\n\n");
            continue;
        }
        amount/=2;
        int totW = 0;
        for(int i = 1;i<=6;i++){
            for(int j = 1;j<=a[i];j*=2){
                w[totW++] = j*i;
                a[i]-=j;
            }
            if(a[i]>0){
                w[totW++] = a[i]*i;
            }
        }
        for(int i = 0;i<totW;i++){
            for(int j = amount;j>=w[i];j--){
                dp[j] = std::max(dp[j],dp[j-w[i]]+w[i]);
            }
        }
        printf(dp[amount]==amount?"Can be divided.\n\n":"Can't be divided.\n\n");
    }
}