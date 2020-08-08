/*
title: 埃及分数
category: DFS
*/
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
typedef long long ll;
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
struct Frac{
    Frac(){};
    Frac(ll a,ll b){num=a;deno=b;}
    ll num;
    ll deno;
    void red(){
        ll GCD = gcd(deno,num);
        num/=GCD;deno/=GCD;
    }
    int cmp(const Frac& fr){
        int q = num*fr.deno-fr.num*deno;
        if(q>0)return 1;
        if(q==0)return 0;
        if(q<0)return -1;
    }
    Frac operator -(const Frac& fr){
        int n_num=num*fr.deno-fr.num*deno;
        int n_deno = deno*fr.deno;
        Frac n_fr = Frac(n_num,n_deno);
        n_fr.red();
        return n_fr;
    }
};
int a[30];
int ans[30];
Frac target;
int minm=22;
int minlast = 1048580;
int sa,sb;
void dfs(int i,Frac fr){
    if(i>minm)return;
    if(fr.num==0){
        if(i<minm||(i==minm&&a[i-1]<minlast)){
            minlast=a[i-1];
            minm = i;
            memcpy(ans,a,sizeof(a));
        }
        return;
    }
    if(i==minm)return;
    int lowB = (int)ceil(1.0*fr.deno/fr.num);
    int uprB = (int)ceil(2.0*fr.deno/fr.num);
    if(lowB<=a[i-1])lowB=a[i-1]+1;
    for(int x = lowB;x<=uprB;x++){
        if(x>minlast)break;
        //if(1LL*(minm-i+1)*sb<=1LL*sa*i)break;
        a[i]=x;
        dfs(i+1,fr-Frac(1,x));
    }
}
int main(){
    int a,b;scanf("%d%d",&a,&b);
    sa=a;sb=b;
    target = Frac(a,b);
    dfs(1,target);
    for(int i=1;ans[i];i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}