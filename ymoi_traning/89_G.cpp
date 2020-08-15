#include<cstdio>
#include<cstdlib>
#include<deque>
using std::deque;
struct Node{
    int i;long long s;
    Node(int i,long long s){
        this->i=i;this->s=s;
    }
};

int n,k;
long long* a;
long long* dp;

deque<Node> q;

int main(){
    scanf("%d%d",&n,&k);
    a=(long long*)calloc(n+1,sizeof(long long));
    dp=(long long*)calloc(n+1,sizeof(long long));
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        a[i]+=a[i-1];
    }
    q.push_back(Node(0,0));
    for(int i=1;i<=n;i++){
        while((!q.empty())&&q.front().i<i-k-1)q.pop_front();
        dp[i]=q.front().s+a[i];
        // printf("test: %d|%d %d %d %d\n",i,q.front().i,q.front().s,a[i],dp[i]);
        while((!q.empty())&&q.back().s<=dp[i]-a[i+1])q.pop_back();
        q.push_back(Node(i,dp[i]-a[i+1]));
    }
    printf("%lld\n",dp[n]);
    return 0;
}