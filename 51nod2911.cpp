#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
using std::vector;
vector< vector<int> > G;
int* vis;
bool dfs(int u){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(vis[v]==-1){
            vis[v]=vis[u]^1;
            if(dfs(v)){
                return true;
            }
        }else if(vis[v]==vis[u]){
            printf("No\n");
            return true;
        }
    }
    return false;
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        G.clear();
        memset(vis=(int*)malloc((n+1)*sizeof(int)),-1,(n+1)*sizeof(int));
        G.resize(n+1);
        while(m--){
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==-1){
                if(dfs(i)){
                    goto match;
                };
            }
        }
        printf("Yes\n");
        match:;
    }
    return 0;
}