#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
using std::sort;
using std::unique;
using std::lower_bound;
template<typename T> T*& alloc(T*&a,size_t siz){
    return a=(T*)calloc(siz,sizeof(T));
}
namespace d12n{
    int *a;
    int n=0;
    void init(int _n){
        alloc(a,_n);
    }
    void insert(int i){
        a[n++]=i;
    }
    void d12n_sort(){
        sort(a,a+n);
        n=unique(a,a+n)-a;
        // for(int i=0;i<n;i++){
        //     printf("%d ",a[i]);
        // }
        // printf("\n");
    }
    int h(int i){
        return lower_bound(a,a+n,i)-a+1;
    }
    int g(int i){
        return a[i-1];
    }
}
using d12n::h;
using d12n::g;
struct Query{
    int op;
    int x;
}* qli;
namespace bit{
    int* a;
    int n;
    int _log2n;
    void init(int _n){
        _log2n = (int)ceil(log2(_n));
        alloc(a,_n);
        n=_n;
    }
    inline int lowbit(int x){return x&-x;}
    void update(int i,int x){
        i=h(i);
        for(;i<=n;i+=lowbit(i)){
            a[i]+=x;
        }
    }
    int exist(int i){
        i=h(i);int j=i-1;
        int ans1=0;
        for(;i;i-=lowbit(i)){
            ans1+=a[i];
        }
        int ans2=0;
        for(;j;j-=lowbit(j)){
            ans2+=a[j];
        }
        return ans1-ans2;
    }
    int query(int i){
        i=h(i);
        int ans=0;
        for(;i;i-=lowbit(i)){
            ans+=a[i];
        }
        return ans;
    }
    int rnk(int i){
        i=h(i);int j=i-1;
        int ans2=0;
        for(;j;j-=lowbit(j)){
            ans2+=a[j];
        }
        return ans2+1;
    }
    int kth(int k){
        int r=0;int t;
        for(int i=_log2n;i>=0;i--){
            t=r|1<<i;
            if(t>n)continue;
            int qt=a[t];
            if(qt<k){
                k-=qt;
                r=t;
            }
        }
        return g(r+1);
    }
    int upper_bound(int x){
        return kth(query(x)+1);
    }
    int lower_bound(int x){
        if(!exist(x))return kth(query(x)+1);
        return kth(query(x));
    }
    int less_upper_bound(int x){
        if(!exist(x))return kth(query(x));
        return kth(rnk(x)-1);
    }
}
int main(){
    // freopen("bst.ans","w",stdout);
    int n;scanf("%d",&n);
    bit::init(n+5);
    d12n::init(n+1);
    alloc(qli,n+1);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&qli[i].op,&qli[i].x);
        if(qli[i].op==1)d12n::insert(qli[i].x);
    }
    d12n::d12n_sort();
    for(int i=1;i<=n;i++){
        int op=qli[i].op,x=qli[i].x;
        switch(op){
            case 1:
                bit::update(x,1);
                break;
            case 2:
                bit::update(x,-1);
                break;
            case 3:
                printf("%d\n",bit::rnk(x));
                break;
            case 4:
                printf("%d\n",bit::kth(x));
                break;
            case 5:
                // printf("test: %d %d %d\n",x,h(x),g(h(x)));
                printf("%d\n",bit::less_upper_bound(x));
                break;
            case 6:
                // printf("test: %d %d %d\n",x,h(x),g(h(x)));
                printf("%d\n",g(h(x))==x?bit::upper_bound(x):bit::lower_bound(x));
                break;
        }
    }
    return 0;
}
