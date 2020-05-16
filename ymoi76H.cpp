#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
namespace CcBcj{
    int* f;
    int n;
    int cnt;
    void init(int N){
        cnt=n=N;
        f=(int*)malloc((n)*sizeof(int));
        for(int i=0;i<n;i++)f[i]=i;
    }
    int find(int x){
        return f[x]==x?x:f[x]=find(f[x]);
    }
    void update(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx!=fy){
            f[fx]=fy;
            cnt--;
        }
    }
}
vector< vector<int> > G;
int* nodes;
bool* del;
int* anses;
int main(){
    int n,m;scanf("%d%d",&n,&m);
    CcBcj::init(n);
    del=(bool*)calloc(n,sizeof(bool));
    G.resize(n);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    int k;scanf("%d",&k);
    nodes=(int*)malloc(k*sizeof(int));
    anses=(int*)malloc((k+1)*sizeof(int));
    for(int i=0;i<k;i++){
        scanf("%d",nodes+i);
        del[nodes[i]]=true;
    }
    CcBcj::cnt=n-k;
    for(int u=0;u<n;u++){
        if(del[u])continue;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(del[v])continue;
            CcBcj::update(u,v);
        }
    }
    anses[k]=CcBcj::cnt;
    for(int i=k-1;i>=0;i--){
        int u=nodes[i];
        del[u]=false;
        CcBcj::cnt++;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(del[v])continue;
            CcBcj::update(u,v);
        }
        anses[i]=CcBcj::cnt;
    }
    for(int i=0;i<=k;i++){
        printf("%d\n",anses[i]);
    }
    return 0;
}