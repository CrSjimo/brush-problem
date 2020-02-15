#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::sort;
struct Range{
    int l,r;
}* a;
int n;
bool cmp(Range r1,Range r2){
    return r1.r<r2.r;
}
int main(){
    scanf("%d",&n);
    a = (Range*)malloc((n+1)*sizeof(Range));
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].l,&a[i].r);
    }
    sort(a+1,a+n+1,cmp);
    int bp = -19260817;
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(a[i].l>bp){
            ans++;
            bp=a[i].r;
        }
    }
    printf("%d\n",ans);
    return 0;
}
