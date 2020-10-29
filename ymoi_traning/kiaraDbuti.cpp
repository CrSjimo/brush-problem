#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::unique;
using std::lower_bound;
typedef long long ll;
ll* a;
ll* b;
ll* c;
ll* f;
using std::sort;
int n1;
inline int lb(int x){return x&-x;}
inline int query(int x){
    int ans=0;
    for(;x;x-=lb(x)){
        ans+=f[x];
    }
    return ans;
}
inline void update(int x,int v){
    for(;x<=n1;x+=lb(x)){
        f[x]+=v;
    }
}
int main(){
    freopen("running.in","r",stdin);
    freopen("running.out","w",stdout);
    int n,k;scanf("%d%d",&n,&k);
    a=(ll*)malloc((n+1)*sizeof(ll));
    b=(ll*)malloc((n+1)*sizeof(ll));
    c=(ll*)malloc((n+1)*sizeof(ll));
    f=(ll*)calloc((n+1),sizeof(ll));
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        b[i]=a[i]/k;
        c[i]=a[i]=a[i]%k;
    }
    ll ans=0;
    for(int i=1,j=-n+1;i<=n;i++,j+=2){
        ans+=b[i]*j;
    }
    sort(a+1,a+1+n);
    n1=unique(a+1,a+1+n)-a-1;
    for(int i=1;i<=n;i++){
        c[i]=lower_bound(a+1,a+n1+1,c[i])-a;
    }
    for(int i=n;i>=1;i--){
        update(c[i],1);
        ans-=query(c[i]-1);
    }
    printf("%lld\n",ans);
    return 0;
}