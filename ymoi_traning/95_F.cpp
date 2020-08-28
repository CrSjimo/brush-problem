#include<cstdio>
#include<cstdlib>
#include<cstring>
int MOD;
typedef long long ll;
struct Matrix{
    ll a[20][20];
    int n,m;
    Matrix(int n,int m){
        this->n=n;this->m=m;
        memset(a,0,sizeof(a));
    }
    void identity(){
        for(int i=1;i<=n;i++){
            a[i][i]=1;
        }
    }
    Matrix operator*(const Matrix& m2)const{
        Matrix ans(n,m2.m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m2.m;j++){
                for(int k=1;k<=m;k++){
                    (ans.a[i][j]+=(a[i][k]*m2.a[k][j])%MOD)%=MOD;
                }
            }
        }
        return ans;
    }
};
inline void _test_print(const Matrix& m2){
    for(int i=1;i<=m2.n;i++){
        for(int j=1;j<=m2.m;j++){
            printf("%lld ",m2.a[i][j]);
        }
        printf("\n");
    }
}
Matrix ksm(Matrix a,ll b){
    Matrix ans(a.n,a.m);
    ans.identity();
    for(;b;a=(a*a),b>>=1){
        if(b&1)ans=(ans*a);
    }
    return ans;
}
int b[20];
int c[20];
int main(){
    int k;scanf("%d",&k);
    Matrix B(k+1,k+1);
    Matrix A(1,k+1);
    int s=0;
    for(int i=1;i<=k;i++){
        scanf("%d",b+i);
        A.a[1][k+1]+=b[i];
    }
    for(int i=1;i<=k;i++){
        scanf("%d",c+i);
    }
    for(int i=1;i<=k;i++){
        A.a[1][i]=b[i];
        B.a[k-i+1][k]=B.a[k-i+1][k+1]=c[i];
    }
    for(int i=1;i<=k-1;i++){
        B.a[i+1][i]=1;
    }
    B.a[k+1][k+1]=1;
    int an,am;
    ll n,m;scanf("%lld%lld%d",&m,&n,&MOD);
    if(n<=k){
        an=b[n]%MOD;
    }else{
        Matrix C=A*ksm(B,n-k);
        an=C.a[1][k+1];
    }
    if(m-1<=k){
        am=b[m-1]%MOD;
    }else{
        Matrix C=A*ksm(B,m-1-k);
        am=C.a[1][k+1];
    }
    printf("%d\n",(an-am+MOD)%MOD);
    return 0;
}