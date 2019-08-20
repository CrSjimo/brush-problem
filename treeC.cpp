#include<stdio.h>
#include<string.h>
#include<algorithm>
typedef long long ll;
int n;
long long ago[500010];
ll query(int x){
    ll ans = 0;
    // printf("test: %d %d\n",x,(x & (-x)));
    for(;x>0;x-=(x & (-x))){
        ans += ago[x];
    }
    return ans;
}
void update(int x,int num){
    for(;x<=n;x+=(x & (-x))){
        ago[x]+=num;
    }
}
struct Node{
    int val;
    int index;
    bool operator<(const Node& n)const{
        return val<n.val;
    }
} a[500010];
int anses[500010];
int main(){
    while(~scanf("%d",&n)&&n){
        memset(ago,0,sizeof(ago));
        memset(a,0,sizeof(a));
        memset(anses,0,sizeof(anses));
        for(int i = 1;i<=n;i++){
            scanf("%d",&a[i].val);
            a[i].index = i;
        }
        std::sort(a+1,a+n+1);
        for(int i =1;i<=n;i++){
            anses[a[i].index] = i;
        }
        ll ans = 0;
        for(int i = 1;i<=n;i++){
            update(anses[i],1);
            ans+=i-query(anses[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}