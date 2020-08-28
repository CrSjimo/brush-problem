#include<cstdio>
#include<cstdlib>
#include<utility>
using std::swap;

const int MAXN=114514-11451-1145-114-11-1;

typedef long long ll;

const int MAGIC=19260817;

struct Node{
    ll val;
    int ls,rs,d;
} f[MAXN];

bool del[MAXN];

int rt[MAXN];
namespace bcj{
    int f[MAXN];
    void init(){
        for(int i=0;i<MAXN-5;i++){
            f[i]=rt[i]=i;
        }
    }
    int find(int x){
        return f[x]==x?x:f[x]=find(f[x]);
    }
    void update(int,int);
}
int merge(int x,int y){
    if(x==0||y==0)return x|y;
    if(f[x].val>f[y].val){
        swap(x,y);
    }
    f[x].rs=merge(f[x].rs,y);
    if(f[f[x].ls].d<f[f[x].rs].d){
        swap(f[x].ls,f[x].rs);
    }
    f[x].d=f[f[x].rs].d+1;
    return x;
}
void bcj::update(int x,int y){
    if(del[x]||del[y])return;
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    rt[fx]=merge(rt[fx],rt[fy]);
    f[fy]=fx;
}
ll pop(int x){
    if(del[x])return -1;
    int fx=bcj::find(x);
    ll ans=f[rt[fx]].val;
    del[rt[fx]]=true;
    rt[fx]=merge(f[rt[fx]].ls,f[rt[fx]].rs);
    return ans/MAGIC;
}
int main(){
    bcj::init();
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        f[i].val=1ll*k*MAGIC+i;
        f[i].d=1;
    }
    while(m--){
        int op,x,y;scanf("%d%d",&op,&x);
        if(op==1){
            scanf("%d",&y);
            bcj::update(x,y);
        }else if(op==2){
            printf("%lld\n",pop(x));
        }
    }
    return 0;
}