#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::min;
using std::max;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
const int INF = 2147483647;
//baoli
int main(){
    freopen("young.in","r",stdin);
    freopen("young.out.diff","w",stdout);
    int l,r;scanf("%d%d",&l,&r);
    int min1=INF,max1=-INF,min2=INF,max2=-INF;
    for(int i=l;i<=r;i++){
        for(int j=i;j<=r;j++){
            int ccp=gcd(i,j),kmt=i*j/ccp;
            min1=min(min1,ccp);
            max1=max(max1,ccp);
            min2=min(min2,kmt);
            max2=max(max2,kmt);
        }
    }
    printf("%d\n%d\n%d\n%d\n",min1,max1,min2,max2);
    return 0;
}