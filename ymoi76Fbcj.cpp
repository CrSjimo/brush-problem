/** 
 * use union-find set
 * use dfs @see ymoi76F.cpp
*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::max_element;
namespace Bcj{
    int* f;
    int* w;
    int* num;
    inline void init(int n){
        f=(int*)malloc((n+1)*sizeof(int));
        w=(int*)malloc((n+1)*sizeof(int));
        num=(int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;i++){
            f[i]=i;
            num[i]=1;
        }
    }
    int find(int x){
        if(f[x]==x){
            return x;
        }else{
            f[x]=find(f[x]);
            num[x]=num[f[x]];
            w[x]=w[f[x]];
            return f[x];
        }
    }
    inline void update(int x,int y){
        int fx=find(x),fy=find(y);
        f[fx]=fy;
        num[fy]+=num[fx];
        w[fy]+=w[fx];
    }
}
int main(){
    int n;scanf("%d",&n);
    Bcj::init(n);
    for(int i=1;i<=n;i++){
        scanf("%d",&Bcj::w[i]);
    }
    int m;scanf("%d",&m);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);Bcj::update(u,v);
    }
    int max_w_f=max_element(Bcj::w+1,Bcj::w+n+1)-Bcj::w;
    int max_num_f=max_element(Bcj::num+1,Bcj::num+n+1)-Bcj::num;
    max_w_f=Bcj::find(max_w_f);
    max_num_f=Bcj::find(max_num_f);
    for(int i=1;i<=n;i++){
        if(Bcj::find(i)==max_num_f){
            printf("%d ",i);
        }
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        if(Bcj::find(i)==max_w_f){
            printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}