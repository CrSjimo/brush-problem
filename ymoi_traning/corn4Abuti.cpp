#include<cstdio>
int main(){
    freopen("young.in","r",stdin);
    freopen("young.out","w",stdout);
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n%d\n%d\n%lld\n",a==b?a:1,b,a,a==b?1ll*a:1ll*b*(b-1));
    return 0;
}