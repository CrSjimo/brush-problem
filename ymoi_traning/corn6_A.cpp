#include<cstdio>
#include<cstdlib>
#include<cstring>
typedef long long ll;
const ll MOD = 998244353;
ll C[30][30];
void dabiao(){
    C[0][0]=C[1][0]=C[1][1]=1;
    for(int i=2;i<=25;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
}
struct Matrix{
    ll a[50][50];
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
            printf("%4lld ",m2.a[i][j]);
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
ll ksm(ll a,ll b){
    ll ans=1;
    for(;b;a=(a*a)%MOD,b>>=1){
        if(b&1)ans=(ans*a)%MOD;
    }
    return ans;
}
ll b[50];
int main(){
    dabiao();
    int n,k;scanf("%d%d",&n,&k);
    if(n<=2){
        printf("1\n");
        return 0;
    }
    Matrix B(2*k+2,2*k+2),A(1,2*k+2);
    for(int i=0;i<k;i++){
        scanf("%lld",b+i);
        b[i]%=MOD;
    }
    A.a[1][1]=A.a[1][2]=1;
    B.a[2][1]=B.a[1][2]=B.a[2][2]=1;
    for(int i=0;i<k;i++){
        ll mi=ksm(3,i);
        A.a[1][3+i]=mi;
        A.a[1][3+k+i]=(b[i]*mi)%MOD;
    }
    for(int i=0;i<k;i++){
        B.a[3+k+i][2]=1;
        for(int j=0;j<=i;j++){
            B.a[3+j][3+i]=C[i][j];
            B.a[3+j][3+k+i]=(b[i]*C[i][j])%MOD;
        }
    }
    // _test_print(A);
    // printf("\n");
    // _test_print(B);
    Matrix C=ksm(B,n-2);
    A=A*C;
    printf("%lld\n",A.a[1][2]);
    return 0;
}