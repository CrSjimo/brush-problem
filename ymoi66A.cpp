#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::sort;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int* a = (int*)malloc((n+1)*sizeof(int));
    int* p = (int*)calloc(sizeof(int),(m+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    sort(a+1,a+n+1);
    int j = 0,ans = 0;
    for(int i=1;i<=n;i++){
        j = (j%m)+1;
        p[j]+=a[i];
        ans+=p[j];
    }
    printf("%d",ans);
    return 0;
}