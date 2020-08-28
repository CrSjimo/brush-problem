#include<cstdio>
#include<cstdlib>

typedef long long ll;

ll* f1;
ll* f2;

inline int lowbit(int x){return x&-x;}

int n;

void update(int x,int val){
    for(int i=x;i<=n;i+=lowbit(i)){
        f1[i]+=val;
        f2[i]+=1ll*val*x;
    }
}

ll query(int x){
    ll ans=0;
    for(int i=x;i>0;i-=lowbit(i)){
        ans+=f1[i]*(x+1)-f2[i];
    }
    return ans; 
}

int main(){
    int q;scanf("%d%d",&n,&q);
    f1=(ll*)calloc((n+1),sizeof(ll));
    f2=(ll*)calloc((n+1),sizeof(ll));
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        update(i,k);
        update(i+1,-k);
    }
    while(q--){
        int op,l,r,x;scanf("%d%d%d",&op,&l,&r);
        if(op==1){
            scanf("%d",&x);
            update(l,x);
            update(r+1,-x);
        }else if(op==2){
            printf("%lld\n",query(r)-query(l-1));
        }
    }
    return 0;
}