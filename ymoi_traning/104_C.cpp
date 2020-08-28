#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<map>
using std::map;
using std::swap;
using std::vector;
int tot=0;
map<int,int> mp;
inline int h(int i){
    return mp[i]?mp[i]:mp[i]=++tot;
}
int** fa;
int* dep;
vector< vector<int> >G;
int n,log2n;
void dfs(int u,int p){
    fa[u][0]=p;
    dep[u]=dep[p]+1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==p)continue;
        dfs(v,u);
    }
}
int rt;
void init(){
    dep=(int*)calloc((n+1),sizeof(int));
    fa=(int**)malloc((n+1)*sizeof(int*));
    for(int**p=fa;p<=fa+n;p++)*p=(int*)calloc(log2n+1,sizeof(int));
    dep[0]=-1;
    dfs(rt,0);
    for(int j=1;j<=log2n;j++){
        for(int i=1;i<=n;i++){
            fa[i][j]=fa[fa[i][j-1]][j-1];
        }
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    for(int j=log2n;j>=0;j--){
        if(dep[v]<=dep[fa[u][j]]){
            u=fa[u][j];
        }
    }
    if(u==v)return v;
    for(int j=log2n;j>=0;j--){
        if(fa[u][j]!=fa[v][j]){
            u=fa[u][j];
            v=fa[v][j];
        }
    }
    return fa[u][0];
}
int main(){
	scanf("%d",&n);
	G.resize(n+1);
    log2n=(int)log2(n)+1;
	for(int i=1;i<=n;i++){
		int u,v;scanf("%d%d",&u,&v);
        if(v==-1){
            rt=h(u);
        }else{
            u=h(u),v=h(v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
	}
    init();
    int q;scanf("%d",&q);
    while(q--){
        int u,v;scanf("%d%d",&u,&v);
        u=h(u),v=h(v);
        int zgz=lca(u,v);
        if(zgz==u)printf("1\n");
        else if(zgz==v)printf("2\n");
        else printf("0\n");
    }
    return 0;
}