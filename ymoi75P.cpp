#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
bool f[15][15];
int a[15];
void trsclsr(){
    for(int k=0;k<=9;k++){
        f[k][k]|=1;
        for(int i=0;i<=9;i++)
            for(int j=0;j<=9;j++)
                f[i][j]|=(f[i][k]&f[k][j]);
    }
}
const size_t N=40;
struct BigInt{
    char* digits;
    BigInt(){
        this->digits=new char[N];
    }
    BigInt(int k){
        this->digits=new char[N];
        this->digits[0]=k;
    }
    BigInt& operator*=(int k){
        int carry=0;
        for(int i=0;i<N;i++){
            digits[i]*=k;
            digits[i]+=carry;
            carry=digits[i]/10;
            digits[i]%=10;
        }
    }
    const char* c_str(){
        int len=N;
        while(digits[len-1]==0)len--;
        char* s=new char[len];
        for(int i=len-1;i>=0;i--){
            s[len-i-1]=digits[i]+'0';
        }
        return s;
    }
};
int main(){
    int m;char* s=new char[35];
    scanf("%s%d",s,&m);
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        f[u][v]|=1;
    }
    trsclsr();
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            a[i]+=f[i][j];
        }
    }
    BigInt ans=1;
    for(char*c=s;*c;c++){
        int d = *c-'0';
        ans*=a[d];
    }
    printf("%s\n",ans.c_str());
    return 0;
}