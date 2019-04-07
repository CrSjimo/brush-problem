#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int cas;
int n;
int a[105];
bool used[25010];
int dp[25010];
void sort(int* arr,int* brr){
    int len = brr-arr;
    for(int i = 0;i<len;i++){
        int minPos = i;
        for(int j = i;j<len;j++){
            minPos = arr[j]<arr[minPos]?j:minPos;
        }
        int tmp = arr[i];
        arr[i] = arr[minPos];
        arr[minPos] = tmp;
    }
}
int main(){
    scanf("%d",&cas);
    while(cas--){
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
        }
        sort(a+1,a+1+n);
        int cnt = n;
        dp[0] = 1;
        // for(int c = 1;c<=n;c++){
           
           for(int i = 1;i<=n;i++){
            //   if(dp[i]){
            //       cnt--;
            //       continue;
            //   }
                for(int j = a[i];j<=a[n];j++){
                   dp[j]+=dp[j-a[i]];
               }
               
           }
           cnt = 0;
           for(int i = 1;i<=n;i++){
               if(dp[a[i]]==1)cnt++;
           }
        // }
        printf("%d\n",cnt);
    }
    return 0;
}