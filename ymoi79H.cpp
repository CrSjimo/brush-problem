/*
title: 曲线
category: 三分
*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::max;
struct Func{
    int a,b,c;
    double calc(double x){
        return 1.0*a*x*x+b*x+c;
    }
} a[100005];
int n;
double F(double x){
    double maxn = a[1].calc(x);
    for(int i=2;i<=n;i++){
        maxn=max(maxn,a[i].calc(x));
    }
    return maxn;
}
double epsln = 1e-11;
double ternary(double l,double r){
    while(r-l>=epsln){
        double lmid = l+(r-l)/3.0, rmid = l+(r-l)/3.0*2.0;
        if(F(lmid)>F(rmid)){
            l=lmid;
        }else{
            r=rmid;
        }
    }
    return F(l);
}
int main(){
    int cas;scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
        }
        printf("%.4lf\n",ternary(0,1000));
    }
    return 0;
}