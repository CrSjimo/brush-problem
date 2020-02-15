#include<cstdio>
#include<cstdlib>
int lowerBound(int* a,int l,int r,int q){
    while(l<=r){
        int m = (l+r)>>1;
        if(a[m]<=q){
            l=m+1;
        }else{
            r=m-1;
        }
    }
    return r;
}
int main(){
    int n,m;scanf("%d%d",&n,&m);
    int* a = (int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    a[0]=-1;
    while(m--){
        int k;scanf("%d",&k);
        printf("%d\n",a[lowerBound(a,1,n,k)]);
    }
    return 0;
}