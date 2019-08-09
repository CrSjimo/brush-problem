#include<stdio.h>
#define MAXN 1010
struct Edge{
    int u,v;
    double rate;
    double cost;
    void set(int u,int v,double rate,double cost){
        this->u = u;
        this->v = v;
        this->rate = rate;
        this->cost = cost;
    }
} elist[MAXN];
double dis[MAXN];
int n,m;
bool f(){
    bool isOK = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(dis[elist[j].v]<(dis[elist[j].u]-elist[j].cost)*elist[j].rate){
                dis[elist[j].v]=(dis[elist[j].u]-elist[j].cost)*elist[j].rate;
                isOK = 1;
            }
        }
        if(!isOK)break;
    }
    for(int j = 0;j<m;j++){
        if(dis[elist[j].v]<(dis[elist[j].u]-elist[j].cost)*elist[j].rate){
            return 1;
        }
    }
    return 0;
}
int main(){
    int m1,s;
    double v;
    scanf("%d%d%d%lf",&n,&m1,&s,&v);
    for(int i = 0 ;i<m1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        double r1,c1,r2,c2;
        scanf("%lf%lf%lf%lf",&r1,&c1,&r2,&c2);
        elist[m++].set(a,b,r1,c1);
        elist[m++].set(b,a,r2,c2);
    }
    dis[s] = v;
    if(f()){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}