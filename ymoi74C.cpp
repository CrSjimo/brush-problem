#include<cstdio>
#include<cstdlib>
#include<queue>
using std::max;
using std::priority_queue;
struct Node{
    int w;
    int i;
    Node(int w,int i){
        this->w=w;
        this->i=i;
    }
    bool operator<(const Node& nd)const{
        return w<nd.w;
    }
};
struct tr{
    int m;
    int d;
    int t;
}* a;
int main(){
    int n;scanf("%d",&n);
    a=(tr*)malloc((n+1)*sizeof(tr));
    for(int i=1;i<=n;i++)scanf("%d",&a[i].m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].d);
    for(int i=1;i<=n-1;i++)scanf("%d",&a[i].t);
    int dl;scanf("%d",&dl);
    int maxn=0,trd=0;
    priority_queue<Node> q;
    for(int i=1;i<=n;i++){
        int ans=0;
        int time=dl-trd;
        for(int j=1;j<=i;j++){
            q.push(Node(a[j].m,j));
        }
        while(time>0&&q.top().w>0){
            Node u=q.top();q.pop();
            ans+=u.w;
            u.w-=a[u.i].d;
            q.push(u);
            time--;
        }
        maxn=max(maxn,ans);
        trd+=a[i].t;
    }
    printf("%d\n",maxn);
    return 0;
}
