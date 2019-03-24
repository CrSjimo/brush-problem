#include <stdio.h>
int n,k;
long long very_fucking_big = 1e18;
long long dpH[1010];
long long dpL[1010];
int main(){
    scanf("%d%d",&n,&k);
    dpL[0]=1;
    for(int i=1;i<=k;i++){
        for(int j=i;j<=n;j++){
            dpH[j]+=(dpH[j-i]+(dpL[j]+dpL[j-i])/very_fucking_big);
            dpL[j]=(dpL[j]+dpL[j-i])%very_fucking_big;
        }
    }
    if(dpH[n]!=0)printf("%lld",dpH[n]);
    printf("%lld",dpL[n]);
    return 0;
}