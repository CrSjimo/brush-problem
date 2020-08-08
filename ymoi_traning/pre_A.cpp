#include<cstdio>
#include<cstdlib>
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    int cas;scanf("%d",&cas);
    while(cas--){
        int a,b;scanf("%d%d",&a,&b);
        int ccp = gcd(a,b);
        printf("%d %lld\n",ccp,1LL*a*b/ccp);
    }
    return 0;
}