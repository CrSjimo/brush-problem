#include<cstdio>
#include<cstdlib>
namespace Ufs{
    int* f;
    int n;
    inline void init(int _n){
        n=_n;
        f=(int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;i++)f[i]=i;
    }
    int find(int i){
        return f[i]==i?i:f[i]=find(f[i]);
    }
    inline void update(int i,int j){
        f[find(i)]=find(j);
    }
    inline int size(){
        int siz=0;
        for(int i=1;i<=n;i++){
            if(f[i]==i)siz++;
        }
        return siz;
    }
}
bool f[205][205];
int main(){
    int n;scanf("%d",&n);
    Ufs::init(n);
    for(int i=1;i<=n;i++){
        f[i][i]|=1;
        int v;
        while(~scanf("%d",&v)&&v){
            f[i][v]|=1;
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]|=f[i][k]&f[k][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(f[i][j]){
                Ufs::f[j]=Ufs::f[i];
            }
        }
    }
    printf("%d\n",Ufs::size());
    return 0;
}