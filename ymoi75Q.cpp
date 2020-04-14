#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::min;
int** f;
int** a;
int n;
int ans = 0x3f3f3f3f;
void min_cir(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=k-1;i++)
            for(int j=i+1;j<=k-1;j++){
                ans=min(ans,f[i][j]+a[j][k]+a[k][i]);
            }
                
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    }
}
int main(){
    int m;scanf("%d%d",&n,&m);
    f=(int**)malloc((n+1)*sizeof(int*));
    for(int**p=f;p<=f+n;p++)
        memset(*p=(int*)malloc((n+1)*sizeof(int)),0x3f,(n+1)*sizeof(int));
    a=(int**)malloc((n+1)*sizeof(int*));
    for(int**p=a;p<=a+n;p++)
        memset(*p=(int*)malloc((n+1)*sizeof(int)),0x3f,(n+1)*sizeof(int));
    while(m--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        f[u][v]=f[v][u]=a[u][v]=a[v][u]=w;
    }
    for(int i=1;i<=n;i++)f[i][i]=0;

    min_cir();
    if(ans==0x3f3f3f3f){
        printf("no\n");
    }else
        printf("%d\n",ans);
    return 0;
}