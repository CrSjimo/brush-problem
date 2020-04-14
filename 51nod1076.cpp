#include<cstdio>
#include<cstdlib>
#include<stack>
#include<vector>
using std::stack;
using std::vector;
using std::min;
int n,m;
vector< vector<int> > G;
vector<int> dfn;
vector<int> low;
stack<int> st;
int t=0;
int cnt=0;
vector<int> color;
void tarjan(int u,int fa){
    dfn[u]=low[u]=++t;
    st.push(u);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==fa)continue;
        if(!dfn[v]){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }else{
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        int v;
        cnt++;
        do{
            v=st.top();st.pop();
            color[v]=cnt;
        }while(u!=v);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    G.resize(n+1);
    dfn.resize(n+1);
    low.resize(n+1);
    color.resize(n+1);
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i,-1);
    }
    scanf("%d",&m);
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf(color[x]==color[y]?"Yes\n":"No\n");
    }
    return 0;
}