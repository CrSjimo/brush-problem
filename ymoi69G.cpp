#include<cstdio>
#include<cstdlib>
int* a;
int* dp1;
int* dp2;
#include<vector>
using std::vector;
using std::max;
int main(){
    int n;scanf("%d",&n);
    a=(int*)malloc((n+1)*sizeof(int));
    dp1=(int*)calloc(n+1,sizeof(int));
    dp2=(int*)calloc(n+1,sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int maxn=0;
        for(int j=1;j<i;j++){
            if(a[j]<a[i]){
                maxn = max(maxn,dp1[j]);
            }
        }
        dp1[i]=maxn+1;
    }
    for(int i=n;i>=1;i--){
        int maxn=0;
        for(int j=n;j>i;j--){
            if(a[j]<a[i]){
                maxn = max(maxn,dp2[j]);
            }
        }
        dp2[i]=maxn+1;
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,dp1[i]+dp2[i]);
    }
    printf("%d\n",n-ans+1);
    return 0;
}