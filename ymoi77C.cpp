#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using std::vector;
using std::sort;
struct EdgeE{
    int u,v;
    int w;
    EdgeE(int u,int v,int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
    bool operator<(const EdgeE& e)const{
        return w<e.w;
    }
};
vector<EdgeE> a;
struct Bcj{
    int n;
    int* f;
    Bcj(int n){
        this->n=n;
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
        f[find(x)]=find(y);
    }
};
int main(){
    int n,m;scanf("%d%d",&n,&m);
    Bcj bcj=Bcj(n);
    a.reserve(m+4);
    int ans=0;
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        if(w==0)continue;
        (a.push_back(EdgeE(u,v,w)));
        ans+=w;
    }
    sort(a.begin(),a.end());
    int cnt=0;
    for(int i=0;cnt<=n-1&&i<a.size();i++){
        EdgeE& e=a[i];
        if(bcj.find(e.u)!=bcj.find(e.v)){
            bcj.update(e.u,e.v);
            cnt++;
            ans-=e.w;
        }
    }
    printf("%d\n",ans);
    return 0;
}