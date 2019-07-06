#include<stdio.h>
#include<string.h>
#include<algorithm>
struct Node{
    int p;
    int d;
};
bool cmp(Node x,Node y){
    if(x.p == y.p)return x.d > y.d;
    return x.p > y.p;
}
Node arr[10010];
bool vis[16384];
int n;
int main(){
    while(~scanf("%d",&n)){
        memset(arr,0,sizeof(arr));
        memset(vis,0,sizeof(vis));
        for(int i = 0;i<n;i++){
            scanf("%d%d",&arr[i].p,&arr[i].d);
        }
        std::sort(arr,arr+n,cmp);
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = arr[i].d;j>0;j--){
                if(!vis[j]){
                    ans += arr[i].p;
                    vis[j] = 1;
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}