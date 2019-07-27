#include<stdio.h>
#define MAXN  500010
typedef long long ll;
long long ago, there_were [MAXN] /*dishes*/ ;
ll* num = there_were;
struct Node{
    ll l,r;
    ll preR;//max prefix r
    ll sufL;//max suffix l
    ll maxSum;//max lianxu sum
    ll maxPre,maxSuf;
    ll sum;
};
Node a[MAXN<<2];
/*
TODO 5 
l maxSum
r maxSum
l suffix + r sum
l sum + r prefix
l suffix + r prefix
 */
void pushUp(ll o,ll l,ll r){
    ll lc = o*2,rc = o*2+1;
    a[o].sum = a[lc].sum + a[rc].sum;
    a[o].maxPre = a[lc].maxPre;
    a[o].maxSuf = a[rc].maxSuf;
    a[o].preR = a[lc].preR;
    a[o].sufL = a[rc].sufL;

    //0. lc sum + rc prefix
    a[o].maxSum = a[lc].sum + a[rc].maxPre;
    a[o].l = l;
    a[o].r = a[rc].preR;

    //1. lc maxsum
    if(a[o].maxSum < a[lc].maxSum || /*set r pos */(a[o].l == a[lc].l && a[o].maxSum == a[lc].maxSum)){
        a[o].r = a[lc].r;
        a[o].l = a[lc].l;
        a[o].maxSum = a[lc].maxSum;
    }

    //2. lc max suffix + rc max prefix
    if(a[o].maxSum < a[lc].maxSuf + a[rc].maxPre || (a[o].l > a[lc].sufL && a[o].maxSum == a[lc].maxSuf + a[rc].maxPre)){
        a[o].r = a[rc].preR;
        a[o].l = a[lc].sufL;
        a[o].maxSum = a[lc].maxSuf + a[rc].maxPre;
    }

    //3. rc maxsum
    if(a[o].maxSum < a[rc].maxSum || (a[o].l > a[rc].sufL && a[o].maxSum == a[rc].maxSum)){
        a[o].l = a[rc].l;
        a[o].r = a[rc].r;
        a[o].maxSum = a[rc].maxSum;
    }

    //4. lc suffix + rc sum
    if(a[o].maxSum  < a[lc].maxSuf+a[rc].sum || (a[o].maxSum  == a[lc].maxSuf+a[rc].sum && a[o].l>a[lc].sufL)){
        a[o].l = a[lc].sufL;
        a[o].r = r;
        a[o].maxSum = a[lc].maxSuf + a[rc].sum;
    }

    //update suffix & prefix pos and value
    if(a[lc].maxSuf + a[rc].sum > a[o].maxSuf){
        a[o].maxSuf = a[lc].maxSuf + a[rc].sum;
        a[o].sufL = a[lc].sufL;
    }
    if(a[lc].sum + a[rc].maxPre > a[o].maxPre){
        a[o].maxPre = a[lc].sum + a[rc].maxPre;
        a[o].preR = a[rc].preR;
    }

}
void build(ll o,ll l,ll r){
    if(l == r){
        a[o].maxPre = a[o].maxSuf = a[o].maxSum = a[o].sum = num[l];
        a[o].l = a[o].r = a[o].preR = a[o].sufL = l;
        return;
    }
    ll lc = o*2,rc = o*2+1,m = (l+r)/2;
    build(lc,l,m);
    build(rc,m+1,r);
    pushUp(o,l,r);
}
ll qr,ql;
Node query(int o,int l,int r){
    /*
    TODO 5 
    l maxSum
    r maxSum
    l suffix + r sum
    l sum + r prefix
    l suffix + r prefix
    */
   if(ql <= l && qr >= r){
       return a[o];
   }
   ll m = (l+r)/2,lc = o*2,rc = o*2+1;
   if(qr <= m) return query(lc,l,m);
   if(ql > m) return query(rc,m+1,r);
   Node nL = query(lc,l,m),nR = query(rc,m+1,r);
   Node tmp;
   tmp.sum = nL.sum + nR.sum;
   tmp.maxPre = nL.maxPre;
   tmp.maxSuf = nR.maxSuf;
   tmp.preR = nL.preR;
   tmp.sufL = nR.sufL;

   //0. lc sum + rc prefix
    tmp.maxSum = nL.sum + nR.maxPre;
    tmp.l = l;
    tmp.r = nR.preR;

    if(tmp.maxSum < nL.maxSum || (tmp.l == nL.l && tmp.maxSum == nL.maxSum)){
        tmp.r = nL.r;
        tmp.l = nL.l;
        tmp.maxSum = nL.maxSum;
    }

    //2. lc max suffix + rc max prefix
    if(tmp.maxSum < nL.maxSuf + nR.maxPre || (tmp.l > nL.sufL && tmp.maxSum == nL.maxSuf + nR.maxPre)){
        tmp.r = nR.preR;
        tmp.l = nL.sufL;
        tmp.maxSum = nL.maxSuf + nR.maxPre;
    }

    //3. rc maxsum
    if(tmp.maxSum < nR.maxSum || (tmp.l > nR.sufL && tmp.maxSum == nR.maxSum)){
        tmp.l = nR.l;
        tmp.r = nR.r;
        tmp.maxSum = nR.maxSum;
    }

    //4. lc suffix + rc sum
    if(tmp.maxSum  < nL.maxSuf+nR.sum || (tmp.maxSum  == nL.maxSuf+nR.sum && tmp.l>nL.sufL)){
        tmp.l = nL.sufL;
        tmp.r = r;
        tmp.maxSum = nL.maxSuf + nR.sum;
    }

    //update suffix & prefix pos and value
    if(nL.maxSuf + nR.sum > tmp.maxSuf){
        tmp.maxSuf = nL.maxSuf + nR.sum;
        tmp.sufL = nL.sufL;
    }
    if(nL.sum + nR.maxPre > tmp.maxPre){
        tmp.maxPre = nL.sum + nR.maxPre;
        tmp.preR = nR.preR;
    }
    return tmp;
}
int main(){
    ll n,m,cas = 0;
    while(~scanf("%lld%lld",&n,&m)){
        printf("Case %lld:\n",++cas);
        for(int i = 1;i<=n;i++){
            scanf("%lld",num+i);
        }
        build(1,1,n);
        while(m--){
            scanf("%lld%lld",&ql,&qr);
            Node tmp = query(1,1,n);
            //printf("test:%lld %lld %lld %lld\n",tmp.maxSum,tmp.maxPre,tmp.maxSuf,tmp.sum);
            printf("%lld %lld\n",tmp.l,tmp.r);
        }
    }
    return 0;
}