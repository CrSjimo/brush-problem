#include<cstdio>
#include<cstdlib>
int n;
int sqrtn;
#include<cmath>
typedef long long ll;
ll* tag1;
ll* tag2;
ll* s;
ll* a;
const int MOD=10007;
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
            tag1[i]+=c;
            s[i]+=c*sqrtn;
        }
    }
}
ll query(int r){
    return a[r]*tag2[h(r)]+tag1[h(r)];
}
int main(){
    scanf("%d",&n);sqrtn=ceil(sqrt(n));
    a=(ll*)malloc((n+1)*sizeof(ll));
    s=(ll*)calloc(sqrtn+1,sizeof(ll));
    tag1=(ll*)calloc(sqrtn+1,sizeof(ll));
    tag2=(ll*)calloc(sqrtn+1,sizeof(ll));
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
            
        }else if(op==2){
            printf("%lld\n",query(l,r,c+1));
        }
    }
    return 0;
}