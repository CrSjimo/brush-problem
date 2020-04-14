#include<cstdio>
#include<vector>
#include<cstdlib>
using std::vector;
using std::min;
int n,m;
vector< vector<int> > G;
int t = 0;
vector<int> dfn;
vector<int> low;
typedef long long ll;
vector<int> num;
vector<ll> ans;
void tarjan(int u){
    dfn[u]=low[u]=++t;
    num[u]=1;
    ll cnt = 0;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!dfn[v]){
            tarjan(v);
            num[u]+=num[v];
            low[u] = min(low[u],low[v]);
            if(dfn[u]<=low[v]){
                ans[u]+=cnt*num[v];
                cnt+=num[v];
            }
        }else{
            low[u]=min(low[u],dfn[v]);
        }
    }
    ans[u]+=cnt*(n-cnt-1);
}
int main(){
    scanf("%d%d",&n,&m);
    G.resize(n+5);
    dfn.resize(n+5);
    low.resize(n+5);
    num.resize(n+5);
    ans.resize(n+5);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    tarjan(1);
    for(int i=1;i<=n;i++){
        printf("%lld\n",(ans[i]+n-1)*2);
    }
    return 0;
}