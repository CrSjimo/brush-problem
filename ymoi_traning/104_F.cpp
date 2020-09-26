#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using std::swap;
using std::sort;
using std::vector;
using std::min;
int** fa;
int* dep;
int** minn;
template<typename T>T*&alloc(T*&a,size_t siz){
    return a=(T*)calloc(siz,sizeof(T));
}
template<typename T>vector<T>&alloc(vector<T>&a,size_t siz){
    a.resize(siz);
    return a;
}
struct Edge{
    int v, w;
    Edge(){}
    Edge(int v,int w){
        this->v=v;
        this->w=w;
    }
};
struct Edge2{
    int u,v, w;
    Edge2(){}
    Edge2(int u,int v,int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
    bool operator<(const Edge2& e)const{
        return w>e.w;
    }
}* el;
vector< vector<Edge> >G;
int n,m,log2n;
namespace UFS{
    int* f;
    void clear(){
        for(int i=0;i<=n;i++)f[i]=i;
    }
    void init(){
        alloc(f,n+1);
        clear();
    }
    int find(int x){
        return f[x]==x?x:f[x]=find(f[x]);
    }
    void update(int x,int y){
        f[find(x)]=find(y);
    }
}
namespace LCA{
    void dfs(int u,int p){
        // printf("test-d: %d\n",u);
        dep[u]=dep[p]+1;
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(e.v==p)continue;
            fa[e.v][0]=u;
            minn[e.v][0]=e.w;
            // printf("test: %d\n",e.v);
            UFS::update(u,e.v);
            for(int j=1;j<=log2n;j++){
                fa[e.v][j]=fa[fa[e.v][j-1]][j-1];
                minn[e.v][j]=min(minn[e.v][j-1],minn[fa[e.v][j-1]][j-1]);
            }
            dfs(e.v,u);
        }
    }
    void init(){
        alloc(dep,n+1);
        alloc(fa,n+1);
        for(int**p=fa;p<=fa+n;p++)alloc(*p,log2n+1);
        alloc(minn,n+1);
        for(int**p=minn;p<=minn+n;p++)
            memset(alloc(*p,log2n+1),0x3f,(log2n+1)*sizeof(int));
        UFS::clear();
        dep[0]=0;
        for(int i=1;i<=n;i++){
            if(!dep[i]){
                dfs(i,0);
            }
        }
    }
    int lca(int u,int v){
        int ans=19260817;
        if(dep[u]<dep[v])swap(u,v);
        for(int j=log2n;j>=0;j--){
            if(dep[v]<=dep[fa[u][j]]){
                ans=min(ans,minn[u][j]);
                u=fa[u][j];
            }
        }
        if(u==v)return ans;
        for(int j=log2n;j>=0;j--){
            if(fa[u][j]!=fa[v][j]){
                ans=min(ans,min(minn[u][j],minn[v][j]));
                u=fa[u][j];
                v=fa[v][j];
            }
        }
        ans=min(ans,min(minn[u][0],minn[v][0]));
        return ans;
    }
}
void kruskal(){
    using namespace UFS;
    sort(el+1,el+m+1);
    init();
    for(int i=1;i<=m;i++){
        Edge2& e=el[i];
        if(find(e.u)!=find(e.v)){
            G[e.u].push_back(Edge(e.v,e.w));
            G[e.v].push_back(Edge(e.u,e.w));
            update(e.u,e.v);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    log2n=(int)log2(n)+1;
    alloc(G,n+1);
    alloc(el,m+1);
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        el[i]=Edge2(u,v,w);
    }
    kruskal();
    LCA::init();
    // for(int i=1;i<=n;i++){
	// 	for(int j=0;j<=log2n;j++){
	// 		printf("%d ",minn[i][j]);
	// 	}
	// 	printf("\n");
	// }
    // for(int i=1;i<=n;i++){
	// 	for(int j=0;j<=log2n;j++){
	// 		printf("%d ",fa[i][j]);
	// 	}
	// 	printf("\n");
	// }
    int q;scanf("%d",&q);
    while(q--){
        int u,v;scanf("%d%d",&u,&v);
        if(UFS::find(u)!=UFS::find(v)){
            printf("-1\n");
        }else{
            printf("%d\n",LCA::lca(u,v));
        }
    }
    return 0;
}