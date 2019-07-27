#include<stdio.h>
#include<algorithm>
typedef long long ll;
#define MAXN 500100
long long ago, there_were [500100] /*dishes*/ ;
typedef ll Val;
typedef ll Pos;
typedef ll Id;
struct Node{
    Val maxSum;//最大連續和
    Val maxPre;//最大前綴和
    Val maxSuf;//最大後綴和
    Val sum;//總和
    Pos l;
    Pos r;
    Pos maxPreR;
    Pos maxSufL;
} a[MAXN<<2];
Val num[MAXN];
void doChange(
    Node& o,Val target,
    Pos tL, Pos tR
){
    if(o.maxSum < target){
        o.maxSum = target;
        o.l = tL;
        o.r = tR;
    }else if(o.maxSum == target){
        if(o.l > tL){
            o.l = tL;
            o.r = tR;
        }else if(o.l == tL){
            if(o.r > tR){
                o.r = tR;
            }
        }
    }
}
void update_prefix_and_suffix(Node& o,Node lc,Node rc){
    if(o.maxPre<lc.sum+rc.maxPre){
        o.maxPre = lc.sum+rc.maxPre;
        o.maxPreR = rc.maxPreR;
    }
    if(o.maxSuf<rc.sum+lc.maxSuf){
        o.maxSuf = rc.sum+lc.maxSuf;
        o.maxSufL = lc.maxSufL;
    }
}
void abstractPushUp(Node& o,Node lc,Node rc,Pos l,Pos r){
    Pos m = (l+r)/2;
    o.sum = lc.sum + rc.sum;
    //init prefix and suffix
    o.maxPre = lc.maxPre;
    o.maxPreR = lc.maxPreR;
    o.maxSuf = rc.maxSuf;
    o.maxSufL = rc.maxSufL;

    /*
    left first if multiple cases
    if value equals, who more left select who
    if left eqals,who more less right select who
    1. lc sum + rc prefix
    2. lc maxSum
    3. lc prefix + rc suffix
    4. lc suffix + rc sum
    5. rc maxSum
     */

    //case1:
    o.maxSum = lc.sum + rc.maxPre;
    o.l = l;
    o.r = rc.maxPreR;

    //case2:
    doChange(o,lc.maxSum,lc.l,lc.r);

    //case3:
    doChange(o,lc.maxSuf+rc.maxPre,lc.maxSufL,rc.maxPreR);

    //case4:
    doChange(o,lc.maxSuf+rc.sum,lc.maxSufL,r);

    //case5:
    doChange(o,rc.maxSum,rc.l,rc.r);

    //update prefix and suffix
    update_prefix_and_suffix(o,lc,rc);
}
void pushUp(Id o,Pos l,Pos r){
    abstractPushUp(a[o],a[o*2],a[o*2+1],l,r);
}
void build(Id o,Pos l,Pos r){
    if(l == r){
        a[o].sum = a[o].maxSum = a[o].maxPre = a[o].maxSuf = num[l];
        a[o].l = a[o].r = a[o].maxSufL = a[o].maxPreR = l;
        return;
    }
    Pos m = (l+r)/2;
    build(o*2,l,m);
    build(o*2+1,m+1,r);
    pushUp(o,l,r);
}
Pos ql,qr;
Node query(Id o,Pos l,Pos r){
    if(ql <= l && qr >= r){
        return a[o];
    }
    Pos m = (l+r)/2;
    if(qr <= m){
        return query(o*2,l,m);
    }
    if(ql > m){
        return query(o*2+1,m+1,r);
    }
    Node tmp;
    abstractPushUp(
        tmp,
        query(o*2,l,m),
        query(o*2+1,m+1,r),
        l,r
    );
    return tmp;
}
int main(){
    Pos n;
    int m;
    while(~scanf("%lld%d",&n,&m)){
        for(Pos i = 1;i<=n;i++){
            scanf("%lld",num+i);
        }
        build(1,1,n);
        while(m--){
            scanf("%lld%lld",&ql,&qr);
            Node tmp = query(1,1,n);
            printf("%lld %lld\n",tmp.l,tmp.r);
        }
    }
    return 0;
}