#include<cstdio>

int C[10010][10010];

const int MOD = 10007;

void init(){
    C[0][0]=C[1][0]=C[1][1]=1;
    for(int i=2;i<=10007;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
}

int main(){
    init();
    int cas;scanf("%d",&cas);
    while(cas--){
        int n,m;scanf("%d%d",&n,&m);
        int ans=1;
        while(n){
            int nk=n%MOD,mk=m%MOD;
            ans=(ans*C[nk][mk])%MOD;
            n/=MOD,m/=MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}