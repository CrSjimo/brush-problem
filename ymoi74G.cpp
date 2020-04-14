#include<cstdio>
#include<cstdlib>
#include<queue>
using std::priority_queue;
using std::vector;
using std::greater;
priority_queue<long long,vector<long long>,greater<long long> > q;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        long long k;
        scanf("%lld",&k);
        q.push(k);
    }
    long long ans=0;
    for(int i=1;i<=n-1;i++){
        long long a=q.top();q.pop();
        long long b=q.top();q.pop();
        ans+=(a+b);
        q.push(a+b);
    }
    printf("%lld\n",ans);
    return 0;
}