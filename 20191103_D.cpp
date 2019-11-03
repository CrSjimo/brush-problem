#include<stdio.h>
const int MOD = 10007;
int mi(int a,int k){
    if(a==1)return 1;
    int ans=1;
    int t=a;
    while(k){
        if(k&1) ans=ans*t%MOD; 
        t=t*t%MOD;
        k/=2;
    }
    return ans;
}
int C[1005][1005];
void dabiao(){
    C[0][0]=C[1][0]=C[1][1]=1;
    for(int i = 2;i<=1000;i++){
        C[i][0]=1;
        for(int j=1;j<=1000;j++){
            C[i][j]=(C[i-1][j-1]%MOD+C[i-1][j]%MOD)%MOD;
        }
    }
}
int main(){
    dabiao();
    int a,b,k,n,m;
    scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
    printf("%d\n",(((C[k][n]*mi(a,n))%MOD)*mi(b,m))%MOD);
    return 0;
}
