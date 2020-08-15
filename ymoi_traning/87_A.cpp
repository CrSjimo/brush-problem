#include<cstdio>
int n,m;
int dp[42][42][42][42];
int a[355];
int num[5];
inline int max(int a,int b){
    return a>b?a:b;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for(int i=1;i<=m;i++){
        int k;scanf("%d",&k);
        num[k]++;
    }
    #define myxr(x) for(int i##x=0;i##x<=num[x];i##x++)
    #define irld(x) i##x*x
    #define pd(i,j,k,l) dp[i1+i][i2+j][i3+k][i4+l]
    dp[0][0][0][0]=a[0];
    myxr(1)myxr(2)myxr(3)myxr(4){
        int p = irld(1)+irld(2)+irld(3)+irld(4);
        if(i1)pd(0,0,0,0) = max(pd(-1,0,0,0)+a[p],pd(0,0,0,0));
        if(i2)pd(0,0,0,0) = max(pd(0,-1,0,0)+a[p],pd(0,0,0,0));
        if(i3)pd(0,0,0,0) = max(pd(0,0,-1,0)+a[p],pd(0,0,0,0));
        if(i4)pd(0,0,0,0) = max(pd(0,0,0,-1)+a[p],pd(0,0,0,0));
    }
    printf("%d\n",dp[num[1]][num[2]][num[3]][num[4]]);
    return 0;
}