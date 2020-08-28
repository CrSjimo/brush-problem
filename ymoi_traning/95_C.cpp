#include<cstdio>
#include<cstdlib>
#include<cstring>
int MOD;
typedef long long ll;
struct Matrix{
    ll a[4][4];
    int n,m;
    // Matrix(const Matrix& m2){
    //     this->n=m2.n;this->m=m2.m;
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             a[i][j]=m2.a[i][j];
    //         }
    //     }
    // }
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
Matrix ksm(Matrix a,int b){
    Matrix ans(a.n,a.m);
    ans.identity();
    for(;b;a=(a*a),b>>=1){
        if(b&1)ans=(ans*a);
    }
    return ans;
}
int main(){
    Matrix B(3,3);
    B.a[1][2]=B.a[2][1]=B.a[2][2]=1;
    B.a[1][3]=B.a[2][3]=B.a[3][3]=1;
    int n;scanf("%d%d",&n,&MOD);
    Matrix A(1,3);
    A.a[1][1]=A.a[1][2]=1;
    A.a[1][3]=2;
    if(n<=2){
        printf("1\n");
    }else{
        Matrix C=ksm(B,n-2);
        A=A*C;
        printf("%lld\n",A.a[1][3]);
    }
    return 0;
}