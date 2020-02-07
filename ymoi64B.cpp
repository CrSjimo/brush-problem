#include<cstdio>
#include<cstdlib>
typedef long long ll;
typedef ll* lp;
int main(){
    int a,n;
    while(~scanf("%d%d",&a,&n)){
        lp q = (lp)malloc((n+10)*sizeof(ll));
        size_t ptr = 1,p2 = 0,p3 = 0;
        q[0] = a;
        while(ptr<n){
            ll k2 = q[p2]*2+1,k3 = q[p3]*3+1;
            ll k;
            if(k2<k3){
                k = k2;
                p2++;
            }else{
                k = k3;
                p3++;
            }
            if(k == q[ptr-1])continue;
            q[ptr++] = k;
            int t;
        }
        printf("%lld\n",q[n-1]);
    }
}