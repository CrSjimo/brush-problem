#include<cstdio>
#include<cstdlib>
typedef long long ll;
struct Node{
    ll sum;
    ll tag;
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
}
void build(od){
    if(l==r){
        tree[o].sum=a[l];
        return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    push_up(o);
}
void push_down(od){
    if(!tree[o].tag)return;
    tree[lc].tag+=tree[o].tag;
    tree[rc].tag+=tree[o].tag;
    tree[lc].sum+=tree[o].tag*(mid-l+1);
    tree[rc].sum+=tree[o].tag*(r-mid);
    tree[o].tag=0;
}
ll query(od,int ql,int qr){
    if(l>=ql&&r<=qr){
        return tree[o].sum;
    }
    ll ans=0;
    push_down(oq);
    if(ql<=mid){
        ans+=query(lcq,ql,qr);
    }
    if(qr>mid){
        ans+=query(rcq,ql,qr);
    }
    return ans;
}
void update(od,int ql,int qr,ll val){
    if(l>=ql&&r<=qr){
        tree[o].tag+=val;
        tree[o].sum+=val*(r-l+1);
        return;
    }
    push_down(oq);
    if(ql<=mid){
        update(lcq,ql,qr,val);
    }
    if(qr>mid){
        update(rcq,ql,qr,val);
    }
    push_up(o);
}
int main(){
    int n,q;scanf("%d%d",&n,&q);
    a=(int*)malloc((n+1)*sizeof(int));
    tree=(Node*)calloc((n+1)<<2,sizeof(Node));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    build(1,1,n);
    while(q--){
        int op,ql,qr;scanf("%d%d%d",&op,&ql,&qr);
        if(op==1){
         
            update(1,1,n,ql,ql,qr);
        }else{
            printf("%lld\n",query(1,1,n,ql,qr));
        }
    }
    return 0;
}