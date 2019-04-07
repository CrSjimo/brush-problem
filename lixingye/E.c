#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int cas;
int n;
int a[105];
bool used[25010];
int dp[25010];
int sort(int* arr,int* brr){
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
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
        }
        sort(a+1,a+1+n);
        int cnt = n;
        for(int c = 1;c<=n;c++){
           memset(dp,0,sizeof(dp));
           dp[0] = 1;
           for(int i = 1;i<c;i++){
              if(used[i])continue;
                for(int j = a[i];j<=a[c];j++){
                   dp[j]+=dp[j-a[i]];
               }
               if(dp[a[c]]){
                   cnt--;
                   used[c] = 1;
               }
           }
        }
        printf("%d\n",cnt);
    }
    return 0;
}