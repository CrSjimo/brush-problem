#include<cstdio>
#include<cstdlib>
int n;
int sqrtn;
#include<cmath>
typedef long long ll;
ll* tag;
ll* s;
ll* a;
inline int h(int i){
    return (i-1)/sqrtn+1;
}
void update(int l,int r,ll c){
    int hl=h(l),hr=h(r);
    if(hl==hr){
        for(int i=l;i<=r;i++){
            a[i]+=c;
            s[hl]+=c;
        }
    }else{
        for(int i=l;h(i)==hl;i++){
            a[i]+=c;
            s[hl]+=c;
        }
        for(int i=r;h(i)==hr;i--){
            a[i]+=c;
            s[hr]+=c;
        }
        for(int i=hl+1;i<=hr-1;i++){
            tag[i]+=c;
            s[i]+=c*sqrtn;
        }
    }
}
ll query(int l,int r,int MOD){
    int hl=h(l),hr=h(r);
    ll ans=0;
    if(hl==hr){
        for(int i=l;i<=r;i++){
            ans+=(a[i]%MOD+tag[hl]%MOD)%MOD;
            ans%=MOD;
        }
    }else{
        for(int i=l;h(i)==hl;i++){
            ans+=(a[i]%MOD+tag[hl]%MOD)%MOD;
            ans%=MOD;
        }
        for(int i=r;h(i)==hr;i--){
            ans+=(a[i]%MOD+tag[hr]%MOD)%MOD;
            ans%=MOD;
        }
        for(int i=hl+1;i<=hr-1;i++){
            ans+=(s[i]%MOD);
            ans%=MOD;
        }
    }
    return ans;
}
int main(){
    scanf("%d",&n);sqrtn=ceil(sqrt(n));
    a=(ll*)malloc((n+1)*sizeof(ll));
    s=(ll*)calloc(sqrtn+1,sizeof(ll));
    tag=(ll*)calloc(sqrtn+1,sizeof(ll));
    // printf("==test==: %d\n",sqrtn);
    // for(int i=1;i<=n;i++){
    //     printf("test: %d %d\n",i,h(i));
    // }
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        s[h(i)]+=a[i];
    }
    for(int i=1;i<=n;i++){
        int op,l,r,c;scanf("%d%d%d%d",&op,&l,&r,&c);
        if(op==0){
            update(l,r,c);
        }else if(op==1){
            printf("%lld\n",query(l,r,c+1));
        }
    }
    return 0;
}