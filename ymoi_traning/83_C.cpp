#include<cstdio>
#include<cstdlib>
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    int a0, a1, b0, b1, cas;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
        int ak=a0/a1, bk=b1/b0;
        int ans=0;
        for(int x=1;x*x<=b1;x++){
            if(b1%x)continue;
            ans+=(x%a1==0 && gcd(ak,x/a1)==1 && gcd(bk,b1/x)==1);
            int xx=b1/x;
            ans+=(x!=xx && xx%a1==0 && gcd(ak,xx/a1)==1 && gcd(bk,b1/xx)==1);
        }
        printf("%d\n",ans);
    }
    return 0;
}