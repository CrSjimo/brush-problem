#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cctype>
#include<queue>
using std::priority_queue;
using std::max;
using std::min;
typedef long long ll;
int* lg;
int** st;
int* val;
ll* f;
namespace rmq{
    bool cmp(int a,int b){
        return f[a]<f[b];
    }
    void init(int n){
        lg=(int*)calloc((n+1),sizeof(int));
        lg[1]=0;
        for(int i=2;i<=n;i++){
            lg[i]=lg[i>>1]+1;
        }
        st=(int**)malloc((n+1)*sizeof(int*));
        int L=lg[n];
        for(int i=1;i<=n;i++){
            st[i]=(int*)calloc((L+1),sizeof(int));
            st[i][0]=i;
        }
        for(int j=0;j+1<=L;j++){
            for(int i=1;i+((1<<(j+1)))-1<=n;i++){
                st[i][j+1]=max(st[i][j],st[i+(1<<j)][j],cmp);
            }
        }
    }
    int query(int l,int r){
        int L=lg[r-l+1];
        return max(st[l][L],st[r-(1<<L)+1][L],cmp);
    }
}
struct Node{
    int x;
    int l,r;
    int pos;
    Node(int x,int l,int r){
        this->x=x;
        this->l=l;
        this->r=r;
        this->pos=rmq::query(l,r);
    }
    inline ll calc()const{
        return f[pos]-f[x-1];
    }
    bool operator<(const Node& a)const{
        return calc()<a.calc();
    }
};
priority_queue<Node> q;
int main(){
    int n,k,l,r;scanf("%d%d%d%d",&n,&k,&l,&r);
    val=(int*)malloc((n+1)*sizeof(int));
    f=(ll*)malloc((n+1)*sizeof(ll));
    for(int i=1;i<=n;i++){
        scanf("%d",val+i);
        f[i]=f[i-1]+val[i];
    }
    rmq::init(n);
    for(int i=1;i+l-1<=n;i++){
        q.push(Node(i,i+l-1,min(i+r-1,n)));
    }
    ll ans=0;
    while(k--){
        Node a=q.top();q.pop();
        ans+=a.calc();
        if(a.pos!=a.l){
            q.push(Node(a.x,a.l,a.pos-1));
        }
        if(a.pos!=a.r){
            q.push(Node(a.x,a.pos+1,a.r));
        }
    }
    printf("%lld\n",ans);
    return 0;
}
