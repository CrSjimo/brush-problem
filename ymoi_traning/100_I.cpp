#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::sort;
typedef long long ll;

const int n=32005;

ll f[n];

inline int lowbit(int x){return x&-x;}

void update(int x,int val){
    for(;x<=n;x+=lowbit(x)){
        f[x]+=val;
    }
}

ll query(int x){
    ll ans=0;
    for(;x>0;x-=lowbit(x)){
        ans+=f[x];
    }
    return ans;
}
struct Node{
    int x,y;
    bool operator<(const Node& a)const{
        if(y==a.y)return x<a.x;
        return y<a.y;
    }
} a[15114];
int ans[15144];
int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].x++;a[i].y++;
    }
    sort(a+1,a+1+N);
    for(int i=1;i<=N;i++){
        ans[query(a[i].x)]++;
        update(a[i].x,1);
    }
    for(int i=0;i<N;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}