#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::swap;
using std::min;
int* a;
int tail=0;
inline void push(int k){
    a[++tail]=k;
    int ch=tail;
    int pa=ch>>1;
    while(ch>1&&a[ch]<a[pa]){
        swap(a[ch],a[pa]);
        ch=pa;
        pa=ch>>1;
    }
}
inline int top(){
    return a[1];
}
inline void pop(){
    a[1]=a[tail--];
    int pa=1;
    while(pa<<1<=tail){
        int ch=pa<<1;
        if(ch<=tail-1){
            ch=&min(a[pa<<1],a[pa<<1|1])-a;
        }
        if(a[pa]<=a[ch])return;
        swap(a[pa],a[ch]);
        pa=ch;
    }
}
int main(){
    int n;scanf("%d",&n);
    a=(int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        push(k);
    }
    int ans=0;
    for(int i=1;i<=n-1;i++){
        int a=top();pop();
        int b=top();pop();
        ans+=(a+b);
        push(a+b);
    }
    printf("%d\n",ans);
    return 0;
}
