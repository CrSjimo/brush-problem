#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using std::max;
using std::min;
using std::max_element;
int** a;
int** dp;
int main(){
    int f,v;
    scanf("%d%d",&f,&v);
    a=(int**)malloc((f+1)*sizeof(int*));
    for(int** p=a;p<=a+f;p++)*p=(int*)malloc((v+1)*sizeof(int));
    dp=(int**)malloc((f+1)*sizeof(int*));
    for(int** p=dp;p<=dp+f;p++)memset(*p=(int*)malloc((v+1)*sizeof(int)),0x80,(v+1)*sizeof(int));
    for(int i=1;i<=f;i++){
        for(int j=1;j<=v;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=v-f+1;i++){
        dp[1][i]=a[1][i];
    }
    for(int i=2;i<=f;i++){
        for(int j=i;j<=v-f+i;j++){
            for(int k=i-1;k<=j-1;k++){
                dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
            }
        }
    }
    printf("%d\n",*max_element(dp[f]+f,dp[f]+v+1));
    return 0;
}