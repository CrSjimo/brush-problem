#include<cstdio>
#include<cstdlib>
#include<algorithm>
int** a;
int main(){
    int n;scanf("%d",&n);
    a = (int**)malloc((n+1)*sizeof(int*));
    for(int** p = a;p<=a+n;p++)*p = (int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        a[i][i]=0;
        for(int j=i+1;j<=n;j++){
            scanf("%d",&a[i][j]);
            a[j][i]=a[i][j];
        }
    }
    int ans = -19260817;
    for(int i=1;i<=n;i++){
        std::sort(a[i]+1,a[i]+n+1);
        ans = a[i][n-1]>ans?a[i][n-1]:ans;
    }
    printf("1\n%d\n",ans);
    return 0;
}