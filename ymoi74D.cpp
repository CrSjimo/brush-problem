#include<cstdio>
#include<cstdlib>
#include<queue>
using std::priority_queue;
using std::vector;
using std::greater;
priority_queue<int/* ,vector<int>,greater<int> */ > q;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        q.push(k);
    }
    for(int i=1;i<=n-1;i++){
        int a=q.top();q.pop();
        int b=q.top();q.pop();
        q.push((a+b)/k);
    }
    printf("%d\n",q.top());
    return 0;
}