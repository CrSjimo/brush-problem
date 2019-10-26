#include<stdio.h>
int n;
int a[100010];
int* sliceMin(int* start,int* end){
    int* minPtr = start;
    for(int* i = start;i<end;i++){
        minPtr = (*i)<(*minPtr)?i:minPtr;
    }
    return minPtr;
}
int tot = 0;
void p(int* l,int* r){
    if(l == r){
        // printf("%d\n",l-a);
        return;
    }
    int d = *(sliceMin(l,r));
    tot+=d;
    // printf("test\n");
    for(int* i = l;i<r;i++){
        (*i)-=d;
    }
    int* nextL = l;
    for(int* i = l;i<=r;i++){
        if((*i)==0||i==r){
            // printf("test\n");
            p(nextL,i);
            nextL = i+1;
        }
    }  
}
int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",a+i);
    }
    p(a,a+n);
    printf("%d\n",tot);
    return 0;
}