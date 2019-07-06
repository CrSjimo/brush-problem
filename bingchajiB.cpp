#include<stdio.h>
#include<string.h>
int arr[10010];
int n,m;
int query(int i){
    if(arr[i] == i){
        return i;
    }
    return arr[i] = query(arr[i]);
}
void update(int i,int j){
    int aliasI = query(i);
    int aliasJ = query(j);
    arr[aliasI] = aliasJ;
}
void init(int len){
    while(len--){
        arr[len] = len;
    }
}
int main(){
    while(~scanf("%d",&n) && n){
        init(1001);
        scanf("%d",&m);
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            update(a,b);
        }
        int ans = -1;
        for(int i = 1;i<=n;i++){
            if(arr[i] == i)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}