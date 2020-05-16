#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
using std::vector;
using std::queue;
struct Edge{
    int w,v;
    Edge(int w,int v){
        this->w=w;
        this->v=v;
    }
};
vector< vector<Edge> >G;
int* c;
int* ind;
int n;
queue<int> q;
int toposort(){
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i].v;
            if(c[u]>0)c[v]+=G[u][i].w*c[u];
            if(!--ind[v]){
                q.push(v);
            }
        }
    }
}
int main(){
    int m;scanf("%d%d",&n,&m);
    c=(int*)calloc(n+1,sizeof(int));
    ind=(int*)calloc(n+1,sizeof(int));
    G.resize(n+1);
    for(int i=1;i<=n;i++){
        int b;scanf("%d%d",&c[i],&b);
        if(c[i]==0)c[i]-=b;
        else q.push(i);
    }
    while(m--){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(Edge(w,v));
        ind[v]++;
    }
    toposort();
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(G[i].size()==0 && c[i]>0){
            printf("%d %d\n",i,c[i]);
            flag=false;
        }
    }
    if(flag){
        printf("NULL\n");
    }
    return 0;
}