// #include<stdio.h>
// #include<string.h>
// long long dp[30010];
// int a[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
// int main(){
//     dp[0]=1;
//     for(int i=0;i<11;i++){
//         for(int j=a[i];j<=30001;j++){
//             dp[j]+=dp[j-a[i]];
//         }
//     }
//     double n1;
//     while(~scanf("%lf",&n1)&&n1){
//         int n = (int)(100*n1+0.5);
//         printf("%6.2f%17lld\n",n1,dp[n]);
//     }
//     return 0;
// }
#include<stdio.h>
int dp[10010];
int a[5]={1,5,10,25,50};
int main(){
    dp[0]=1;
    for(int i=0;i<5;i++){
        for(int j=a[i];j<=8000;j++){
            dp[j]+=dp[j-a[i]];
        }
    }
    int n;
    while(~scanf("%d",&n)){
        printf("%d\n",dp[n]);
    }
    return 0;
}