#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;
using std::min;
typedef long long ll;
const int MAXN=1e6+7;
char s[MAXN];
int n=0;
int a[MAXN];
ll p[MAXN];
int maxn=0;
void manacher(){
    s[0]='$';
    int mid=0,r=0;
    for(int i=1;i<=n;i++){
        a[i]=max(min(a[2*mid-i],r-i),0);
        while(s[i+a[i]]==s[i-a[i]])a[i]++;
        a[i]--;
        p[a[i]]++;
        maxn=max(maxn,a[i]);
        if(i+a[i]>r)r=i+a[i],mid=i;
    }
}
const int MOD=19930726;
ll ksm(ll a,ll b){
    ll ans = 1;
    for(;b;a=(a*a)%MOD,b>>=1){
        if(b&1)ans=(ans*a)%MOD;
    }
    return ans;
}
int main(){
    ll k;scanf("%d%lld",&n,&k);
    scanf("%s",s+1);
    manacher();
    ll cnt=0;
    ll ans=1;
    // for(int i=1;i<=maxn;i++){
    //     printf("test: %d %d\n",i,p[i]);
    // }
    for(int i=maxn;i>=0;i--){
        cnt+=p[i];
        if(k>=cnt){
            ans*=ksm(i*2+1,cnt);
            ans%=MOD;
            k-=cnt;
        }else{
            ans*=ksm(i*2+1,k);
            ans%=MOD;
            k-=cnt;
            break;
        }
        
    }
    printf("%lld\n",k>0?-1:ans);
    return 0;
}