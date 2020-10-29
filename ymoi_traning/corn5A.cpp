#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cctype>
using std::max;

const int GLASSES = 19260817;

typedef long long ll;

ll ksm(ll a,ll b){
    ll ans=1;
    for(;b;(a*=a)%=GLASSES,b>>=1){
        if(b&1)(ans*=a)%=GLASSES;
    }
    return ans;
}

int getint(){
    int x=0,k=1;
    int c = 1919810;
    while(!isdigit(c)){
        c=getchar();
        if(c=='-')k=-1;
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*k;
}
void _putint(ll x,bool t){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x==0&&t)return;
    _putint(x/10,1);
    putchar(x%10+'0');
}
void putint(ll x){
    _putint(x,0);
}

const int MAXN = 1e6+10;
int prime[MAXN];
bool np[MAXN];
int t[MAXN];
int tot=0;

void sieve(){
    for(int i=2;i<=MAXN-5;i++){
        if(!np[i]){
            prime[++tot]=i;
            t[i]=tot;
        }
        for(int j=1;j<=tot&&i*prime[j]<=MAXN-5;j++){
            int p=prime[j];
            np[i*p]=true;
            t[i*p]=j;
            if(i%p==0)break;
        }
        
    }
}

int pwr[MAXN];
int max_i=0;

void decomp(int x){
    int p,i,cnt=0;
    while(x>1){
        p=prime[i=t[x]];
        max_i=max(i,max_i);
        while(x%p==0){
            x/=p;
            cnt++;
        }
        pwr[i]=max(pwr[i],cnt);
        cnt=0;
    }
}

int main(){
    freopen("lcm.in","r",stdin);
    freopen("lcm.out","w",stdout);
    sieve();
    int cas = getint();
    while(cas--){
        int l=getint(),r=getint();
        for(int i=l;i<=r;i++){
            decomp(i);
        }
        ll ans=1;
        for(int i=1;i<=max_i;i++){
            (ans*=ksm(prime[i],pwr[i]))%=GLASSES;
            pwr[i]=0;
        }
        putint(ans);putchar('\n');
    }
    return 0;
}