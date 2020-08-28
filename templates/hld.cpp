#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
using std::swap;
typedef long long ll;

namespace seg_tree{
    #define mid ((l+r)>>1)
    #define lc (o<<1)
    #define rc (o<<1|1)
    #define lcq lc,l,mid
    #define rcq rc,mid+1,r
    #define oq o,l,r
    #define od int o,int l,int r
    struct Node{
        ll sum;
        ll tag;
    }* tree;
    int* a;
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
/* siz[i]表示i结点的子树大小 */
int* siz;
/* dep[i]表示i结点的深度(定义根的深度为1) */
int* dep;
/* fa[i]表示i结点的父结点编号 */
int* fa;
/* son[i]表示i结点的重儿子编号 */
int* son;
/* top[i]表示i结点所在重链顶端结点的编号 */
int* top;
/* id[i]表示i结点按照重儿子优先顺序的dfs序号 */
int* id;
vector< vector<int> >G;

/* 求出子树大小siz, 深度dep, 重儿子son, 父结点fa */
void dfs1(int u){
    siz[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==fa[u])continue;
        dep[v]=dep[u]+1;fa[v]=u;
        dfs1(v);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])son[u]=v;
    }
}
int cnt=0;
/** 
 * 求出重链顶端top,重儿子优先的dfs序id
 * @param topf 当前重链顶端 
 */
void dfs2(int u,int topf){
    top[u]=topf;id[u]=++cnt;
    a[id[u]]=ra[u];
    if(son[u])dfs2(son[u],topf);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==fa[u]||v==son[u])continue;
        dfs2(v,v);
    }
}

int lca(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]<dep[v]?u:v;
}

int query_path(int u,int v){
    int ans=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        ans+=query(1,1,n,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if(dep[u]>dep[v])swap(u,v);
    ans+=query(1,1,n,id[u],id[v]);
    return ans;
}

void update_path(int u,int v,int val){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        update(1,1,n,id[top[u]],id[u],val);
        u=fa[top[u]];
    }
    if(dep[u]>dep[v])swap(u,v);
    update(1,1,n,id[u],id[v],val);
}

int query_tree(int u){
    return query(1,1,n,id[u],id[u]+siz[u]-1);
}

void update_tree(int u,int val){
    update(1,1,n,id[u],id[u]+siz[u]-1,val);
}

template<typename T>inline void alloc(T*& a,size_t siz){
    a=(T*)calloc(siz,sizeof(T));
}
template<typename T>inline void alloc(vector<T>& a,size_t siz){
    a.resize(siz);
}

int main(){
    int q,r,p;scanf("%d%d%d%d",&n,&q,&r,&p);
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
    for(int i=1;i<=n;i++){
        scanf("%d",&ra[i]);
    }
    for(int i=1;i<=n-1;i++){
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(r);
    dfs2(r,r);
    build(1,1,n);
    // for(int i=1;i<=n;i++){
    //     printf("test %4d %4d %4d\n",i,id[i],siz[i]);
    // }
    while(q--){
        int op,u,v,val;
        scanf("%d%d",&op,&u);
        if(op==1){
            scanf("%d%d",&v,&val);
            update_path(u,v,val);
        }else if(op==2){
            scanf("%d",&v);
            printf("%d\n",query_path(u,v));
        }else if(op==3){
            scanf("%d",&val);
            update_tree(u,val);
        }else if(op==4){
            printf("%d\n",query_tree(u));
        }
    }
    return 0;
}