#include<stdio.h>
#include<vector>
#include<stack>
std::vector< std::vector<int> > G;
std::vector<int> dfn;
std::vector<int> low;
std::vector< std::vector<int> > color;
std::vector<int> rev_color;
std::vector<bool> vis;
int T=0;
int cnt=0;
std::stack<int> s;
void tarjan(int u){
    dfn[u]=low[u]=++T;
    vis[u]=true;
    s.push(u);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=std::min(low[u],low[v]);
        }else if(vis[v]){//here vis means in stack
            low[u]=std::min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        color.push_back(std::vector<int>());
        int v;
        do{
            v=s.top();s.pop();vis[v]=0;
            color[cnt].push_back(v);
            rev_color[v]=cnt;
        }while(u!=v);
        cnt++;
    }
}