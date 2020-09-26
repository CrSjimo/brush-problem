#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
using std::swap;
using std::vector;
int** fa;
int* dep;
int* f;
vector< vector<int> >G;
int n,m,log2n;
void dfs(int u,int p){
    fa[u][0]=p;
    dep[u]=dep[p]+1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==p)continue;
        dfs(v,u);
    }
}
void init(){
    dep=(int*)calloc((n+1),sizeof(int));
    f=(int*)calloc((n+1),sizeof(int));
    fa=(int**)malloc((n+1)*sizeof(int*));
    for(int**p=fa;p<=fa+n;p++)*p=(int*)calloc(log2n+1,sizeof(int));
    dep[0]=-1;
    dfs(1,0);
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
void ddfs(int u,int fa){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==fa)continue;
        ddfs(v,u);
        f[u]+=f[v];
    }
}
int main(){
	scanf("%d%d",&n,&m);
	G.resize(n+1);
    log2n=(int)log2(n)+1;
	for(int i=1;i<=n-1;i++){
		int u,v;scanf("%d%d",&u,&v);
		G[u].push_back(v);
        G[v].push_back(u);
	}
    init();
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        f[u]++,f[v]++;
        f[lca(u,v)]-=2;
    }
    ddfs(1,0);
    int ans=0;
    for(int i=2;i<=n;i++){
        if(f[i]==0){
            ans+=m;
        }else if(f[i]==1){
            ans+=1;
        }
    }
    printf("%d\n",ans);
    return 0;
}