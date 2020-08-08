#include<cstdio>
#include<cstdlib>
const int YARIMASUNE = 5+
                       11+4514+
                       11+4514
                       +19+19+810
                       +11+45+14
                       +11+4+5+14;
int C[1005][1005];
void init(){
    C[0][0]=C[1][0]=C[1][1]=1;
    for(int i = 2;i<=1000;i++){
        C[i][0]=1;
        for(int j=1;j<=1000;j++){
            C[i][j]=(C[i-1][j-1]%YARIMASUNE+C[i-1][j]%YARIMASUNE)%YARIMASUNE;
        }
    }
}
int ksm(int a,int b){
    int ans = 1;
    for(;b;a=(a*a)%YARIMASUNE,b>>=1){
        if(b&1)ans=(ans*a)%YARIMASUNE;
    }
    return ans;
}
int main(){
    init();
    int a,b,k,n,m;scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
    a%=YARIMASUNE;b%=YARIMASUNE;
    printf("%d\n",(C[k][n]*ksm(a,n)%YARIMASUNE)*ksm(b,m)%YARIMASUNE);
}
