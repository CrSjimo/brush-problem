#include<cstdio>
#include<cstdlib>

typedef long long ll;

ll** f;

inline int lowbit(int x){return x&-x;}

int n,m;

void update(int x,int y,int val){
    for(int i=x;i<=n;i+=lowbit(i)){
        for(int j=y;j<=m;j+=lowbit(j)){
            f[i][j]+=val;
        }
    }
}

ll query(int x,int y){
    ll ans=0;
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            ans+=f[i][j];
        }
    }
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    f=(ll**)malloc((n+6)*sizeof(ll*));
    for(ll**p=f;p<=f+n;p++){
        *p=(ll*)calloc((m+6),sizeof(ll));
    }
    int op;
    while(~scanf("%d",&op)){
        if(op==1){
            int x,y,k;scanf("%d%d%d",&x,&y,&k);
            update(x,y,k);
        }else if(op==2){
            int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
            printf("%lld\n",query(c,d)-query(a-1,d)-query(c,b-1)+query(a-1,b-1));
        // }else if(op==114514){
        //     printf("test-query:\n");
        //     for(int i=1;i<=n;i++){
        //         for(int j=1;j<=m;j++){
        //             printf("%lld ",query(i,j));
        //         }
        //         printf("\n");
        //     }
        //     printf("test-tree:\n");
        //     for(int i=1;i<=n;i++){
        //         for(int j=1;j<=m;j++){
        //             printf("%lld ",f[i][j]);
        //         }
        //         printf("\n");
        //     }
        }
    }
    return 0;
}