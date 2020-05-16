#include<cstdio>
#include<cstdlib>
#include<set>
using std::set;
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
    void update(int x,int y){
        f[find(x)]=find(y);
    }
}
int main(){
    int n,m;scanf("%d%d",&n,&m);
    Bcj::init(n*2);
    while(m--){
        int k,x,y;scanf("%d%d%d",&k,&x,&y);
        if(k==0){
            Bcj::update(x,y);
        }else{
            Bcj::update(x+n,y);
            Bcj::update(x,y+n);
        }
    }
    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(Bcj::find(i));
    }
    printf("%ld\n",s.size());
    return 0;
}/*
6 4
1 1 4
0 3 5
0 4 6
1 1 2
*/