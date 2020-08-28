#include<cstdio>
#include<cstdlib>
#include<vector>
#include<stack>
using std::vector;
using std::stack;
using std::min;
vector< vector<int> > G;
int* dfn;
int* low;
int* color;
int* c_siz;
bool* ins;
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
void suodian(){
    for(int u=1;u<=n;u++){
        c_siz[color[u]]++;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(color[u]==color[v])continue;
            Gs[color[u]].push_back(color[v]);
        }
    }
}
int main(){
    int m;scanf("%d%d",&n,&m);
    alloc(dfn,n+1);
    alloc(low,n+1);
    alloc(color,n+1);
    alloc(ins,n+1);
    G.resize(n+1);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    for(int u=1;u<=n;u++){
        if(!dfn[u])tarjan(u);
    }
    Gs.resize(cnt+1);
    alloc(c_siz,cnt+1);
    suodian();
    int ans=0;
    bool selected=false;
    for(int u=1;u<=cnt;u++){
        if(Gs[u].size()==0 && !selected){
            ans=c_siz[u];
            selected=true;
        }else if(Gs[u].size()==0 && selected){
            printf("0\n");
            return 0;
        }
    }
    printf("%d\n",ans);
    return 0;
}