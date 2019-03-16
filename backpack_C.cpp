#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;
int a[MAXN],dp[MAXN];

int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        int m;
        scanf("%d",&m);
        if(m<5){
            printf("%d\n",m);
            continue;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<n;i++){
            for(int j=m-5;j>0;j--){
                if(j>=a[i])dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
            }
        }
        printf("%d\n",m-dp[m-5]-a[n]);
    }
    return 0;
}