#include<cstdio>
#include<cstdlib>

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
int ans[15144];
int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;i++){
        int x,y;scanf("%d%d",&x,&y);
        x++;y++;
        ans[query(x)]++;
        update(x,1);
    }
    for(int i=0;i<N;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}