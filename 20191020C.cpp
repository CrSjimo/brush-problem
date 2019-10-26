#include<stdio.h>
#include<vector>
#include<algorithm>
std::vector< std::vector<short> > map;
struct edge{
    int x,y;
    int w;
};
typedef edge egde;
bool cmp(egde& e1,edge& e2){
    return e1.w>e2.w;
}
std::vector<edge> elist;
int bcj[10020];
void init(int n){
    while(n--){
        bcj[n] = n;
    }
}
int query(int i){
    if(bcj[i]==i){
        return i;
    }
    return bcj[i] = query(bcj[i]);
}
void update(int i,int j){
    bcj[query(i)] = query(j);
}
void kruskal(){
    std::sort(elist.begin(),elist.end(),cmp);
    for(int i = 0;i<elist.size();i++){
        edge e = elist[i];
        if(query(e.x)!=query(e.y)){
            update(e.x,e.y);
            map[e.x][e.y] = map[e.y][e.x] = e.w;
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    map.resize(n+10);
    init(n+10);
    for(int i = 0;i<n+5;i++){
        map[i].resize(n+10);
    }
    for(int i = 0;i<m;i++){
        edge e;
        scanf("%d%d%d",&e.x,&e.y,&e.w);
        elist.push_back(e);
    }
    kruskal();
    // for(int i = 1;i<=n;i++){
    //     for(int j = 1;j<=n;j++){
    //         printf("%d ",map[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                map[i][j] = std::max(map[i][j],std::min(map[i][k],map[k][j]));
            }
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int s,t;
        scanf("%d%d",&s,&t);
        if(map[s][t]==0)map[s][t] = -1;
        printf("%d\n",map[s][t]);
    }
    return 0;
}