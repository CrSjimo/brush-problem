#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cctype>
typedef long long ll;
int getint(){
    int x=0,k=1;
    int c = 1919810;
    while(!isdigit(c)){
        c=getchar();
        if(c=='-')k=-1;
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*k;
}
void _putint(ll x,bool t){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x==0&&t)return;
    _putint(x/10,1);
    putchar(x%10+'0');
}
void putint(ll x){
    _putint(x,0);
}
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

ll query_path(int u,int v){
    ll ans=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        ans+=query(1,1,n,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if(dep[u]>dep[v])swap(u,v);
    ans+=query(1,1,n,id[u],id[v]);
    return ans;
}

void update_path(int u,int v,ll val){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        update(1,1,n,id[top[u]],id[u],val);
        u=fa[top[u]];
    }
    if(dep[u]>dep[v])swap(u,v);
    update(1,1,n,id[u],id[v],val);
}

ll query_tree(int u){
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
    n=getint();int q=getint(),r=getint();
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
        ra[i]=getint();
    }
    for(int i=1;i<=n-1;i++){
        int u=getint(),v=getint();
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
        int op=getint(),u=getint(),v=getint();
        if(op==1){
            update_path(u,u,v);
        }else if(op==2){
            update_tree(u,v);
        }else if(op==3){
            putint(query_path(u,v));putchar('\n');
        }
    }
    return 0;
}