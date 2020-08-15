#include<cstdio>
typedef long long ll;
int C[5014][5014];
const int MOD = 1e9+7;
void init(int m){
    C[0][0]=C[1][0]=C[1][1]=1;
    for(int i=2;i<=m;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
}
ll ksm(ll a,ll k){
    ll ans=1;
    for(;k;a=(a*a)%MOD,k>>=1){
        if(k&1)ans=(ans*a)%MOD;
    }
    return ans;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    init(m+5);
    int ans = ksm(n,m+1);
    for(int i=0;i<=m-1;i++){
        ll s=0;
        for(int j=1;j<=n;j++){
            s=(s+ksm(j,i))%MOD;
        }
        s=(s*C[m+1][i])%MOD;
        if((m-i)&1){
            ans+=s;
        }else{
            ans-=s;
        }
    }
    printf("%d\n",ans);
    return 0;
}