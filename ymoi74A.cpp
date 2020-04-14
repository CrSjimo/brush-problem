#include<cstdio>
#include<cstdlib>
#include<queue>
using std::priority_queue;
using std::vector;
using std::greater;
priority_queue<int,vector<int>,greater<int> > q;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        q.push(k);
    }
    int ans=0;
    for(int i=1;i<=n-1;i++){
        int a=q.top();q.pop();
        int b=q.top();q.pop();
        ans+=(a+b);
        q.push(a+b);
    }
    printf("%d\n",ans);
    return 0;
}