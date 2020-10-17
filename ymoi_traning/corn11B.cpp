#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
using std::max_element;
using std::vector;
typedef vector< vector<int> > Tree;
Tree G1;
Tree G2;
int* dis1;
int* dis2;
int n,m;
void dfs(int* dis,const Tree& G,int u,int fa){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==fa)continue;
        dis[v]=dis[u]+1;
        dfs(dis,G,v,u);
    }
}
inline void init(int&n,int*&dis,Tree& G){
    scanf("%d",&n);
    G.resize(n+1);
    dis=(int*)calloc((n+1),sizeof(int));
    for(int i=1;i<=n-1;i++){
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}
int main(){
    init(n,dis1,G1);
    init(m,dis2,G2);
    int q;scanf("%d",&q);
    while(q--){
        int s1,s2;scanf("%d%d",&s1,&s2);
        memset(dis1,0,(n+1)*sizeof(int));
        memset(dis2,0,(m+1)*sizeof(int));
        dfs(dis1,G1,s1,0);
        dfs(dis2,G2,s2,0);
        // for(int i=1;i<=n;i++){
        //     printf("test1: %d %d\n",i,dis1[i]);
        // }
        // for(int i=1;i<=m;i++){
        //     printf("test2: %d %d\n",i,dis2[i]);
        // }
        printf("%d\n",*max_element(dis1+1,dis1+n+1)+1+*max_element(dis2+1,dis2+m+1));
    }
    return 0;
}