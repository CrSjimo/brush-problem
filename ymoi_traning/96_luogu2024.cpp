#include<cstdio>
#include<cstdlib>
struct Bcj{
    int* f;
    size_t siz;
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
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int cnt=0;
    Bcj bcj(3*n);
    while(k--){
        int op,x,y;scanf("%d%d%d",&op,&x,&y);
        if(x>n||y>n){
            cnt++;
            continue;
        }
        if(op==1){
            if(bcj.find(x)==bcj.find(y+n)||bcj.find(x+n)==bcj.find(y)){
                cnt++;
                continue;
            }
            bcj.update(x,y);
            bcj.update(x+n,y+n);
            bcj.update(x+2*n,y+2*n);
        }else if(op==2){
            if(bcj.find(x)==bcj.find(y)||bcj.find(x+n)==bcj.find(y)){
                cnt++;
                continue;
            }
            bcj.update(x,y+n);
            bcj.update(x+n,y+2*n);
            bcj.update(x+2*n,y);
        }
    }
    printf("%d\n",cnt);
    return 0;
}