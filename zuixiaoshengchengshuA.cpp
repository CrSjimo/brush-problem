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
Edge elist[500];
bool cmp(Edge e1,Edge e2){
    return e1.dist < e2.dist;
}
int n;
int main(){
    while(~scanf("%d",&n) && n){
        memset(elist,0,sizeof(elist));
        init(n+10);
        int cnt = 0;
        for(int i = 0;i<n-1;i++){
            char c[5];
            int k;
            scanf("%s%d",c,&k);
            // printf("test: %c %d\n",c[0],k);
            for(int j = 0;j<k;j++){
                // printf("%d\n",j);
                char cc[5];
                Edge e;
                e.pre1 = c[0]-'A';
                scanf("%s%d",cc,&e.dist);
                // printf("test1: %s %d\n",cc,e.dist);
                e.pre2 = cc[0]-'A';
                elist[cnt++] = e;
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