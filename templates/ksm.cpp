#include<stdio.h>
long long b,p,MOD;
long long ksm(long long a,long long k){
	a%=MOD;
	long long ans=1;
	for(;k;k>>=1){
		if(k&1)ans=ans*a%MOD;
        a=a*a%MOD;
    }
    return ans%MOD;
}
int main(){
	scanf("%lld%lld%lld",&b,&p,&MOD);
	printf("%lld\n",ksm(b,p));
	return 0;
}
