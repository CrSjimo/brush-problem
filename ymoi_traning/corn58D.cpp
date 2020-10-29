#include<cstdio>
#include<cstdlib>
#include<cstring>
namespace maker{
    unsigned long long N,p,q,r=0;
    void init(){scanf("%llu%llu%llu",&N,&p,&q);}
    unsigned long long rand(){
	    q^=q<<37,q^=q>>13,q^=q<<53,r+=p;
        return (q^r)%N+1;
    }
}
const int MOD=998244353;
typedef long long ll;
struct Matrix{
    ll a[3][3];
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
Matrix ksm(Matrix a,int b){
    Matrix ans(a.n,a.m);
    ans.identity();
    for(;b;a=(a*a),b>>=1){
        if(b&1)ans=(ans*a);
    }
    return ans;
}
inline ll mod(ll x){
    return (x%MOD+MOD)%MOD;
}
int main(){
    freopen("hy.in","r",stdin);
    freopen("hy.out","w",stdout);
    ll a1,a2,b,c,t;
    scanf("%lld%lld%lld%lld%lld",&a1,&a2,&b,&c,&t);
    a1=mod(a1),a2=mod(a2),b=mod(b),c=mod(c);
    maker::init();
    ll ans=0;
    while(t--){
        ll n = maker::rand();
        Matrix B(2,2);
        B.a[1][2]=c;
        B.a[2][1]=1;
        B.a[2][2]=b;
        Matrix A(1,2);
        A.a[1][1]=a1,A.a[1][2]=a2;
        if(n<=2){
            ans^=mod(A.a[1][n]);
        }else{
            Matrix C=ksm(B,n-2);
            A=A*C;
            ans^=mod(A.a[1][2]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}