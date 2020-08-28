#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
struct Bcj{
    int* f;
    int n;
    size_t siz;
    Bcj(int n){
        this->n=n;
        siz=n;
        f=(int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;i++){
            f[i]=i;
        }
    }
    ~Bcj(){
        free(f);
    }
    int find(int x){
        return f[x]==x?x:f[x]=find(f[x]);
    }
    void update(int x,int y){
        int fx=find(x),fy=find(y);
        f[fx]=fy;
        if(fx!=fy)siz--;
    }
    size_t size(){
        return siz;
    }
};
vector<int> s;
bool* ins;
vector<vector<int> >G;
int main(){
    int n,m;scanf("%d%d",&n,&m);
    G.resize(n+1);
    ins=(bool*)calloc((n+1),sizeof(bool));
    Bcj bcj(n);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);u++,v++;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int k;scanf("%d",&k);
    s.reserve(k+1);
    for(int i=1;i<=k;i++){
        int u;scanf("%d",&u);u++;
        s.push_back(u);
        ins[u]=1;
    }
    for(int u=1;u<=n;u++){
        if(ins[u])continue;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(ins[v])continue;
            bcj.update(u,v);
        }

    }
    vector<int> ss;ss.reserve(k+1);
    for(int i=k;i>=1;i--){
        ss.push_back(bcj.size()-s.size());
        int u=s.back();s.pop_back();ins[u]=false;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(ins[v])continue;
            bcj.update(u,v);
        }
    }
    ss.push_back(bcj.size());
    while(!ss.empty()){
        printf("%d\n",ss.back());ss.pop_back();
    }
    return 0;
}