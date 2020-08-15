#include<cstdio>
#include<cstdlib>
int* a;
int* dp;
int* pd;
int n;
int main(){
    scanf("%d",&n);
    a=(int*)malloc((n+1)*sizeof(int));
    dp=(int*)calloc((n+1),sizeof(int));
    pd=(int*)calloc((n+1),sizeof(int));
    dp[1]=pd[1]=1;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        if(i==1)continue;
        if(a[i]>a[i-1]){
            dp[i]=pd[i-1]+1;
            pd[i]=pd[i-1];
        }else if(a[i]<a[i-1]){
            pd[i]=dp[i-1]+1;
            dp[i]=dp[i-1];
        }else{
            dp[i]=dp[i-1];
            pd[i]=pd[i-1];
        }
    }
    printf("%d\n",dp[n]>pd[n]?dp[n]:pd[n]);
    return 0;
}