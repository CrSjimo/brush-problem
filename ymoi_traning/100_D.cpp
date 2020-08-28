#include<cstdio>
#include<cstdlib>

typedef long long ll;

ll* f;

inline int lowbit(int x){return x&-x;}

int n;

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

int main(){
    int q;scanf("%d%d",&n,&q);
    f=(ll*)calloc((n+1),sizeof(ll));
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        update(i,k);
    }
    while(q--){
        int op,i,x;scanf("%d%d%d",&op,&i,&x);
        if(op==1){
            update(i,x);
        }else if(op==2){
            printf("%lld\n",query(x)-query(i-1));
        }
    }
    return 0;
}