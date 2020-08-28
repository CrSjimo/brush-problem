#include<cstdio>
#include<cstdlib>
#include<utility>
using std::swap;

#define lc (x<<1)
#define rc (x<<1|1)
#define pnt (x>>1)

int f[1000005];
int n;

int top(){
    return f[1];
}

void push_down(){
    int x=1;
    while(lc<=n){
        int t=lc;
        if(rc<=n && f[rc]<f[t]){
            t=rc;
        }
        if(f[t]>f[x])return;
        swap(f[t],f[x]);
        x=t;
    }
}

void pop(){
    swap(f[1],f[n--]);
    push_down();
}

void push_up(int x){
    while(x>1 && f[x]<f[pnt]){
        swap(f[x],f[pnt]);
        x=pnt;
    }
}

void push(int a){
    f[++n]=a;
    push_up(n);
}
#undef lc
#undef rc
#undef pnt
int main(){
    int q;scanf("%d",&q);
    while(q--){
        int op;scanf("%d",&op);
        if(op==1){
            int x;scanf("%d",&x);
            push(x);
        }else if(op==2){
            printf("%d\n",top());
        }else if(op==3){
            pop();
        }
    }
    return 0;
}