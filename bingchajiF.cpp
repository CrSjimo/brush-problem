#include<stdio.h>
#include<set>
int arr[50010];
int query(int i){
    if(arr[i] == i)
        return i;
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
    int n,m;
    int cas = 0;
    while(~scanf("%d%d",&n,&m) && (n || m)){
        init(n);
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            update(a,b);
        }
        std::set<int> s;
        for(int i = 0;i<n;i++){
            s.insert(query(i));
        }
        printf("Case %d: %d\n",++cas,s.size());
    }
    return 0;
}