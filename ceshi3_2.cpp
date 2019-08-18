#include<stdio.h>
#include<algorithm>
long long a[110];
long long w[110];
long long n;
long long m;
long long delta = 0;
long long tot = 0;
bool cando(long long x){
    long long totl = 0;
    for(int i = 0;i<n;i++){
        if(x>a[i])totl+=(x-a[i])*w[i];
    }
    return totl<=m;
}
long long find(long long l,long long r){
    if(l == r)return l-1;
    long long m = (l+r)/2;
    if(cando(m)){
        return find(m+1,r);
    }else{
        return find(l,m);
    }
}
int main(){
    long long ans = 0;
    scanf("%lld%lld",&n,&m);
    for(int i = 0;i<n;i++){
        scanf("%lld",a+i);
    }
    for(int i = 0;i<n;i++){
        scanf("%lld",w+i);
    }
    long long minn = *std::min_element(a,a+n);
    for(int i = 0;i<n;i++){
        a[i]-=minn;
        delta+=a[i]*w[i];
        tot+=w[i];
    }
    ans+=minn;
    ans+=find(0,1e10);
    printf("%lld\n",ans);
    return 0;
}