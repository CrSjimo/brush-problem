#include<cstdio>
#include<map>
#include<cmath>
using std::map;

#define int long long

typedef long long ll;

int MOD;

ll ksm(ll a,ll k){
    ll ans=1;
    for(;k;a=(a*a)%MOD,k>>=1){
        if(k&1)ans=(ans*a)%MOD;
    }
    return ans;
}

void exgcd(int a,int b,int& x,int& y){
    if(b==0){
        x=1;y=0;
    }else{
        int _x,_y;
        exgcd(b,a%b,_x,_y);
        x=_y;y=_x-(a/b)*_y;
    }
}

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

void task1(int y,int z,int p){
    MOD = p;
    printf("%lld\n",ksm(y,z));
}

void task2(int y,int z,int p){
    int ccp = gcd(y,p);
    if(z%ccp){
        printf("Orz, I cannot find x!\n");
        return;
    }
    int x,trash;
    exgcd(y,p,x,trash);
    x=x*z/ccp;
    int mod = p/ccp;
    x=(x%mod+mod)%mod;
    printf("%lld\n",x);
}

ll bsgs(int a,int b,int p){
    if(b==1)return 0;
    if(a%p==0&&b)return -1;
    MOD = p;
    map<ll,int> mp;
    int t=ceil(sqrt(p));
    ll s=b%p;
    for(int i=1;i<=t;i++){
        s=(s*a)%p;
        mp[s]=i;
    }
    ll a_sqrtt = ksm(a,t);
    s=1;
    for(int i=1;i<=t;i++){
        s=(s*a_sqrtt)%p;
        if(mp.count(s)){
            int j=mp[s];
            return ((i*t)%p-j)%p;
        }
    }
    return -1;
}

void task3(int y,int z,int p){
    ll ans = bsgs(y,z,p);
    if(ans!=-1)printf("%lld\n",ans);
    else printf("Orz, I cannot find x!\n");
}

#undef int
int main(){
#define int long long
    int cas,k;
    scanf("%lld%lld",&cas,&k);
    while(cas--){
        int y,z,p;scanf("%lld%lld%lld",&y,&z,&p);
        if(k==1){
            task1(y,z,p);
        }else if(k==2){
            task2(y,z,p);
        }else{
            task3(y,z,p);
        }
    }
    return 0;
}

