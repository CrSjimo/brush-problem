#include<cstdio>
#include<cstdlib>
namespace bcj{
    int ans=0;
    int* f;
    int* siz;
    void init(int n){
        f=(int*)malloc((n+1)*sizeof(int));
        siz=(int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;i++)f[i]=i,siz[i]=1;
    }
    int find(int i){
        if(f[i]==i)return i;
        int fi = f[i];
        f[i]=find(f[i]);
        siz[i]=siz[f[i]];
        return f[i];
    }
    void update(int i,int j){
        int fi=find(i),fj=find(j);
        if(fi==fj)return;
        f[fi]=fj;
        siz[fj]+=siz[fi];
        siz[fi]=siz[fj];
    }
}
int main(){
    int n;scanf("%d",&n);
    bcj::init(n);
    int u,v;
    while(~scanf("%d%d",&u,&v)){
        bcj::update(v,u);
        printf("siz: ");
        for(int i=0;i<=n;i++)printf("%d ",bcj::siz[i]);
        printf("\n");
        printf("f: ");
        for(int i=0;i<=n;i++)printf("%d ",bcj::f[i]);
        printf("\n");
    }
    return 0;
}