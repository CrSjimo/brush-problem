/*
title: Best Cow Fences
category: 二分 二分答案
*/
#include<cstdio>
#include<cstdlib>
int n;
int L;
int* a;
double* f;
#include<algorithm>
using std::min;
using std::max;
const double EPSLN = 1e-6;
int binary(double l,double r){
    while(r-l>=EPSLN){
        double mid = l+(r-l)/2.0;
        for(int i=1;i<=n;i++){
            f[i]=f[i-1]+a[i]-mid;
        }
        double minn = 1e16,maxn = -1e16;
        /*找到最大子段和*/
        for(int i=L;i<=n;i++){
            minn=min(minn,f[i-L]);
            maxn=max(maxn,f[i]-minn);
        }
        if(maxn>0){
            l=mid;
        }else{
            r=mid;
        }
    }
    return (int)(r*1000);
}
int main(){
    scanf("%d%d",&n,&L);
    a=(int*)calloc((n+1),sizeof(int));
    f=(double*)calloc((n+1),sizeof(double));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    printf("%d\n",binary(0,1e5));
    return 0;
}