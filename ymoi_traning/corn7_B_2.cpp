#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
using std::set;
using std::min;
using std::vector;
using std::queue;

set<int> vis[105][1<<15];

struct Node{
    int d;
    int S;
    int u;
    Node(int u,int S,int d){
        this->u=u;
        this->S=S;
        this->d=d;
    }
};
int w[104];
int k[104];
vector<int> G[104];
int ar[104];
int n,m;
int ans=0x7fffffff;
void dfs(int u,int S,int d){
    ar[u]++;
    vis[u][S].insert(d);
    if(S==(1<<(m+1))-1){
        // printf("test: %d %d\n",u,d);
        // for(int i=1;i<=n;i++){
        //     if(ar[i])printf("%d ",i);
        // }
        // printf("\n");
        ans=min(ans,d);
        ar[u]--;
        return;
    }
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        int nS=S|(1<<k[u]);
        int nd=d+w[v]*(!ar[v]);
        if(vis[v][nS].count(nd))continue;
        dfs(v,nS,nd);
    }
    ar[u]--;
}
int kmw[15];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",k+i);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",w+i);
    }
    bool spc1=true;
    bool spc2=true;
    for(int i=1;i<=n-1;i++){
        int u,v;scanf("%d%d",&u,&v);
        if(!(u==i&&v==i+1))spc1=false;
        if(!(u==1&&v==i+1))spc2=false;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(spc2 && n>10){
        memset(kmw,0x3f,sizeof(kmw));
        if(k[1]){
            kmw[k[1]]=0;
        }
        for(int i=2;i<=n;i++){
            if(k[i])kmw[k[i]]=min(kmw[k[i]],w[i]);
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            ans+=kmw[i];
        }
        printf("%d\n",ans+w[1]);
        return 0;
    }else dfs(1,0,w[1]);
    printf("%d\n",ans);
    return 0;
}