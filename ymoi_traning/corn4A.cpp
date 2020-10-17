#include<cstdio>
int main(){
    freopen("young.in","r",stdin);
    freopen("young.out","w",stdout);
    int l,r;scanf("%d%d",&l,&r);
    printf("%d\n%d\n%d\n%lld\n",1,r,l,1ll*r*(r-1));
    return 0;
}