#include<cstdio>
#include<cstdlib>
namespace Bcj{
    int* f;
    inline void init(int n){
        f=(int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;i++)f[i]=i;
    }
    int find(int x){
        return f[x]==x?x:f[x]=find(f[x]);
    }
    inline void update(int x,int y){
        f[find(x)]=find(y);
    }
}
int main(){
    int n,m;scanf("%d%d",&n,&m);
    Bcj::init(n);
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        Bcj::update(x,y);
    }
    int q;scanf("%d",&q);
    while(q--){
        int x,y;scanf("%d%d",&x,&y);
        printf(Bcj::find(x)==Bcj::find(y)?"Yes\n":"No\n");
    }
    return 0;
}