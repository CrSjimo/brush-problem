#include<cstdio>
#include<cstdlib>
namespace Bcj{
    int* f;int n;
    int* prefix;
    int* cnt;
    inline void init(int N){
        n=N;
        f=(int*)malloc((n+1)*sizeof(int));
        prefix=(int*)calloc((n+1),sizeof(int));
        cnt=(int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;i++){
            f[i]=i;
            cnt[i]=1;
        }
    }

    //f is pre x
    int find(int x){
        if(f[x]==x){
            return x;
        }else{
            int ff = find(f[x]);
            prefix[x]+=prefix[f[x]];
            return f[x]=ff;
        }
    }
    void update(int x,int y){
        int fx=find(x),fy=find(y);
        f[fx]=fy;
        prefix[fx]+=cnt[fy];
        cnt[fy]+=cnt[fx];
    }
}
inline int abs(int a){return a>0?a:-a;}
int main(){
    Bcj::init(30000);
    int q;scanf("%d",&q);
    while(q--){
        char* s=new char[4];
        int x,y;scanf("%s%d%d",s,&x,&y);
        if(*s=='M'){
            Bcj::update(x,y);
        }else{
            printf("%d\n",Bcj::find(x)==Bcj::find(y)?abs(Bcj::prefix[x]-Bcj::prefix[y])-1:-1);
        }
    }
    return 0;
}