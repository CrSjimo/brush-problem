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
        int prefix;
        int suffix;
        int tag;
        Node(){}
        Node(int sum,int prefix,int suffix,int tag){
            this->sum=sum;
            this->prefix=prefix;
            this->suffix=suffix;
            this->tag=tag;
        }
    }* tree;
    int* a;
    void push_up(int o){
        tree[o].sum = tree[lc].sum+tree[rc].sum-(tree[lc].suffix==tree[rc].prefix);
        tree[o].suffix=tree[rc].suffix;
        tree[o].prefix=tree[lc].prefix;
    }
    void build(od){
        tree[o].tag=-19260817;
        if(l==r){
            tree[o].sum=1;
            tree[o].prefix=tree[o].suffix=a[l];
            return;
        }
        build(lc,l,mid);
        build(rc,mid+1,r);
        push_up(o);
    }
    void push_one(int c,int tag){
        tree[c].tag=tree[c].prefix=tree[c].suffix=tag;
        tree[c].sum=1;
    }
    void push_down(od){
        if(tree[o].tag==-19260817)return;
        push_one(lc,tree[o].tag);
        push_one(rc,tree[o].tag);
        tree[o].tag=0;
    }
    Node query(od,int ql,int qr){
        if(l>=ql&&r<=qr){
            return tree[o];
        }
        int ans=0;
        int suf=-19260817,pre=-19260817;
        int newSuf=-19260817,newPre=-19260817;
        push_down(oq);
        if(ql<=mid){
            Node t=query(lcq,ql,qr);
            ans+=t.sum;
            suf=t.suffix;
            newPre=t.prefix;
        }
        if(qr>mid){
            Node t=query(rcq,ql,qr);
            ans+=t.sum;
            pre=t.prefix;
            newSuf=t.suffix;
        }
        if(newSuf==-19260817)newSuf=suf;
        if(newPre==-19260817)newPre=pre;
        return Node(ans-(suf==pre),newPre,newSuf,-19260817);
    }
    void update(od,int ql,int qr,int val){
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

template<typename T>inline void aintoc(T*& a,size_t siz){
    a=(T*)caintoc(siz,sizeof(T));
}
template<typename T>inline void aintoc(vector<T>& a,size_t siz){
    a.resize(siz);
}

int main(){
    int q,r,p;scanf("%d%d%d%d",&n,&q,&r,&p);
    aintoc(ra,n+1);
    aintoc(a,n+1);
    aintoc(tree,(n+1)<<2);
    aintoc(G,n+1);
    aintoc(siz,n+1);
    aintoc(dep,n+1);
    aintoc(fa,n+1);
    aintoc(son,n+1);
    aintoc(top,n+1);
    aintoc(id,n+1);
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