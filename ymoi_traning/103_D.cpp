#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>
using std::vector;
using std::max;
struct Node{
    int v[2];
    bool tag;
} b [3300000];
int tot=1;
int rt = 1;
void insert(int x){
    int p=rt;
    for(int i=31;i>=0;i--){
        char w=(x>>i)&1;
        if(!b[p].v[w])b[p].v[w]=(++tot);
        p=b[p].v[w];
    }
    b[p].tag=true;
}
int find(int x){
    int p=rt;
    int ans=0;
    for(int i=31;i>=0;i--){
        char w=(x>>i)&1;
        if(b[p].v[w^1]){
            p=b[p].v[w^1];
            ans|=(1<<i);
        }else if(b[p].v[w]){
            p=b[p].v[w];
        }else return ans;
    }
    return ans;
}
struct Edge{
    int v,w;
    Edge(){};
    Edge(int v,int w){
        this->v=v;
        this->w=w;
    }
};
vector<vector<Edge> >G;
int f[100010];
void dfs(int u,int x,int fa){
    f[u]=x;
    for(int i=0;i<G[u].size();i++){
        Edge& e=G[u][i];
        if(e.v==fa)continue;
        dfs(e.v,x^e.w,u);
    }
}
int main(){
    int n;scanf("%d",&n);
    G.resize(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
    }
    dfs(1,0,-1);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,find(f[i]));
        insert(f[i]);
    }
    printf("%d\n",ans);
    return 0;
}