#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
int arr[110];
struct Edge{
    int pre1;
    int pre2;
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
bool cmp(Edge e1,Edge e2){
    return e1.dist < e2.dist;
}
int n,m;
int main(){
    while(~scanf("%d",&n) && n){
        scanf("%d",&m);
        memset(elist,0,sizeof(elist));
        init(n+10);
        int cnt = 0;
        for(int i = 0 ;i<m;i++){
            Edge e;
            scanf("%d%d%d",&e.pre1,&e.pre2,&e.dist);
            elist[cnt++] = e;
        }
        std::sort(elist,elist+cnt,cmp);
        int ans = 0;
        for(int i = 0;i<cnt;i++){
            Edge e = elist[i];
            if(query(e.pre1) != query(e.pre2)){
                update(e.pre1,e.pre2);
                ans += e.dist;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}