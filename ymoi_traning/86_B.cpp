#include<cstdio>
#include<cstdlib>

typedef long long ll;

int exgcd(ll a,ll b,ll& x,ll& y){
    if(b==0){
        x=1;y=0;
        return a;
    }else{
        ll _x,_y;
        int ccp = exgcd(b,a%b,_x,_y);
        x=_y;y=_x-(a/b)*_y;
        return ccp;
    }
}
int n;
struct Node{int a,b;} num[114514];
inline ll vnmod(ll x,ll mod){
    return (x%mod+mod)%mod;
}
//b>a
ll exCRT(){
    ll ans=num[1].a,M=num[1].b;
    for(int i=2;i<=n;i++){
        ll c=vnmod(num[i].a-ans,num[i].b);
        ll x,y;
        int ccp=exgcd(M,num[i].b,x,y);
        if(c%ccp)return -1;
        ll t=num[i].b/ccp;
        x=x*c/ccp%t;
        ans+=M*x;
        M*=t;
        ans=vnmod(ans,M);
    }
    return ans;
}
int main(){
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d%d",&num[i].b,&num[i].a);
        }
        printf("%lld\n",exCRT());
    }
    return 0;
}