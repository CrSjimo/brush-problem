#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::max_element;
using std::min_element;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int* a = (int*)malloc((n+1)*sizeof(int));
    int* p = (int*)calloc(m+1,sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i=1;i<=n;i++){
        int t = min_element(p+1,p+m+1)-p;
        //printf("t:%d %d\n",t,a[i]);
        p[t]+=a[i];
    }
    printf(("%d\n"),*max_element(p+1,p+m+1));
    return 0;
}