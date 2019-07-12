#include<stdio.h>
#define four(x) for(int x = 0;x<4;x++)
const int MAXN = 1<<22;
int sumv[4][MAXN];
int opv[4][MAXN];
int xorv[4][MAXN];
int num[MAXN];
void pushUp(int o){
    int lc = o*2,rc = o*2+1;
    four(i){
        sumv[i][o] = sumv[i][lc] + sumv[i][rc];
    }
}
void build(int o,int l,int r){
    four(i){
        opv[i][o] = ~(xorv[i][o] = sumv[i][o] = 0);
    }
    if(l == r){
        four(i){
            if(num[l] & (1<<i)){
                sumv[i][o] = 1;
            }
        }
        return;
    }
    int m = (l+r)/2,lc = o*2,rc = o*2+1;
    build(lc,l,m);
    build(rc,m+1,r);
    pushUp(o);
}
void doXOR(int o,int i){
    if(~opv[i][o])opv[i][o]^=1;
    else xorv[i][o] ^=1;
}
void pushDown(int o,int len){
    int lc = o*2,rc = o*2+1;
    int llen = len-len/2,rlen = len/2;
    four(i){
        if(~opv[i][o]){
            opv[i][lc] = opv[i][rc] = opv[i][o];//down op label
            opv[i][o] = -1; //remove op label
            sumv[i][lc] = llen*opv[i][lc];
            sumv[i][rc] = rlen*opv[i][rc];
            xorv[i][lc] = xorv[i][rc] = 0;//remove xor label
        }
        if(xorv[i][o]){
            sumv[i][lc] = llen*opv[i][lc];
            sumv[i][rc] = rlen*opv[i][rc];
            doXOR(lc,i);
            doXOR(rc,i);
        }
    }
}
int main(){
    
    return 0;
}