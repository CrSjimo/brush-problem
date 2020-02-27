#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using std::min;
int** dp;
int* a;
int* b;
int* w;
int main(){
    int m1,m2;
    scanf("%d%d",&m1,&m2);
    dp=(int**)malloc((m1+1)*sizeof(int*));
    for(int** p=dp;p<=dp+m1;p++)memset(*p=(int*)malloc((m2+1)*sizeof(int)),0x3f,(m2+1)*sizeof(int));
    int n;scanf("%d",&n);
    a=(int*)malloc((n+1)*sizeof(int));
    b=(int*)malloc((n+1)*sizeof(int));
    w=(int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",a+i,b+i,w+i);
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=m1;j>=0;j--){
            for(int k=m2;k>=0;k--){
                int jj=j+a[i]>m1?m1:j+a[i],kk=k+b[i]>m2?m2:k+b[i];
                dp[jj][kk]=min(dp[jj][kk],dp[j][k]+w[i]);
            }
        }
    }
    printf("%d\n",dp[m1][m2]);
    return 0;
}