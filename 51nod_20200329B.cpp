#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
using std::vector;
int link[205];
bool found[205];
vector< vector<int> > G;
bool dfs(int u){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!found[v]){
            found[v]=true;
            if(!link[v]||dfs(link[v])){
                link[v]=u;
                return true;
            }
        }
    }
    return false;
}
int n;
int hungary(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        memset(found,0,(n+1)*sizeof(bool));
        if(dfs(i))cnt++;
    }
    return cnt;
}
int main(){
    int cas;scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
        G.clear();G.resize(n+1);
        memset(link,0,(n+1)*sizeof(int));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int k;scanf("%d",&k);
                if(k==1)G[i].push_back(j);
            }
        }
        if(hungary()==n)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}