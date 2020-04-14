#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::min;
bool f[105][105];
int cnt = 0;
int main(){
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&u,&v);
        f[u][v]|=1;
    }
    for(int k=1;k<=n;k++){
        f[k][k]|=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]|=f[i][k]&f[k][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        int cc1 = 0,cc2=0;
        for(int j=1;j<=n;j++){
            //printf("%d ",f[i][j]);
            cc1+=f[i][j];
            cc2+=f[j][i];
        }
        //printf("\n");
        if(cc1>(n+1)/2||cc2>(n+1)/2)cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}