#include<cstdio>
#include<vector>
using std::vector;
vector< vector<int> > G;
vector<int> color;
int n,k,m;
inline void add_edge(int x,int y){
    G[x].push_back(y);
}
int ans = 0;
inline bool cando(int i,int j){
    for(int k=0;k<G[i].size();k++){
        int v = G[i][k];
        if(j==color[v])return false;
    }
    return true;
}
void dfs(int i){
    if(i>n){
        ans++;
        return;
    }
    for(int j=1;j<=m;j++){
        if(cando(i,j)){
            color[i]=j;
            dfs(i+1);
            color[i]=0;
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&k,&m);
    G.resize(n+1);
    color.resize(n+1);
    while(k--){
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs(1);
    printf("%d\n",ans);
    return 0;
}