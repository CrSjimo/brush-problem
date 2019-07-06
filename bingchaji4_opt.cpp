#include<stdio.h>
#include<string.h>
#include<algorithm>
int da[10010];
struct Node{
    int p,d;
};
bool cmp(Node x,Node y){
    if(x.p == y.p)return x.d > y.d;
    return x.p > y.p;
}
int query(int i){
    if(da[i] == i){
        return i;
    }
    return da[i] = query(da[i]);
}
void init(int len){
    while(len--){
        da[len] = len;
    }
}
int n;
Node arr[10010];
int main(){
    while(~scanf("%d",&n)){
        for(int i = 0;i<n;i++){
            scanf("%d%d",&arr[i].p,&arr[i].d);
        }
        init(10010);
        int ans = 0;
        std::sort(arr,arr+n,cmp);
        for(int i = 0;i<n;i++){
            int j = query(arr[i].d);
            if(j > 0){
                ans += arr[i].p;
                da[j] = j-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}