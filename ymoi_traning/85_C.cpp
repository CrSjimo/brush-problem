#include<cstdio>
#include<cstdlib>
int n,m,k;
int C[2010][2010];
void init(){
    C[0][0]=C[1][0]=C[1][1]=1;
    for(int i=0;i<=2000;i++){
        C[i][0]=1;
    }
    for(int i=1;i<=2000;i++){
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%k;
        }
    }
    for(int i=1;i<=2000;i++){
        for(int j=1;j<=i;j++){
            C[i][j]=!C[i][j];
        }
    }
    for(int i=1;i<=2000;i++){
        for(int j=1;j<=2000;j++){
            C[i][j]+=(C[i-1][j]+C[i][j-1]-C[i-1][j-1]);
        }
    }
}    
int main(){
    int t;
    scanf("%d%d",&t,&k);
    init();
    while(t--){
        scanf("%d%d",&n,&m);
        printf("%d\n",C[n][m]);
    }
    return 0;
}