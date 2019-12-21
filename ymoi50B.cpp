#include<stdio.h>
#include<vector>
std::vector<long long> fib(110);
std::vector<long long> pre(110);
int main(){
    int x,y,n;
    scanf("%d%d%d",&x,&y,&n);
    for(int i=1;i<=x;i++){
        fib[i]=1;
        pre[i]=0;
    }
    for(int i=x+1;i<=n+1;i++){
        pre[i]=y*fib[i-x];
        fib[i]=fib[i-1]+pre[i-2];
    }
    printf("%lld\n",fib[n+1]);
    return 0;
}