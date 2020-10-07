#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::swap;
using std::max;
typedef long long ll;
struct Node{
    ll sum;
    ll maxn;
    int maxarg;
}* tree;
int* a;
#define mid ((l+r)>>1)
#define lc (o<<1)
#define rc (o<<1|1)
#define lcq lc,l,mid
#define rcq rc,mid+1,r
#define oq o,l,r
#define od int o,int l,int r
void push_up(int o){
    tree[o].sum = tree[lc].sum+tree[rc].sum;
    if(tree[lc].maxn>tree[rc].maxn){
        tree[o].maxn=tree[lc].maxn;
        tree[o].maxarg=tree[lc].maxarg;
    }else{
        tree[o].maxn=tree[rc].maxn;
        tree[o].maxarg=tree[rc].maxarg;
    }
}
void build(od){
    if(l==r){
        tree[o].sum=a[l];
        tree[o].maxn=a[l];
        tree[o].maxarg=l;
        return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    push_up(o);
}
inline void combine(Node& ans,Node b){
    ans.sum+=b.sum;
    if(b.maxn>ans.maxn){
        ans.maxn=b.maxn;
        ans.maxarg=b.maxarg;
    }
}
Node query(od,int ql,int qr){
    if(l>=ql&&r<=qr){
        return tree[o];
    }
    Node ans=(Node){0,0,0};
    if(ql<=mid){
        combine(ans,query(lcq,ql,qr));
    }
    if(qr>mid){
        combine(ans,query(rcq,ql,qr));
    }
    return ans;
}
void update(od,int q,ll val){
    if(l==r){
        tree[o].sum+=val;
        return;
    }
    if(q<=mid){
        update(lcq,q,val);
    }
    if(q>mid){
        update(rcq,q,val);
    }
    push_up(o);
}
#undef mid
#undef lc
#undef rc
#undef lcq
#undef rcq
#undef oq
#undef od
char op[4];
int n;
ll* f;

inline int lowbit(int x){return x&-x;}

void update2(int x,int val){
    for(;x<=n;x+=lowbit(x)){
        f[x]+=val;
    }
}

ll query2(int x){
    ll ans=0;
    for(;x>0;x-=lowbit(x)){
        ans+=f[x];
    }
    return ans;
}
int main(){
    int q;scanf("%d%d",&n,&q);
    a=(int*)malloc((n+1)*sizeof(int));
    f=(ll*)malloc((n+1)*sizeof(ll));
    tree=(Node*)malloc(4*(n+1)*sizeof(Node));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        update2(i,a[i]);
    }
    build(1,1,n);
    while(q--){
        scanf("%s",op);
        if(op[0]=='C'){
            int i,k;scanf("%d%d",&i,&k);
            update2(i,k);
        }else{
            int l1,r1,l2,r2;scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            if(l1>r1)swap(l1,r1);
            if(l2>r2)swap(l2,r2);
            if(l1>r2)swap(l1,l2),swap(r1,r2);
            ll ans=-19260817114514;
            for(int i=l1;i<=r1;i++){
                for(int j=l2;j<=r2;j++){
                    if(i>j)continue;
                    ans=max(ans,query2(j)-query2(i-1));
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}