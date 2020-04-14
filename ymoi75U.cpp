#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
using std::min;
int *dfn,*low;
bool *ins;
vector<int> st;
vector< vector<int> > G;
int T=0;
int cnt = 0;
void tarjan(int u){
    dfn[u]=low[u]=++T;
    st.push_back(u);ins[u]=true;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(ins[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        int v;int siz=0;
        do{
            v=st.back();st.pop_back();
            ins[v]=false;
            siz++;
        }while(v!=u);
        cnt+=(siz!=1);
    }
}
template <typename T> void _allocate_init(T*& p,int n){
    p=(T*)calloc((n+1),sizeof(int));
}
template <typename T> void _allocate_init(vector<T>& p,int n){
    p.resize(n+1);
}
int main(){
    int n,m;scanf("%d%d",&n,&m);
    _allocate_init(dfn,n);
    _allocate_init(low,n);
    _allocate_init(ins,n);
    _allocate_init(G,n);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    printf("%d\n",cnt);
    return 0;
}