#include<stdio.h>
#include<string.h>
#define MAXN 200000
#define INF 1e9
int a[105];
int b[105];
int dp[MAXN+10];
int n;
int s=0;
int max(int x,int y){
    return x>y?x:y;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",a+i,b+i);
        s+=a[i];
    }
    for(int i=0;i<sizeof(dp)/sizeof(int);i++){
        dp[i] = -INF;
    }
    dp[100000] = 0;
    // printf("%d",dp[1]);
    for(int i=0;i<n;i++){
        if(a[i]>0){
            for(int j=MAXN;j>=a[i];j--){
                // printf("%d",j);
                if(dp[j-a[i]]>-INF)
                    dp[j] = max(dp[j],dp[j-a[i]]+b[i]);
            }
        }else{
            for(int j=a[i];j<=MAXN+a[i];j++){
                if(dp[j-a[i]]>-INF)
                    dp[j] = max(dp[j],dp[j-a[i]]+b[i]);
            }
        }
    }
    int ans = -INF;
    for(int i=100000;i<MAXN;i++){
        if(dp[i]>0){
            ans = max(ans,dp[i]+i-100000);
        }
    }
    printf("%d\n",max(ans,0));
    return 0;
    //g++ ./poj_2184.c -o ./poj_2184.exe &&./poj_2184.exe
}