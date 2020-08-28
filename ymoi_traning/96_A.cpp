#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
struct Bcj{
    int* f;
    int* pos;
    int* len;
    Bcj(int n){
        f=(int*)malloc((n+1)*sizeof(int));
        pos=(int*)malloc((n+1)*sizeof(int));
        len=(int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;i++){
            f[i]=i;
            len[i]=pos[i]=1;
        }
    }
    ~Bcj(){
        free(f);free(pos);free(len);
    }
    int find(int x){
        if(f[x]==x){
            return x;
        }else{
            int ff=find(f[x]);
            pos[x]+=pos[f[x]]-1;
            return f[x]=ff;
        }
    }
    void update(int x,int y){ // connect x after y
        int fx=find(x),fy=find(y);
        f[fx]=fy;
        pos[fx]+=len[fy];
        len[fy]+=len[fx];
    }
};
char op[4];
int main(){
    Bcj bcj(30000);
    int q;scanf("%d",&q);
    while(q--){
        int x,y;scanf("%s%d%d",op,&x,&y);
        if(op[0]=='M'){
            bcj.update(x,y);
        }else if(op[0]=='C'){
            if(bcj.find(x)!=bcj.find(y)){
                printf("-1\n");
            }else{
                printf("%d\n",abs(bcj.pos[x]-bcj.pos[y])-1);
            }
        }
        // for(int i=1;i<=4;i++){
        //     printf("test: %d %d %d %d\n",i,bcj.f[i],bcj.pos[i],bcj.len[i]);
        // }
    }
    return 0;
}