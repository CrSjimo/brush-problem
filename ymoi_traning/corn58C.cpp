#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
using std::vector;
using std::map;
int n,m;
const int MOD = 998244353;
typedef long long ll;
int lis[6];
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
struct Frac{
    ll a,b;
    Frac(){a=0,b=1;}
    Frac(ll x){a=x,b=1;};
    Frac(ll a,ll b){this->a=a;this->b=b;yf();}
    void yf(){
        if(a==0)b=1;
        else{
            int s1=1,s2=1;
            if(a<0){
                s1=-1,a=-a;
            }
            if(b<0){
                s2=-1,b=-b;
            }
            ll ccp=gcd(a,b);
            a/=ccp;b/=ccp;
            if(s1*s2<0){
                a*=-1;
            }
        }
    }
    Frac& operator+=(const Frac& f){
        a=a*f.b+f.a*b;
        b=b*f.b;
        yf();
        return *this;
    }
    Frac& operator-=(const Frac& f){
        a=a*f.b-f.a*b;
        b=b*f.b;
        yf();
        return *this;
    }
    Frac& operator/=(int k){
        b*=k;
        yf();
        return *this;
    }
    Frac& operator*=(int k){
        a*=k;
        yf();
        return *this;
    }
    ll toInt(){
        if(b==1)return a;
        ll tmp=a;
        for(int i=1;;i++){
            tmp+=1ll*MOD;
            if(tmp%b)return tmp/b;
        }
    }
};
Frac num[6];
Frac bit[6][20005];
inline int lb(int x){return x&-x;}
Frac query(int i,int x){
    Frac ans=0;
    for(;x;x-=lb(x)){
        ans+=bit[i][x];
    }
    return ans;
}
void update(int i,int x,Frac v){
    for(;x<=m;x+=lb(x)){
        bit[i][x]+=v;
    }
}
struct Op1{
    int k;
    int del[6];
    int p;
    bool flag;
    Op1(int p,int k){
        for(int i=1;i<=k;i++){
            del[i]=lis[i];
        }
        this->k=k;
        this->p=p;
        flag=false;
    }
    Frac c;
    void operator()(){
        this->c=num[p];
        this->c/=k;
        for(int i=1;i<=k;i++){
            num[del[i]]+=c;
        }
        num[p]=0;
    }
    void de(){
        if(flag)return;
        for(int i=1;i<=k;i++){
            num[del[i]]-=c;
        }
        num[p]=c;
        num[p]*=k;
    }
};
vector<Op1> ops;
map<int,int> mp;
inline void output(){
    for(int i=1;i<=n;i++){
        printf("%lld ",num[i].toInt());
    }
    printf("\n");
}
int main(){
    freopen("417.in","r",stdin);
    freopen("417.out","w",stdout);
    scanf("%d%d",&n,&m);
    ops.reserve(m+1);
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        num[i]=k;
    }
    while(m--){
        int op;scanf("%d",&op);
        if(op==1){
            int p,k;scanf("%d%d",&p,&k);
            for(int i=1;i<=k;i++){
                scanf("%d",lis+i);
            }
            Op1 opr(p,k);
            opr();
            ops.push_back(opr);
            output();
            if(mp.count(p)==0)mp[p]=ops.size()-1;
        }else{
            //printf("test: %lld\n",ops[2].c.toInt());
            int p;scanf("%d",&p);
            if(mp.count(p)==0){
                output();
            }else{
                int opi = mp[p];
                for(int i=ops.size()-1;i>=opi;i--){
                    ops[i].de();
                }
                ops[opi].flag=true;
                for(int i=opi+1;i<ops.size();i++){
                    ops[i]();
                }
                output();
            }
        }
    }
    return 0;
}