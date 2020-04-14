#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
using std::min;
vector< vector<int> > G;
int cnt=0;
int *dfn,*low;
bool* ins;
int T=0;
vector<int> s;
void tarjan(int u){
    dfn[u]=low[u]=++T;
    s.push_back(u);
    ins[u]=true;
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
        do{
            v=s.back();s.pop_back();
            ins[v]=false;
        }while(u!=v);
        cnt++;
    }
}
int main(){
    int n,m;scanf("%d%d",&n,&m);
    dfn=(int*)calloc(n+1,sizeof(int));
    low=(int*)calloc(n+1,sizeof(int));
    ins=(bool*)calloc(n+1,sizeof(bool));
    G.resize(n+1);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    for(int u=1;u<=n;u++){
        if(!dfn[u])tarjan(u);
    }
    printf("%d\n",cnt);
    return 0;
}