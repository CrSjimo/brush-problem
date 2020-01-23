#include<stdio.h>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include<iostream>
std::vector< std::vector<int> > G;
std::vector<int> dfn;
std::vector<int> low;
std::vector<int> color;
std::vector<bool> ins;
int T=0;
int cnt=1;
std::stack<int> s;
void tarjan(int u){
    ins[u]=true;
    dfn[u]=low[u]=++T;
    s.push(u);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=std::min(low[u],low[v]);
        }else if(ins[v]){
            low[u]=std::min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        int v;
        do{
            v=s.top();s.pop();ins[v]=false;
            color[v]=cnt;
        }while(u!=v);
        cnt++;
    }
}
std::map<std::string,int> map;
int main(){
    int n,m;
    scanf("%d",&n);
    int siz=2*n;
    G.resize(siz);ins.resize(siz);dfn.resize(siz);low.resize(siz);color.resize(siz);
    for(int i=0;i<n;i++){
        std::string s1,s2;
        std::cin>>s1>>s2;
        G[map[s1]=i].push_back(map[s2]=i+n);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        std::string s1,s2;
        std::cin>>s1>>s2;
        G[map[s2]].push_back(map[s1]);
    }
    for(int i=0;i<siz;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=0;i<n;i++){
        if(color[i]==color[i+n]){
            printf("Unsafe\n");
        }else{
            printf("Safe\n");
        }
    }
    return 0;
}