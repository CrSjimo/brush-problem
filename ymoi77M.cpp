#include<cstdio>
#include<vector>
#include<stack>
#include<cstdlib>
#include<cstring>
#include<queue>
using std::queue;
using std::vector;
using std::stack;
using std::min;
using std::max;
vector< vector<int> > G;
vector< vector<int> > G2;
int* dfn;
int* low;
int* color;
bool* ins;
int* cost;
int* d;
int n;
int T=0;
int cnt=0;
stack<int> s;
int* buy;
int* sell;
int* delta;
int* dp;
template<typename T>T*& alloc(T*& p,size_t siz){
    return p=(T*)calloc(siz,sizeof(T));
}
template<typename T>vector<T>& alloc(vector<T>& p,size_t siz){
    p.resize(siz);
    return p;
}
void tarjan(int u){
    dfn[u]=low[u]=++T;
    ins[u]=true;
    s.push(u);
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
        int v;
        cnt++;
        do{
            v=s.top();s.pop();ins[v]=0;
            color[v]=cnt;
        }while(u!=v);
    }
}
int* ind;
void suodian(){
    alloc(G2,cnt+1);
    memset(alloc(buy,cnt+1),0x3f,(cnt+1)*sizeof(int));
    alloc(sell,cnt+1);
    alloc(delta,cnt+1);
    alloc(dp,cnt+1);
    alloc(ind,cnt+1);
    memset(alloc(d,cnt+1),0x3f,(cnt+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        int u=color[i];
        buy[u]=min(buy[u],cost[i]);
        sell[u]=max(sell[u],cost[i]);
        delta[u]=sell[u]-buy[u];
        for(int j=0;j<G[i].size();j++){
            int v=color[G[i][j]];
            if(u==v)continue;
            G2[u].push_back(v);
            ind[v]++;
        }
    }
}
int toposort(){
    queue<int> q;
    for(int i=1;i<=cnt;i++){
        if(!ind[i])q.push(i);
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<G2[u].size();i++){
            int v=G2[u][i];
            d[v]=min(d[u],buy[v]);
            dp[v]=max(max(dp[u],dp[v]),max(delta[v],sell[v]-d[v]));
            if(!--ind[v]){
                q.push(v);
            }
        }
    }
}
int main(){
    int m;scanf("%d%d",&n,&m);
    alloc(G,n+1);
    alloc(dfn,n+1);
    alloc(low,n+1);
    alloc(color,n+1);
    alloc(ins,n+1);
    alloc(cost,n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",cost+i);
    }
    while(m--){
        int u,v,k;scanf("%d%d%d",&u,&v,&k);
        G[u].push_back(v);
        if(k==2)G[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    suodian();
    toposort();
    printf("%d\n",dp[color[n]]);
    return 0;
}