/*
title: 加工生产调度
category: 贪心
*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::sort;
using std::min;
using std::max;
int* a;
int* b;
struct Node{
    int v,i;
    bool operator<(const Node& nd)const{
        return v<nd.v;
    }
}* minv;
int* list;
int* ptl;
int* ptr;
template<typename T>T* _alloc(T*& p,size_t siz){
    return p=(T*)calloc(siz,sizeof(T));
}
int main(){
    int n;scanf("%d",&n);
    _alloc(a,n+1);
    _alloc(b,n+1);
    _alloc(minv,n+1);
    _alloc(list,n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",b+i);
        minv[i].v = min(a[i],b[i]);
        minv[i].i = i;
    }

    /*将每项生产按照A, B中耗费最少的时间为关键字从小到大排序。遍历每项生产i，如果A加工i的时间较少，就把这项生产放到前面；否则放到后面*/
    sort(minv+1,minv+n+1);
    ptl = list+1;
    ptr = list+n;
    for(int i=1;i<=n;i++){
        if(minv[i].v == a[minv[i].i]){
            *ptl = minv[i].i;
            ptl++;
        }else{
            *ptr = minv[i].i;
            ptr--;
        }
    }
    int aa=0,bb=0;
    for(int i=1;i<=n;i++){
        aa+=a[list[i]];
        bb+=max(aa-bb,0);
        bb+=b[list[i]];
    }
    printf("%d\n",bb);
    for(int i=1;i<n;i++){
        printf("%d ",list[i]);
    }
    printf("%d\n",list[n]);
    return 0;
}
