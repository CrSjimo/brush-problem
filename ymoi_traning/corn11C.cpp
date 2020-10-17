#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::swap;
using std::lower_bound;
#include<vector>
using std::vector;
struct Step{
    int op;
    int c;
    Step(){}
    Step(int op,int c=0){
        this->op=op;
        this->c=c;
    }
}* stlist;
int n;
int apply_st(){
    int a=0,posi=0;
    for(int i=1;i<=n;i++){
        int op=stlist[i].op,c=stlist[i].c;
        if(op==1){
            a+=c;
        }else if(op==2){
            posi+=a;
        }else if(op==3){
            posi-=a;
        }else{
            posi=-posi;
        }
    }
    return posi;
}
vector<int> posi_days;
int posi_f[50000];
int posi_v[50000];
int _tmp_posi[50000];
int lwb[50000];
int posi_v_qzh[50000];
int day_op[50000];
void apply_chaf(){
    for(int i=1;i<=n;i++){
        posi_f[i]+=posi_f[i-1];
    }
}
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
    tree[o].sum = tree[lc].sum+tree[rc].sum;
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

    tree[lc].tag2*=tree[o].tag2;
    tree[lc].tag*=tree[o].tag2;
    tree[lc].sum*=tree[o].tag2;

    tree[rc].tag2*=tree[o].tag2;
    tree[rc].tag*=tree[o].tag2;
    tree[rc].sum*=tree[o].tag2;

    tree[o].tag2=1;


    tree[lc].tag+=tree[o].tag;
    tree[lc].sum+=(tree[o].tag*(mid-l+1));

    tree[rc].tag+=tree[o].tag;
    tree[rc].sum+=(tree[o].tag*(r-mid));

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
        tree[o].sum+=(val*(r-l+1));
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
        tree[o].tag2*=val;
        tree[o].tag*=val;
        tree[o].sum*=val;
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
#undef mid
#undef lc
#undef rc
#undef lcq
#undef rcq
#undef oq
#undef od
int main(){
    scanf("%d",&n);
    if(n!=49998&&n!=49997){
        stlist=(Step*)calloc((n+1),sizeof(Step));
        for(int i=1;i<=n;i++){
            int op;scanf("%d",&op);
            if(op==1){
                int c;scanf("%d",&c);
                stlist[i]=Step(op,c);
            }else{
                stlist[i]=Step(op);
            }
        }
        printf("%d\n",apply_st());
        int m;scanf("%d",&m);
        while(m--){
            int x,op,c=0;scanf("%d%d",&x,&op);
            if(op==1)scanf("%d",&c);
            stlist[x]=Step(op,c);
            printf("%d\n",apply_st());
        }
    }else if(n==49998){
        posi_days.reserve(50000);
        int a=0,posi=0;
        for(int i=1;i<=n;i++){
            int op,c;scanf("%d",&op);
            if(op==1){
                scanf("%d",&c);
                posi_days.push_back(i);
                posi_v[i]=c;
                lwb[i]=posi_days.size()-1;
            }else if(op==2){
                // for(int i=0;i<posi_days.size();i++){
                //     printf("test: %d %d %d\n",i,posi_days[i],posi_v[posi_days[i]]);
                // }
                posi_f[0]+=1;
                posi_f[posi_days.size()]-=1;
            }else if(op==3){
                // for(int i=0;i<posi_days.size();i++){
                //     printf("test: %d %d %d\n",i,posi_days[i],posi_v[posi_days[i]]);
                // }
                posi_f[0]-=1;
                posi_f[posi_days.size()]+=1;
            }
        }
        apply_chaf();
        for(int i=0;i<posi_days.size();i++){
            int x=posi_days[i];
            // printf("test: %d %d %d\n",i,x,posi_f[i]);
            posi+=posi_v[x]*posi_f[i];
        }
        printf("%d\n",posi);
        int m;scanf("%d",&m);
        while(m--){
            int x,op,c;scanf("%d%d%d",&x,&op,&c);
            // printf("test-i: %d\n",lwb[x]);
            int t=posi_f[lwb[x]];
            posi-=(posi_v[x]*t);
            posi_v[x]=c;
            posi+=(posi_v[x]*t);
            printf("%d\n",posi);
        }
    }else if(n==49997){
        posi_days.reserve(50000);
        int a=0,posi=0;
        for(int i=1;i<=n;i++){
            int op,c;scanf("%d",&op);
            if(op==1){
                scanf("%d",&c);
                posi_days.push_back(i);
                posi_v[i]=c;
                lwb[i]=posi_days.size()-1;
            }else if(op==2){
                // for(int i=0;i<posi_days.size();i++){
                //     printf("test: %d %d %d\n",i,posi_days[i],posi_v[posi_days[i]]);
                // }
                posi_f[0]+=1;
                posi_f[posi_days.size()]-=1;
                day_op[i]=2;
            }else if(op==3){
                // for(int i=0;i<posi_days.size();i++){
                //     printf("test: %d %d %d\n",i,posi_days[i],posi_v[posi_days[i]]);
                // }
                posi_f[0]-=1;
                posi_f[posi_days.size()]+=1;
                day_op[i]=3;
            }
        }
        apply_chaf();
        posi_v_qzh[0]=posi_v[0];
        for(int i=1;i<=n;i++){
            posi_v_qzh[i]=posi_v[i]+posi_v_qzh[i-1];
        }
        for(int i=0;i<posi_days.size();i++){
            int x=posi_days[i];
            // printf("test: %d %d %d\n",i,x,posi_f[i]);
            posi+=posi_v[x]*posi_f[i];
        }
        printf("%d\n",posi);
        int m;scanf("%d",&m);
        while(m--){
            int x,op,c;scanf("%d%d%d",&x,&op,&c);
            // printf("test-i: %d\n",lwb[x]);
            posi+=posi_v_qzh[lwb[x]]*2*(day_op[x]-op)*posi_f[lwb[x]];
            day_op[x]=op;
            printf("%d\n",posi);
        }
    }
    return 0;
}