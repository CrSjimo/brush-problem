#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 50010*3
int ql,qr;
int sumv[MAXN];
int query(int o,int l,int r){
    if(ql <= l && r <= qr){
        return sumv[o];
    }else{
        int m = l + (r - l) / 2;
        int ans = 0;
        if(ql <= m){
            ans+=query(o*2,l,m);
        }
        if(qr > m){
            ans+=query(o*2+1,m+1,r);
        }
        return ans;
    }
}
int v;
int p;
void update(int o,int l,int r){
    int m = l + (r - l) / 2;
    if(l == r){
        sumv[o] += v;
    }else{
        if(p <= m){
            update(o*2,l,m);
        }else{
            update(o*2+1,m+1,r);
        }
        sumv[o] = sumv[o*2] + sumv[o*2+1];
    }
}
int num[50010];
void build(int o,int l,int r){
    if(l == r){
        sumv[o] = num[l];
    }else{
        int m = l + (r - l) / 2;
        build(o*2,l,m);
        build(o*2+1,m+1,r);
        sumv[o] = sumv[o*2] + sumv[o*2+1];
    }
}

int main(){
    int cas;
    int t = 0;
    scanf("%d",&cas);
    while(cas--){
        int n;
        scanf("%d",&n);
        for(int i = 1;i<=n;i++){
            scanf("%d",num+i);
        }
        build(1,1,n);
        printf("Case %d:\n",++t);
        char op[10];
        while(1){
            scanf("%s",op);
            if(op[0] == 'E'){
                break;
            }else if(op[0] == 'A'){
                scanf("%d%d",&p,&v);
                update(1,1,n);
            }else if(op[0] == 'S'){
                scanf("%d%d",&p,&v);
                v = -v;
                update(1,1,n);
            }else if(op[0] == 'Q'){
                scanf("%d%d",&ql,&qr);
                if(qr < ql){
                    std::swap(ql,qr);
                }
                printf("%d\n",query(1,1,n));
            }
        }
    }
    return 0;
}