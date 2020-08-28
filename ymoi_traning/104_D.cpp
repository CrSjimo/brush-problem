#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<cctype>
using std::swap;
using std::vector;
int** fa;
int* dep;
vector< vector<int> >G;
int n,log2n;
int getint(){
    int x=0,k=1;
    int c = 1919810;
    while(!isdigit(c)){
        c=getchar();
        if(c=='-')k=-1;
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*k;
}
void _putint(int x,bool t){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x==0&&t)return;
    _putint(x/10,1);
    putchar(x%10+'0');
}
void putint(int x){
    _putint(x,0);
}
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
inline int ddis(int u,int v,int zgz){
    return dep[u]+dep[v]-2*dep[zgz];
}
int main(){
	n=getint();int q=getint();
	G.resize(n+1);
    log2n=(int)log2(n)+1;
	for(int i=1;i<=n-1;i++){
		int u=getint(),v=getint();
		G[u].push_back(v);
        G[v].push_back(u);
	}
    init();
    while(q--){
        int u=getint(),v=getint(),p=getint();
        int zuv=lca(u,v);
        int zvp=lca(v,p);
        int zup=lca(u,p);
        if(zvp==zup){
            putint(zuv);putchar(' ');putint((ddis(u,v,zuv)+ddis(v,p,zvp)+ddis(u,p,zup))>>1);putchar('\n');
        }else if(zup==zuv){
            putint(zvp);putchar(' ');putint((ddis(u,v,zuv)+ddis(v,p,zvp)+ddis(u,p,zup))>>1);putchar('\n');
        }else if(zuv==zvp){
            putint(zup);putchar(' ');putint((ddis(u,v,zuv)+ddis(v,p,zvp)+ddis(u,p,zup))>>1);putchar('\n');
        } 
    }
    return 0;
}