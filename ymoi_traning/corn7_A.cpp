#include<cstdio>
#include<cstdlib>

typedef long long ll;

ll exgcd(ll a,ll b,ll& x,ll& y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    ll _x,_y;
    ll ccp=exgcd(b,a%b,_x,_y);
    x=_y,y=_x-(a/b)*_y;
    return ccp;
}
bool check(int x,int y){
    return !((x<0&&y>0)||(x>0&&y<0));
}
int main(){
    int cas;scanf("%d",&cas);
    while(cas--){
        ll a,b,n;scanf("%lld%lld%lld",&a,&b,&n);
        ll x,y;
        int ccp=exgcd(a,b,x,y);
        x*=(n/ccp),y*=(n/ccp);
        // printf("test: %lld %lld\n",x,y);
        if((n%ccp)){
            printf("-1\n");
            continue;
        }
        if(a==0){
            printf("0 %lld %lld 0\n",n/b,n/b);
            continue;
        }else if(b==0){
            printf("%lld 0 0 %lld\n",n/a,n/a);
        }else{
            ll t1=b/ccp;
            ll xm=(x%t1+t1)%t1;
            ll y_xm=(n-xm*a)/b;
            if(!check(xm,y_xm)){
                printf("-1\n");
                continue;
            }
            printf("%lld %lld ",xm,y_xm);
            ll t2=a/ccp;
            ll ym=(y%t2+t2)%t2;
            ll x_ym=(n-ym*b)/a;
            printf("%lld %lld\n",ym,x_ym);
        }
    }
    return 0;
}