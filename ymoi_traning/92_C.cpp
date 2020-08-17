#include<cstdio>
#include<cstdlib>
typedef long long ll;
struct Node{
    ll sum;
    ll tag;
    ll tag2;
}* tree;
int* a;
int MOD;
#define mid ((l+r)>>1)
#define lc (o<<1)
#define rc (o<<1|1)
#define lcq lc,l,mid
#define rcq rc,mid+1,r
#define oq o,l,r
#define od int o,int l,int r
void push_up(int o){
    tree[o].sum = (tree[lc].sum+tree[rc].sum)%MOD;
}
void build(od){

    tree[o].tag2=1;

    if(l==r){
        tree[o].sum=a[l];
        return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    push_up(o);
}
void push_down(od){

    (tree[lc].tag2*=tree[o].tag2)%=MOD;
    (tree[lc].tag*=tree[o].tag2)%=MOD;
    (tree[lc].sum*=tree[o].tag2)%=MOD;

    (tree[rc].tag2*=tree[o].tag2)%=MOD;
    (tree[rc].tag*=tree[o].tag2)%=MOD;
    (tree[rc].sum*=tree[o].tag2)%=MOD;

    tree[o].tag2=1;


    (tree[lc].tag+=tree[o].tag)%=MOD;
    (tree[lc].sum+=(tree[o].tag*(mid-l+1))%MOD)%=MOD;

    (tree[rc].tag+=tree[o].tag)%=MOD;
    (tree[rc].sum+=(tree[o].tag*(r-mid))%MOD)%=MOD;

    tree[o].tag=0;

}
ll query(od,int ql,int qr){
    if(l>=ql&&r<=qr){
        return tree[o].sum;
    }
    ll ans=0;
    push_down(oq);
    if(ql<=mid){
        (ans+=query(lcq,ql,qr))%=MOD;
    }
    if(qr>mid){
        (ans+=query(rcq,ql,qr))%=MOD;
    }
    return ans;
}
void update(od,int ql,int qr,ll val){
    if(l>=ql&&r<=qr){
        (tree[o].tag+=val)%=MOD;
        (tree[o].sum+=(val*(r-l+1))%MOD)%=MOD;
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

void update2(od,int ql,int qr,ll val){
    if(l>=ql&&r<=qr){
        (tree[o].tag2*=val)%=MOD;
        (tree[o].tag*=val)%=MOD;
        (tree[o].sum*=val)%=MOD;
        return;
    }
    push_down(oq);
    if(ql<=mid){
        update2(lcq,ql,qr,val);
    }
    if(qr>mid){
        update2(rcq,ql,qr,val);
    }
    push_up(o);
}
int main(){
    int n,q;scanf("%d%d",&n,&MOD);
    a=(int*)malloc((n+1)*sizeof(int));
    tree=(Node*)calloc((n+1)<<2,sizeof(Node));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        a[i]%=MOD;
    }
    build(1,1,n);
    scanf("%d",&q);
    while(q--){
        int op,ql,qr;scanf("%d%d%d",&op,&ql,&qr);
        if(op==2){
            int val;scanf("%d",&val);
            update(1,1,n,ql,qr,val);
        }else if(op==1){
            int val;scanf("%d",&val);
            update2(1,1,n,ql,qr,val);
        }else{
            printf("%lld\n",query(1,1,n,ql,qr));
        }
    }
    return 0;
}