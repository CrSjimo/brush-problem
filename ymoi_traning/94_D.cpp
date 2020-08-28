#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
using std::swap;
using std::max;
using std::min;

namespace seg_tree{
    #define mid ((l+r)>>1)
    #define lc (o<<1)
    #define rc (o<<1|1)
    #define lcq lc,l,mid
    #define rcq rc,mid+1,r
    #define oq o,l,r
    #define od int o,int l,int r
    struct Node{
        int max;
        int min;
        int tagN;
        int sum;
    }* tree;
    int* a;
    void push_up(int o){
        tree[o].max = max(tree[lc].max,tree[rc].max);
        tree[o].min = min(tree[lc].min,tree[rc].min);
        tree[o].sum = tree[lc].sum+tree[rc].sum;
        // printf("tmp_test: %d %d %d\n",tree[o].min,tree[lc].min,tree[rc].min);
    }
    void build(od){
        tree[o].tagN=1;tree[o].min=19260817,tree[o].max=-19260817;
        if(l==r){
            tree[o].max=tree[o].min=tree[o].sum=a[l];
            return;
        }
        build(lc,l,mid);
        build(rc,mid+1,r);
        push_up(o);
    }
    void push_one(int rt,int c){
        tree[c].tagN*=tree[rt].tagN;
        tree[c].max*=tree[rt].tagN;
        tree[c].min*=tree[rt].tagN;
        tree[c].sum*=tree[rt].tagN;
        if(tree[c].max<tree[c].min)swap(tree[c].max,tree[c].min);
    }
    void push_down(od){
        push_one(o,lc);
        push_one(o,rc);
        tree[o].tagN=1;
    }
    const char Q_MAX=1,Q_MIN=2,Q_SUM=3;
    inline int join(int a,int b,char op){
        if(op==Q_MAX){
            return max(a,b);
        }else if(op==Q_MIN){
            return min(a,b);
        }else if(op==Q_SUM){
            return a+b;
        }
    }
    inline int init(char op){
        if(op==Q_MAX)return -19260817;
        if(op==Q_MIN)return 19260817;
        if(op==Q_SUM)return 0;
    }
    int query(od,int ql,int qr,char op){
        if(l>=ql&&r<=qr){
            if(op==Q_MAX){
                return tree[o].max;
            }else if(op==Q_MIN){
                return tree[o].min;
            }else if(op==Q_SUM){
                return tree[o].sum;
            }
            
        }
        int ans=init(op);
        push_down(oq);
        if(ql<=mid){
            ans=join(ans,query(lcq,ql,qr,op),op);
        }
        if(qr>mid){
            ans=join(ans,query(rcq,ql,qr,op),op);
        }
        return ans;
    }
    const char U_C=1,U_N=2;
    void update(od,int ql,int qr,int val,int op){
        if(l>=ql&&r<=qr){
            if(op==U_C){
                tree[o].max=tree[o].min=val;
                tree[o].sum=val*(r-l+1);//always eq 1
                // printf("tmp_test: %d\n",tree[o].min);
            }else{
                tree[o].max*=val,tree[o].min*=val,tree[o].sum*=val;
                if(tree[o].max<tree[o].min)swap(tree[o].max,tree[o].min);
                tree[o].tagN*=val;
            }
            return;
        }
        push_down(oq);
        if(ql<=mid){
            update(lcq,ql,qr,val,op);
        }
        if(qr>mid){
            update(rcq,ql,qr,val,op);
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
}
using namespace seg_tree;
int n;
int* ra;
int* siz;
int* dep;
int* fa;
int* son;
int* top;
int* id;
struct Edge{
    int v;
    int val;
    Edge(){}
    Edge(int v,int val){
        this->v=v;
        this->val=val;
    }
};
vector< vector<Edge> >G;

void dfs1(int u,int val){
    siz[u]=1;ra[u]=val;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i].v;
        if(v==fa[u])continue;
        dep[v]=dep[u]+1;fa[v]=u;
        dfs1(v,G[u][i].val);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])son[u]=v;
    }
}
int cnt=0;
void dfs2(int u,int topf){
    top[u]=topf;id[u]=++cnt;
    a[id[u]]=ra[u];
    if(son[u])dfs2(son[u],topf);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i].v;
        if(v==fa[u]||v==son[u])continue;
        dfs2(v,v);
    }
}

int query_path(int u,int v,char op){
    int ans=init(op);
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        ans=join(ans,query(1,1,n,id[top[u]],id[u],op),op);
        u=fa[top[u]];
    }
    if(dep[u]>dep[v])swap(u,v);
    if(u!=v)ans=join(ans,query(1,1,n,id[u]+1,id[v],op),op);
    return ans;
}

void update_path(int u,int v,int val,char op){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        update(1,1,n,id[top[u]],id[u],val,op);
        u=fa[top[u]];
    }
    if(dep[u]>dep[v])swap(u,v);
    if(u!=v)update(1,1,n,id[u]+1,id[v],val,op);
}
template<typename T>inline void alloc(T*& a,size_t siz){
    a=(T*)calloc(siz,sizeof(T));
}
template<typename T>inline void alloc(vector<T>& a,size_t siz){
    a.resize(siz);
}
struct Edge2{
    int u,v,val;
    Edge2(){}
    Edge2(int u,int v,int val){
        this->u=u;
        this->v=v;
        this->val=val;
    }
};
vector<Edge2> li;

int main(){
    scanf("%d",&n);
    alloc(ra,n+1);
    alloc(a,n+1);
    alloc(tree,(n+1)<<2);
    alloc(G,n+1);
    alloc(siz,n+1);
    alloc(dep,n+1);
    alloc(fa,n+1);
    alloc(son,n+1);
    alloc(top,n+1);
    alloc(id,n+1);
    li.reserve(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v,val;scanf("%d%d%d",&u,&v,&val);
        u++;v++;
        G[u].push_back(Edge(v,val));
        G[v].push_back(Edge(u,val));
        li.push_back(Edge2(u,v,val));
    }
    dfs1(1,0);
    dfs2(1,1);
    build(1,1,n);
    // for(int i=1;i<=n;i++){
    //     printf("test %4d %4d %4d %4d\n",i,ra[i],id[i],siz[i]);
    // }
    int q;scanf("%d",&q);
    while(q--){
        char op[4];
        int u,v;
        scanf("%s%d%d",op,&u,&v);
        if(op[0]=='N'){
            update_path(u+1,v+1,-1,U_N);
        }else if(op[1]=='A'){
            printf("%d\n",query_path(u+1,v+1,Q_MAX));
        }else if(op[0]=='C'){
            int u_=li[u-1].u,v_=li[u-1].v;
            if(dep[u_]>dep[v_]){
                update(1,1,n,id[u_],id[u_],v,U_C);
            }else{
                update(1,1,n,id[v_],id[v_],v,U_C);
            }
        }else if(op[1]=='I'){
            printf("%d\n",query_path(u+1,v+1,Q_MIN));
        }else if(op[0]=='S'){
            printf("%d\n",query_path(u+1,v+1,Q_SUM));
        }else if(op[0]=='t'){
            printf("test: sum=%d max=%d min=%d\n",query_path(u+1,v+1,Q_SUM),query_path(u+1,v+1,Q_MAX),query_path(u+1,v+1,Q_MIN));
        }
        // for(int i=0;i<n-1;i++){
        //     printf("t: %d %d %d w=%d\n",q,li[i].u,li[i].v,query_path(li[i].u,li[i].v,Q_SUM));
        // }
    }
    return 0;
}