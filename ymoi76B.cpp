#include<cstdio>
#include<cstdlib>
namespace Bcj{
    int* f;int n;
    inline void init(int N){
        n=N;
        f=(int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;i++)f[i]=i;
    }
    int find(int x){
        return f[x]==x?x:f[x]=find(f[x]);
    }
    inline void update(int x,int y){
        f[find(x)]=find(y);
    }
    inline size_t size(){
        size_t siz=0;
        for(int i=1;i<=n;i++){
            siz+=(f[i]==i);
        }
        return siz;
    }
}
int c;
inline int h(int x,int y){
    return (x-1)*c+y;
}
int main(){
    int m;scanf("%d%d",&c,&m);
    int n=c*c;
    Bcj::init(n);
    for(int i=1;i<=m;i++){
        char*s=new char[4];
        int x,y;
        scanf("%d%d%s",&x,&y,s);
        int u=h(x,y);
        int v=(*s=='D'?h(x+1,y):h(x,y+1));
        if(Bcj::find(u)==Bcj::find(v)){
            printf("%d\n",i);
            return 0;
        }
        Bcj::update(u,v);
    }
    printf("draw\n");
    return 0;
}/*
3 5
1 1 D
1 1 R
1 2 D
2 1 R
2 2 D
*/