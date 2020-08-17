#include<cstdio>
#include<cstdlib>
typedef long long ll;
struct Node{
    int sum;
    int tag;
    int lc;
    int rc;
}* tree;
int tot=1;
#define mid ((l+r)>>1)
#define lc (tree[o].lc?tree[o].lc:(tree[++tot].tag=19260817,tree[o].lc=tot))
#define rc (tree[o].rc?tree[o].rc:(tree[++tot].tag=19260817,tree[o].rc=tot))
#define lcq lc,l,mid
#define rcq rc,mid+1,r
#define oq o,l,r
#define od int o,int l,int r
void push_up(int o){
    tree[o].sum = tree[lc].sum+tree[rc].sum;
}
void build(od){
    tree[o].tag=19260817;
    if(l==r){
        tree[o].sum=1;
        return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    push_up(o);
}
void push_down(od){
    if(tree[o].tag==19260817)return;
    tree[lc].tag=tree[o].tag;
    tree[rc].tag=tree[o].tag;
    tree[lc].sum=tree[o].tag*(mid-l+1);
    tree[rc].sum=tree[o].tag*(r-mid);
    tree[o].tag=19260817;
}
int query(od,int ql,int qr){
    if(l>=ql&&r<=qr){
        return tree[o].sum;
    }
    int ans=0;
    push_down(oq);
    if(ql<=mid){
        ans+=query(lcq,ql,qr);
    }
    if(qr>mid){
        ans+=query(rcq,ql,qr);
    }
    return ans;
}
void update(od,int ql,int qr,int val){
    if(l>qr||r<ql)return;
    if(l>=ql&&r<=qr){
        tree[o].tag=val;
        tree[o].sum=val*(r-l+1);
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
    tree=(Node*)calloc(18000000,sizeof(Node));
    update(1,1,n,1,n,1);
    while(q--){
        int op,ql,qr;scanf("%d%d%d",&ql,&qr,&op);
        update(1,1,n,ql,qr,op-1);
        printf("%d\n",query(1,1,n,1,n));
    }
    return 0;
}