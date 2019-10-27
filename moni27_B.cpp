#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
struct TT{
    int x;
    int t;
    long long tvpx;
    long long tvmx;
};
int n,v;
bool cmp(TT a,TT b){
    return a.tvpx<b.tvpx;
}
bool cmp2(TT a,TT b){
    return a.tvmx<b.tvmx;
}
TT list[100010];
TT list2[100010];
long long b[100010];
long long dp[100010];
long long b2[100010];
long long dp2[100010];
int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        TT& a=list[i];
        scanf("%d%d",&a.x,&a.t);
    }
    scanf("%d",&v);
    for(int i=1;i<=n;i++){
        TT& a=list[i];
        a.tvpx=a.t*v+a.x;
        a.tvmx=a.t*v-a.x;
        list2[i]=list[i];
        //printf("test1:%d\n",a.tvmx);
    }
    std::sort(list,list+1+n,cmp);
    std::sort(list2+1,list2+1+n,cmp);
    TT zero;
    zero.tvmx=0;
    int zeropos=std::lower_bound(list,list+1+n,zero,cmp2)-list;
    for(int i=0;i<=n+1;i++){
        b[i]=b2[i]=LONG_LONG_MAX;
    }
    for(int i=0;i<=n;i++){
        printf("test:%d %d\n",list[i].tvpx,list[i].tvmx);
    }
    for(int i=zeropos;i<=n;i++){
        long long* ptr=std::upper_bound(b+zeropos,b+n+zeropos+1,list[i].tvmx);
        *ptr = std::min(*ptr,list[i].tvmx);
        dp[i]=ptr-b;
    }
    long long maxn=-1;
    for(int i=0;i<=n;i++){
        maxn=std::max(maxn,dp[i]);
    }
    printf("%d ",maxn-1);
    for(int i=1;i<=n;i++){
        long long* ptr=std::upper_bound(b2+1,b2+n+2,list2[i].tvmx);
        *ptr = std::min(*ptr,list2[i].tvmx);
        dp[i]=ptr-b2;
    }
    maxn=-1;
    for(int i=1;i<=n;i++){
        maxn=std::max(maxn,dp[i]);
    }
    printf("%d\n",maxn);
    return 0;
}