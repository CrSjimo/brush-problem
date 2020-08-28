#include<cstdio>
#include<cstdlib>
typedef long long ll;
struct Node{
    ll max;
    int max_id;
}* tree;
ll* a;
#define mid ((l+r)>>1)
#define lc (o<<1)
#define rc (o<<1|1)
#define lcq lc,l,mid
#define rcq rc,mid+1,r
#define oq o,l,r
#define od int o,int l,int r
void push_up(int o){
    if(tree[lc].max>tree[rc].max){
        tree[o].max=tree[lc].max;
        tree[o].max_id=tree[lc].max_id;
    }else{
        tree[o].max=tree[rc].max;
        tree[o].max_id=tree[rc].max_id;
    }
}
void build(od){
    if(l==r){
        tree[o].max=a[l];
        tree[o].max_id=l;
        return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    push_up(o);
}
Node query(od,int ql,int qr){
    if(l>=ql&&r<=qr){
        return tree[o];
    }
    Node ans;
    ans.max=0;
    if(ql<=mid){
        Node tmp=query(lcq,ql,qr);
        if(tmp.max>ans.max){
            ans=tmp;
        }
    }
    if(qr>mid){
        Node tmp=query(rcq,ql,qr);
        if(tmp.max>ans.max){
            ans=tmp;
        }
    }
    return ans;
}
void update(od,int p){
    if(l==p && r==p){
        tree[o].max=0;
        return;
    }
    if(p<=mid){
        update(lcq,p);
    }else if(p>mid){
        update(rcq,p);
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
int n;
int binary1(int l,int r,ll k){
    if(l>r)return -1;
    if(l==r){
        Node tmp=query(1,1,n,l,r);
        if(tmp.max>=k){
            // printf("test: %d %lld %d\n",l,tmp.max,tmp.max_id);
            return tmp.max_id;
        }else{
            return -1;
        }
    }
    int mid=(l+r)>>1;
    Node tmp=query(1,1,n,l,r);
    if(tmp.max>=k){
        int rans=binary1(mid+1,r,k);
        if(rans==-1){
            return binary1(l,mid,k);
        }else{
            return rans;
        }
    }else{
        return -1;
    }
}
int binary2(int l,int r,ll k){
    if(l>r)return -1;
    if(l==r){
        Node tmp=query(1,1,n,l,r);
        if(tmp.max>=k){
            // printf("test: %d %lld %d\n",l,tmp.max,tmp.max_id);
            return tmp.max_id;
        }else{
            return -1;
        }
    }
    int mid=(l+r)>>1;
    Node tmp=query(1,1,n,l,r);
    if(tmp.max>=k){
        int lans=binary2(l,mid,k);
        if(lans==-1){
            return binary2(mid+1,r,k);
        }else{
            return lans;
        }
    }else{
        return -1;
    }
}
int main(){
    int q;scanf("%d%d",&n,&q);
    a=(ll*)calloc((n+1),sizeof(ll));
    tree=(Node*)calloc((n+1)<<2,sizeof(Node));
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    build(1,1,n);
    if(n<=2000){
        while(q--){
            int l,r,x,k;scanf("%d%d%d%d",&l,&r,&x,&k);
            if((l<=x)&&(x<=r)){
                ll orz=a[x];
                if(k<=orz){
                    printf("%d\n",x);
                    a[x]=0;
                    continue;
                }
                bool flag=0;
                // printf("test: %d %d\n",lans,rans);
                for(int i=x+1;i<=r;i++){
                    if(a[i]>=k){
                        printf("%d\n",i);
                        a[i]=0;
                        flag=1;
                        break;
                    }
                }
                for(int i=x-1;i>=l;i--){
                    if(a[i]>=k){
                        printf("%d\n",i);
                        a[i]=0;
                        flag=1;
                        break;
                    }
                }
                // if(flag)printf("\n");
            }else if(l>x){
                for(int i=l;i<=r;i++){
                    if(a[i]>=k){
                        printf("%d\n",i);
                        a[i]=0;
                        break;
                    }
                }
            }else if(r<x){
                for(int i=r;i>=l;i--){
                    if(a[i]>=k){
                        printf("%d\n",i);
                        a[i]=0;
                        break;
                    }
                }
            }
        }
        return 0;
    }
    while(q--){
        int l,r,x,k;scanf("%d%d%d%d",&l,&r,&x,&k);
        if((l<=x)&&(x<=r)){
            ll orz=query(1,1,n,x,x).max;
            if(k<=orz){
                printf("%d\n",x);
                update(1,1,n,x);
                continue;
            }
            int lans=binary1(l,x-1,k);
            int rans=binary2(x+1,r,k);
            // printf("test: %d %d\n",lans,rans);
            if(rans!=-1){
                update(1,1,n,rans);
                printf("%d\n",rans);
            }
            if(lans!=-1){
                update(1,1,n,lans);
                printf("%d\n",lans);
            }
        }else if(l>x){
            int rans=binary2(l,r,k);
            if(rans!=-1){
                update(1,1,n,rans);
                printf("%d\n",rans);
            }
        }else if(r<x){
            int lans=binary1(l,r,k);
            if(lans!=-1){
                update(1,1,n,lans);
                printf("%d\n",lans);
            }
        }
    }
    return 0;
}