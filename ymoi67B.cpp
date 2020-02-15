#include<cstdio>
#include<cstdlib>
int* a;
void paws(int* a,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}
void slowsort(int l,int r){
    int i=l,j=r,k=a[(l+r)>>1];
    while(i<j){
        while(a[i]<k) ++i;
        while(a[j]>k) --j;
        if(i<=j){
            paws(&a[i++],&a[j--]);
        }
    }
    if(l<j)slowsort(l,j);
    if(i<r)slowsort(i,r);
}
int main(){
    int n;
    scanf("%d",&n);
    a = (int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    slowsort(1,n);
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}