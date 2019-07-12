#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
int arr[1010];
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
Edge elist[500000];
bool cmp(Edge e1,Edge e2){
    return e1.dist < e2.dist;
}
int n;
int cas;
int adapter[1010];
int main(){
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
        memset(elist,0,sizeof(elist));
        init(n+10);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            scanf("%d",adapter+i);
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                int tmp;
                scanf("%d",&tmp);
                if(i!=j){
                    Edge e;
                    e.pre1 = i;
                    e.pre2 = j;
                    e.dist = tmp + adapter[i] + adapter[j];
                    elist[cnt++] = e;
                }
            }
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