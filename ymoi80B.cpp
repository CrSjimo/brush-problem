/*
title: 生日蛋糕
category: DFS
*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using std::min;
int n,m;
int minv[25];
int minn = 0x3f3f3f3f;
void dfs(int i,int r,int h,int S,int V_rem){

    //推导过程见课件“深搜的剪枝技巧”P18
    if(2*V_rem/r+S>=minn)return;

    if(V_rem<minv[i])return;
    int maxv=0;
    for(int j=1;j<=m-i;j++){
        maxv+=(r-j)*(r-j)*(h-j);
    }
    if(V_rem>maxv)return;

    if(i==m&&V_rem==0){
        minn=min(minn,S);
        return;
    }else if(i<m){
        for(int rn=r-1;rn>=m-i;rn--){
            for(int hn=h-1;hn>=m-i;hn--){
                dfs(i+1,rn,hn,S+2*rn*hn,V_rem-rn*rn*hn);
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        minv[m-i]=minv[m-i+1]+i*i*i;
    }
    for(int r=m;r<=sqrt(n);r++){
        for(int h=n/(r*r);h>=m;h--){
            dfs(1,r,h,r*r+2*r*h,n-r*r*h);
        }
    }
    printf("%d\n",minn<0x3f3f3f3f?minn:0);
    return 0;
}