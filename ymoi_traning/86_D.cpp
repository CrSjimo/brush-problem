#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;
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
};
// struct BigInt{
//   int f[114514],len;
//   inline void clear(){memset(f,0,sizeof(f));len=0;}
//   inline void give(int x){f[len=1]=x;}
//   BigInt operator*(int x){
//       BigInt bi;
//       bi.clear();
//       bi.give(x);
//       return this->operator*(bi);
//   }
//   BigInt operator *(const BigInt &g)const{
//     BigInt h;h.clear();h.len=len+g.len+10;
//     for(int i=1;i<=len;++i)
//       for(int j=1;j<=g.len;++j){
//         h.f[i+j-1]+=f[i]*g.f[j];
//         h.f[i+j]+=h.f[i+j-1]/10;
//         h.f[i+j-1]%=10;
//       }
//     for(int i=1;i<=h.len;++i)
//       h.f[i+1]+=h.f[i]/10,h.f[i]%=10;
//     while(h.len && !h.f[h.len])h.len--;
//     return h;
//   }
//   BigInt operator +(const BigInt &g)const{
//     BigInt h;h.clear();h.len=max(len,g.len)+10;
//     for(int i=1;i<=h.len;++i){
//       h.f[i]+=f[i]+g.f[i];
//       h.f[i+1]+=h.f[i]/10;
//       h.f[i]%=10;
//     }
//     for(int i=1;i<=h.len;++i)
//       h.f[i+1]+=h.f[i]/10,h.f[i]%=10;
//     while(h.len && !h.f[h.len])h.len--;
//     return h;
//   }
//   inline void print(){
//     printf("%d",f[len]);
//     for(int i=len-1;i>=1;--i)
//       printf("%d",f[i]);
//   }
// };

inline void mul_A(BigInt& bi,int n,int m){
    for(int i=n-m+1;i<=n;i++){
        bi*=i;
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    BigInt bi;
    bi.num[0]=2;
    bi.len=1;
    mul_A(bi,n+1,n+1);
    mul_A(bi,n+2,m-1);
    BigInt bii;
    bii.num[0]=1;
    bii.len=1;
    mul_A(bii,n,n);
    mul_A(bii,n+1,2);
    mul_A(bii,n+3,m);
    bi+=bii;
    bi.print();putchar('\n');
    return 0;
}