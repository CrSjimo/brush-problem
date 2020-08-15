#include<cstdio>
#include<cstdlib>

struct BigInt{
    int num[114514];
    int len=0;
    BigInt& operator*=(int x){
        int i;
        int w=0;
        for(i=0;i<len;i++){
            num[i]*=x;
            num[i]+=w;
            w=num[i]/10;
            num[i]%=10;
        }
        while(w){
            num[i]+=w;
            w=num[i]/10;
            num[i]%=10;
            i++;
        }
        len=i;
        return *this;
    }

    void print(){
        for(int i=len-1;i>=0;i--){
            printf("%d",num[i]);
        }
    }

    BigInt& operator+=(const BigInt& bi){
        int i;
        int w=0;
        for(i=0;i<(len>bi.len?len:bi.len);i++){
            num[i]+=w;
            num[i]+=bi.num[i];
            w=num[i]/10;
            num[i]%=10;
        }
        while(w){
            num[i]+=w;
            w=num[i]/10;
            num[i]%=10;
            i++;
        }
        len=i;
        return *this;
    }
    BigInt& operator/=(int x){
        int w=0;
        for(int i=len-1;i>=0;i--){
            num[i]+=w*10;
            w=num[i]%x;
            num[i]/=x;
        }
        for(;!num[len-1];len--);
        return *this;
    }
};

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    BigInt bi;
    bi.num[0]=1;
    bi.len=1;
    for(int i=n*m-3+1;i<=n*m;i++){
        bi*=i;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            
        }
    }
}