#include<cstdio>
#include<cstdlib>
const int MOD=1e9+7;
typedef long long ll;
struct Matrix{
    ll** a;
    int n,m;
    Matrix(int n,int m){
        this->n=n;this->m=m;
        a=(ll**)malloc((n+1)*sizeof(ll*));
        for(ll**p=a;p<=a+n;p++){
            *p=(ll*)calloc((m+1),sizeof(ll));
        }
    }
    ~Matrix(){
        for(ll**p=a;p<=a+n;p++){
            free(*p);
        }
        free(a);
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

int main(){
    int n,p,m;
    scanf("%d%d%d",&n,&p,&m);
    Matrix A1(n,p),A2(p,m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=p;j++){
            scanf("%lld",&A1.a[i][j]);
            A1.a[i][j]=(A1.a[i][j]%MOD+MOD)%MOD;
        }
    }
    for(int i=1;i<=p;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&A2.a[i][j]);
            A2.a[i][j]=(A2.a[i][j]%MOD+MOD)%MOD;
        }
    }
    Matrix A3=A1*A2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%lld ",A3.a[i][j]);
        }
        printf("\n");
    }
    return 0;
}