#include<cstdio>
#include<cstdlib>
int** f;
int main(){
    int n,m,q;scanf("%d%d%d",&n,&m,&q);
    f=(int**)malloc((n+1)*sizeof(int*));
    for(int i=0;i<=n;i++){
        f[i]=(int*)calloc((m+1),sizeof(int));if(!i)continue;
        for(int j=1;j<=m;j++){
            int k;scanf("%d",&k);
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+k;
        }
    }
    while(q--){
        int x1,x2,y1,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",f[x2][y2]-f[x1-1][y2]+f[x1-1][y1-1]-f[x2][y1-1]);
    }
    return 0;
}