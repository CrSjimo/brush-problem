#include<cstdio>
#include<cstdlib>
typedef long long ll;
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
template<typename T>inline T& min(T&a,T&b){
    return a<b?a:b;
}
struct Node{
    int minn;
    int tag;
}* tree;
int* a;
inline void push_up(int o){
    tree[o].minn = min(tree[lc].minn,tree[rc].minn);
}
void build(int o,int l,int r){
    tree[o].tag=0;
    if(l==r){
        tree[o].minn=a[l];
        return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    push_up(o);
}
inline void push_down(int o){
    if(tree[o].tag){
        tree[lc].minn-=tree[o].tag;
        tree[rc].minn-=tree[o].tag;
        tree[lc].tag+=tree[o].tag;
        tree[rc].tag+=tree[o].tag;
        tree[o].tag=0;
    }
}
int currentQuery = 0;
void update(int o,int l,int r,int ql,int qr,int v){
    if(ql<=l&&r<=qr){
        tree[o].tag+=v;
        tree[o].minn-=v;
        if(tree[o].minn<0){
            printf("-1\n%d\n",currentQuery);
            exit(0);
        }
        return;
    }
    push_down(o);
    if(ql<=mid)update(lc,l,mid,ql,qr,v);
    if(qr>mid)update(rc,mid+1,r,ql,qr,v);
    push_up(o);
}
int main(){
    int n,m;scanf("%d%d",&n,&m);
    a=(int*)malloc((n+1)*sizeof(int));
    tree=(Node*)malloc((n<<2|2)*sizeof(Node));
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int d,s,j;
        scanf("%d%d%d",&d,&s,&j);
        currentQuery=i;
        update(1,1,n,s,j,d);
    }
    printf("0\n");
    return 0;
}