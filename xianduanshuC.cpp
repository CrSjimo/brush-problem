#include<stdio.h>
#define four(x) for(int x = 0;x<4;x++)
const int MAXN = 1<<22;
int sumv[4][MAXN];
int opv[4][MAXN];
// int xorv[4][MAXN];
//-1:xor,0:noop,1:1,2:0
int num[MAXN];
void pushUp(int o){
    int lc = o*2,rc = o*2+1;
    four(i){
        sumv[i][o] = sumv[i][lc] + sumv[i][rc];
    }
}
void build(int o,int l,int r){
    four(i){
        opv[i][o] = sumv[i][o] = 0;
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
    if(opv[i][o]>0){
        opv[i][o] = (opv[i][o]==1)?2:1;
    }else{
        opv[i][o] = ~opv[i][o];
    }
}
void pushDown(int o,int len){
    int lc = o*2,rc = o*2+1;
    int llen = len-len/2,rlen = len/2;
    four(i){
        if(opv[i][o]>0){
            opv[i][lc] = opv[i][rc] = opv[i][o];//down op label
            opv[i][o] = 0; //remove op label
            sumv[i][lc] = llen*(2-opv[i][lc]);
            sumv[i][rc] = rlen*(2-opv[i][rc]);
        }else if(opv[i][o] == -1){
            opv[i][o] = 0;
            sumv[i][lc] = llen - sumv[i][lc];
            sumv[i][rc] = rlen - sumv[i][rc];
            doXOR(lc,i);
            doXOR(rc,i);
        }
    }
}
int ql,qr;
int query(int o,int l,int r){
    if(ql<=l&&r<=qr){
        int ans = 0;
        four(i){
            ans += sumv[i][o]*(1<<i);
        }
        return ans;
    }
    int m = (l+r)/2,len = r-l+1;
    pushDown(o,len);
    int ans = 0;
    if(ql<=m){
        ans+=query(o*2,l,m);
    }
    if(qr>m){
        ans+=query(o*2+1,m+1,r);
    }
    return ans;
}
int v;
char ops[10];
char& op = *ops;
void update(int o,int l,int r){
    int len = r-l+1;
    if(ql<=l&&r<=qr){
        four(i){
            int is1 = v&(1<<i);
            if(op == 'O' && is1){
                sumv[i][o] = len;
                opv[i][o] = 1;
            }else if(op == 'X' && is1){
                sumv[i][o] = len - sumv[i][o];
                doXOR(o,i);
            }else if(op == 'A' && !is1){
                sumv[i][o] = 0;
                opv[i][o] = 2;
            }
            
        }
    }else{
        pushDown(o,len);
        int m = (l+r)/2,lc = o*2,rc = o*2+1;
        if(ql<=m){
            update(lc,l,m);
        }
        if(qr>m){
            update(rc,m+1,r);
        }
        pushUp(o);
    }
}
int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i = 1;i<=n;i++){
            scanf("%d",num+i);
        }
        build(1,1,n);
        while(m--){
            scanf("%s",ops);
            // printf("%c\n",ops[0]);
            if(op == 'S'){
                scanf("%d%d",&ql,&qr);
                ql++;qr++;
                printf("%d\n",query(1,1,n));
            }else{
                scanf("%d%d%d",&v,&ql,&qr);
                ql++;qr++;
                update(1,1,n);
            }
        }
    }
    return 0;
}