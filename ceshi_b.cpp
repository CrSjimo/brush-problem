#include<stdio.h>
#include<string.h>
#include<algorithm>
int arr[110];
struct Edge{
    int x;
    int y;
    int dist;
};
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
Edge elist[5500];
int n,m,cnt;
bool cmp(Edge e1,Edge e2){
    return e1.dist < e2.dist;
}
int calc(){
    std::sort(elist,elist+cnt,cmp);
    int ans = 0;
    for(int i = 0;i<cnt;i++){
        Edge e = elist[i];
        if(query(e.x) != query(e.y)){
            update(e.x,e.y);
            ans += e.dist;
        }
    }
    return ans;
}
//咱重新寫一邊試試
int main(){
    while(~scanf("%d",&n) && n){
        memset(elist,0,sizeof(elist));
        init(105);
        cnt = 0;
        for(int i = 0 ;i<n*(n-1)/2;i++){
            Edge e;
            scanf("%d%d%d",&e.x,&e.y,&e.dist);
            elist[cnt++] = e;
        }
        printf("%d\n",calc());
    }
    return 0;
}