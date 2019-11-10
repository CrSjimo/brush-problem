#include<stdio.h>
#include<vector>
#include<algorithm>
struct Node{
    Node* pre;
    int id;
    std::vector<Node*> next;
};
std::vector< Node > treemap;
struct edge{
    int x,y;
    int w;
};
typedef edge egde;
struct Edge{
    int w;
    int next;
};
std::vector< std::vector<Edge> > map;
bool cmp(egde& e1,edge& e2){
    return e1.w>e2.w;
}
std::vector<edge> elist;
int bcj[10020];
void init(int n){
    while(n--){
        bcj[n] = n;
    }
}
int query(int i){
    if(bcj[i]==i){
        return i;
    }
    return bcj[i] = query(bcj[i]);
}
void update(int i,int j){
    bcj[query(i)] = query(j);
}
void kruskal(){
    std::sort(elist.begin(),elist.end(),cmp);
    for(int i = 0;i<elist.size();i++){
        edge e = elist[i];
        if(query(e.x)!=query(e.y)){
            update(e.x,e.y);
            Edge ee;
            ee.w=e.w;

            ee.next=e.y;
            map[e.x].push_back(ee);
            ee.next = e.x;
            map[e.y].push_back(ee);
        }
    }
}
int dep[10010];
int pre[10010];
bool vis[10010];
int w[10010][25];
int fa[10010][25];
void dfs(int u,int depth,int faa){
    vis[u]=1;
    for(int i=0;i<map[u].size();i++){
        if(map[u][i].next==faa)continue;
        #ifdef DEBUG
        printf("test-id:%d %d %d\n",u,map[u][i].next,depth);
        #endif
        dep[map[u][i].next]=depth+1;
        pre[map[u][i].next]=faa;
        fa[map[u][i].next][0]=u;
        w[map[u][i].next][0]=map[u][i].w;
        dfs(map[u][i].next,depth+1,u);
    }
}
int lca(int x,int y){
    if(query(x)!=query(y))return -1;
    if(dep[x]>dep[y])std::swap(x,y);
    int ans = 0x3f3f3f3f;
    for(int i = 20;i>=0;i--){
        if(dep[fa[y][i]]>=dep[x]){
            ans = std::min(ans,w[y][i]);
            y=fa[y][i];
        }
    }
    if(x==y)return ans;
    for(int i = 20;i>=0;i--){
        if(fa[y][i]!=fa[x][i]){
            ans = std::min(ans,std::min(w[x][i],w[y][i]));
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return std::min(ans,std::min(w[x][0],w[y][0]));
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    map.resize(n+10);
    init(n+10);
    // for(int i = 0;i<n+5;i++){
    //     map[i].resize(n+10);
    // }
    for(int i = 0;i<m;i++){
        edge e;
        scanf("%d%d%d",&e.x,&e.y,&e.w);
        elist.push_back(e);
    }
    kruskal();
    // for(int i = 1;i<=n;i++){
    //     for(int j = 1;j<=n;j++){
    //         printf("%d ",map[i][j]);
    //     }
    //     printf("\n");
    // }
    // for(int k = 1;k<=n;k++){
    //     for(int i = 1;i<=n;i++){
    //         for(int j = 1;j<=n;j++){
    //             map[i][j] = std::max(map[i][j],std::min(map[i][k],map[k][j]));
    //         }
    //     }
    // }
    dep[1]=0;
    w[1][0]=0x3f3f3f3f;
    fa[1][0]=1;
    dfs(1,0,-1);
    #ifdef DEBUG
    for(int i = 1;i<=4;i++){
        printf("test:%d %d\n",i,dep[i]);
    }
    #endif
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            dep[i]=0;
            dfs(i,0,-1);
            fa[i][0]=i;
            w[i][0]=0x3f3f3f3f;
        }
    }
    for(int k=1;k<=20;k++){
        for(int i = 1;i<=n;i++){
            fa[i][k]=fa[fa[i][k-1]][k-1];
            w[i][k]=std::min(w[i][k-1],w[fa[i][k-1]][k-1]);
            
        }
        
    }
    #ifdef DEBUG
    for(int k=0;k<=20;k++){
        for(int i=1;i<=n;i++){printf("%d ",w[i][k]);
        }
        printf("\n");
    }
    for(int k=0;k<=20;k++){
        for(int i=1;i<=n;i++){printf("%d ",fa[i][k]);
        }
        printf("\n");
    }
    #endif
    int q;
    scanf("%d",&q);
    while(q--){
        int s,t;
        scanf("%d%d",&s,&t);
        // if(map[s][t]==0)map[s][t] = -1;
        printf("%d\n",lca(s,t));
    }
    return 0;
}