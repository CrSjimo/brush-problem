#include<cstdio>
#include<cstdlib>

int* tmp;
int* a;

void merge(int l,int m,int r){
    int i=l,j=m+1,k=l;
    for(;;){
        if(i<=m&&j<=r){
            if(a[i]<a[j]){
                tmp[k++]=a[i++];
            }else{
                tmp[k++]=a[j++];
            }
        }else if(i<=m&&j>r){
            tmp[k++]=a[i++];
        }else if(i>m&&j<=r){
            tmp[k++]=a[j++];
        }else{
            break;
        }
    }
}
void merge_sort(int l,int r){
    if(l<r){
        int m=(l+r)>>1;
        merge_sort(l,m);
        merge_sort(m+1,r);
        merge(l,m,r);
        for(int i=l;i<=r;i++){
            a[i]=tmp[i];
        }
    }
}
int main(){
    int n;scanf("%d",&n);
    tmp=(int*)malloc((n+1)*sizeof(int));
    a=(int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    merge_sort(1,n);
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
