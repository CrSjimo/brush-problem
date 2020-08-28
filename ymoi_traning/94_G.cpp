#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
using std::swap;

namespace seg_tree{
    #define mid ((l+r)>>1)
    #define lc (o<<1)
    #define rc (o<<1|1)
    #define lcq lc,l,mid
    #define rcq rc,mid+1,r
    #define oq o,l,r
    #define od int o,int l,int r
    struct Node{
        int sum;
        int tag;
    }* tree;
    void push_up(int o){
        tree[o].sum = tree[lc].sum+tree[rc].sum;
    }
    void build(od){
        tree[o].tag=19260817;
        if(l==r){
            tree[o].sum=0;
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
int* siz;
int* dep;
int* fa;
int* son;
int* top;
int* id;
vector< vector<int> >G;

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
void dfs2(int u,int topf){
    top[u]=topf;id[u]=++cnt;
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
char op[10];
int main(){
    int q;scanf("%d",&n);
    alloc(tree,(n+1)<<2);
    alloc(G,n+1);
    alloc(siz,n+1);
    alloc(dep,n+1);
    alloc(fa,n+1);
    alloc(son,n+1);
    alloc(top,n+1);
    alloc(id,n+1);
    for(int i=2;i<=n;i++){
        int u,v=i;scanf("%d",&u);u++;
        G[u].push_back(v);
    }
    dfs1(1);
    dfs2(1,1);
    build(1,1,n);
    // for(int i=1;i<=n;i++){
    //     printf("test %4d %4d %4d\n",i,id[i],siz[i]);
    // }
    scanf("%d",&q);
    int stat=0;
    while(q--){
        int u;scanf("%s%d",op,&u);
        u++;
        if(op[0]=='i'){
            update_path(1,u,1);
        }else if(op[0]=='u'){
            update_tree(u,0);
        }
        int newStat = query_tree(1);
        printf("%d\n",abs(newStat-stat));
        stat=newStat;
    }
    return 0;
}