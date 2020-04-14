#include<cstdio>
#include<cstdlib>
#include<queue>
#include<algorithm>
using std::sort;
using std::priority_queue;
#define int long long
struct Node{
    int w,t;
    bool operator<(const Node& nd)const{
        return w>nd.w;
    }
    Node(int w,int t){
        this->w=w;
        this->t=t;
    }
}* a;
bool cmp(const Node& nd1,const Node& nd2){
    return nd1.t<nd2.t;
}
int32_t main(){
    int n;scanf("%lld",&n);
    a=(Node*)malloc((n+1)*sizeof(Node));
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i].t,&a[i].w);
    }
    sort(a+1,a+1+n,cmp);
    priority_queue<Node> q;
    for(int i=1;i<=n;i++){
        if(q.size()<a[i].t){
            q.push(a[i]);
        }else if(q.top().w<a[i].w){
            q.pop();
            q.push(a[i]);
        }
    }
    int ans=0;
    while(!q.empty()){
        ans+=q.top().w;q.pop();
    }
    printf("%lld\n",ans);
    return 0;
}