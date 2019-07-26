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
void pushUp(ll o,ll l,ll r){
    ll lc = o*2,rc = o*2+1;
    a[o].sum = a[lc].sum + a[rc].sum;
    a[o].maxPre = a[lc].maxPre;
    a[o].maxSuf = a[rc].maxSuf;
    a[o].preR = a[lc].preR;
    a[o].sufL = a[rc].sufL;

    //lc sum + rc prefix
    a[o].maxSum = a[lc].sum + a[rc].maxPre;
    a[o].l = l;
    a[o].r = a[rc].preR;

    //lc maxsum
    if(a[o].maxSum < a[lc].maxSum || (a[o].l == a[lc].l && a[o].maxSum == a[lc].maxSum)){
        a[o].r = a[lc].r;
        a[o].l = a[lc].l;
        a[o].maxSum = a[lc].maxSum;
    }

    //lc max suffix + rc max prefix
    if(a[o].maxSum < a[lc].maxSuf + a[rc].maxPre || (a[o].l > a[lc].sufL && a[o].maxSum == a[lc].maxSuf + a[rc].maxPre)){
        a[o].r = a[rc].preR;
        a[o].l = a[lc].sufL;
        a[o].maxSum = a[lc].maxSuf + a[rc].maxPre;
    }

    //rc maxsum
    if(a[o].maxSum < a[rc].maxSum || (a[o].l > a[rc].sufL && a[o].maxSum == a[rc].maxSum)){
        a[o].l = a[rc].l;
        a[o].r = a[rc].r;
        a[o].maxSum = a[rc].maxSum;
    }

    //lc suffix + rc sum
    if(a[o].maxSum  < a[lc].maxSuf+a[rc].sum || (a[o].maxSum  == a[lc].maxSuf+a[rc].sum && a[o].l>a[lc].sufL)){
        
    }
}