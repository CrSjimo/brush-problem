#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::sort;
struct Bcj{
    int* f;
    Bcj(int n){
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
struct Edge2{
    int u,v,w;
    Edge2(){}
    Edge2(int u,int v,int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
    bool operator<(const Edge2& e)const{
        return w<e.w;
    }
}* el;
int main(){
    int n,m;scanf("%d%d",&n,&m);
    Bcj bcj(n);
    el=(Edge2*)malloc((m+1)*sizeof(Edge2));
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&el[i].u,&el[i].v,&el[i].w);
    }
    sort(el+1,el+m+1);
    int ans=0,cnt=0;
    for(int i=1;i<=m;i++){
        int u=el[i].u,v=el[i].v,w=el[i].w;
        if(bcj.find(u)!=bcj.find(v)){
            bcj.update(u,v);
            ans+=w;
            cnt++;
        }
        if(cnt>n-1){
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}