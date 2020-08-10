#include<cstdio>
typedef long long ll;

struct BigInt{
    char num[200];
    void read(){
        scanf("%s",num);
        int i;
        for(i=0;num[i];i++){
            num[i]-='0';
        }
        num[i]=-1;
    }
    void write(){
        for(int i=0;~num[i];i++){
            putchar(num[i]+'0');
        }
    }
    ll operator%(ll mod){
        ll ans=0;
        for(int i=0;~num[i];i++){
            ans=(ans*10+num[i])%mod;
        }
        return ans;
    }
    bool and_1(){
        for(int i=0;~num[i];i++){
            if(~num[i+1])continue;
            return num[i]&1;
        }
    }
    bool shift_right_equal_1(){
        for(int i=0;~num[i];i++){
            if(~num[i+1]){
                num[i+1]+=(num[i]&1)*10;
            }
            num[i]>>=1;
        }
    }
    bool equal_0(){
        for(int i=0;~num[i];i++){
            if(num[i])return false;
        }
        return true;
    }
};
int MOD;
ll ksm(ll a,BigInt k){
    ll ans=1;
    for(;!k.equal_0();a=(a*a)%MOD,k.shift_right_equal_1()){
        if(k.and_1())ans=(ans*a)%MOD;
    }
    return ans;
}
int main(){
    BigInt a,k;
    a.read();k.read();scanf("%d",&MOD);
    //MOD = 19260817;
    printf("%lld\n",ksm(a%MOD,k));
    return 0;
}