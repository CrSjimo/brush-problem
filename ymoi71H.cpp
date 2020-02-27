#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::min;
using std::max;
int* a;
int* s;
int** dp;
int n,m;
void pirnt(int i){
    if(i==0)return;
    //printf("test %d %d\n",i,k);
    int p=0;
    for(int j=i;j>=1;j--){
        if(p+a[j]>dp[m][n]){
            pirnt(j);
            printf("%d %d\n",j+1,i);
            return;
        }
        p+=a[j];
    }
    printf("1 %d\n",i);
}
int main(){
    scanf("%d%d",&n,&m);
    a=(int*)malloc((n+1)*sizeof(int));
    s=(int*)malloc((n+1)*sizeof(int));s[0]=0;
    dp=(int**)malloc((m+1)*sizeof(int*));
    for(int** p=dp;p<=dp+m;p++)memset(*p=(int*)malloc((n+1)*sizeof(int)),0x3f,(n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        s[i]=s[i-1]+a[i];
        dp[1][i]=s[i];
    }
    for(int k=2;k<=m;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i-1;j++){
                dp[k][i]=min(dp[k][i],max(s[i]-s[j],dp[k-1][j]));
            }
        }
    }
    pirnt(n);
    return 0;
}