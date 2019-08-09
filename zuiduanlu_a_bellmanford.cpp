#include<stdio.h>
#include<string.h>
#define MAXN 1010
struct Edge{
    int u,v;
    int dist;
    void set(int u,int v,int dist){
        this->u = u;
        this->v = v;
        // this->rate = rate;
        this->dist = dist;
    }
} elist[MAXN];
int dis[MAXN];
int n,m;
void f(){
    bool isOK = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(dis[elist[j].v]>dis[elist[j].u]+elist[j].dist){
                dis[elist[j].v]=dis[elist[j].u]+elist[j].dist;
                isOK = 1;
            }
        }
        if(!isOK)break;
    }
}
int main(){
    int cnt;
    while(~scanf("%d%d",&n,&cnt)){
        m = 0;
        memset(dis,0x3f,sizeof(dis));
        // memset(visited,0,sizeof(visited));
        for(int i = 0;i<cnt;i++){
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            Edge e;
            elist[m++].set(x,y,k);
            elist[m++].set(y,x,k);
        }
        int start,end;
        scanf("%d%d",&start,&end);
        dis[start] = 0;
        f();
        printf("%d\n",(dis[end]!=0x3f3f3f3f)?dis[end]:-1);
    }
    return 0;
}