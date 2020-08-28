#include<cstdio>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
using std::queue;
using std::vector;
using std::stack;
using std::min;
vector< vector<int> > G;
typedef long long ll;
int* dfn;
int* low;
int* color;
ll* c_siz;
bool* ins;
int* w;
int T=0;
int cnt=0;
stack<int> s;
void tarjan(int u){
    dfn[u]=low[u]=++T;
    ins[u]=true;
    s.push(u);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(ins[v]){//here ins means in stack
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        int v;
        cnt++;
        do{
            v=s.top();s.pop();ins[v]=0;
            color[v]=cnt;
        }while(u!=v);
    }
}
vector< vector<int> >Gs;
int n;
template<typename T>inline T*& alloc(T*& a,size_t siz){
    return a=(T*)calloc((siz),sizeof(T));
}
int* ind;
int* type;
int* type_gs;
queue<int> q;
int s1;
int ss;
void suodian(){
    for(int u=1;u<=n;u++){
        c_siz[color[u]]+=w[u];
        if(u==s1){
            ss=color[u];
        }else if(type[u]==2){
            type_gs[color[u]]=2;
        }
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(color[u]==color[v])continue;
            ind[color[v]]++;
            Gs[color[u]].push_back(color[v]);
        }
    }
}
ll* dp;
using std::max;
int toposort(){
    q.push(ss);
    dp[ss]=c_siz[ss];
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<Gs[u].size();i++){
            int v=Gs[u][i];
            dp[v]=max(dp[v],c_siz[v]+dp[u]);
            if(!--ind[v]){
                q.push(v);
            }
        }
    }
}
int main(){
    int m;scanf("%d%d",&n,&m);
    alloc(dfn,n+1);
    alloc(low,n+1);
    alloc(color,n+1);
    alloc(ins,n+1);
    alloc(w,n+1);
    alloc(type,n+1);
    G.resize(n+1);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    for(int u=1;u<=n;u++){
        scanf("%d",w+u);
        if(!dfn[u])tarjan(u);
    }
    int p;scanf("%d%d",&s1,&p);
    for(int i=1;i<=p;i++){
        int u;scanf("%d",&u);
        type[u]=2;
    }
    Gs.resize(cnt+1);
    alloc(c_siz,cnt+1);
    alloc(type_gs,cnt+1);
    alloc(ind,cnt+1);
    alloc(dp,cnt+1);
    suodian();
    toposort();
    ll ans=-19260817;
    for(int i=1;i<=cnt;i++){
        if(type_gs[i]==2){
            ans=max(ans,dp[i]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}