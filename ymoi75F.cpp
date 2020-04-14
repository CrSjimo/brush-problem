#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::min;
int** f;
int* w;
#define fr(x) for(int x=1;x<=n;x++)
int n;
int main(){
    scanf("%d",&n);
    w=(int*)malloc((n+1)*sizeof(int));
    f=(int**)malloc((n+1)*sizeof(int*));
    for(int**p=f;p<=f+n;p++)memset(*p=(int*)malloc((n+1)*sizeof(int)),0x3f,(n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        f[i][i]=0;
        int x,y;scanf("%d%d%d",w+i,&x,&y);
        f[i][x]=f[x][i]=1;
        f[i][y]=f[y][i]=1;
    }
    fr(k)fr(i)fr(j)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    int minn = 0x3f3f3f3f;
    fr(i){
        int val=0;
        fr(j)val+=w[j]*f[i][j];
        minn=min(val,minn);
    }
    printf("%d\n",minn);
    return 0;
}