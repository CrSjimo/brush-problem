#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
int arr[110];
struct Edge{
    int pre1;
    int pre2;
    double dist;
};
struct ball{
    double x,y,z,r;
    double operator-(const ball& b)const{
        double d = sqrt(pow(b.x-x,2)+pow(b.y-y,2)+pow(b.z-z,2))-r-b.r;
        return std::max(d,0.0);
    }
    
} a[110];
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
        memset(elist,0,sizeof(elist));
        init(n+10);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z,&a[i].r);
            for(int j = 0;j<i;j++){
                Edge e;
                e.pre1 = j;
                e.pre2 = i;
                e.dist = a[j]-a[i];
                elist[cnt++] = e;
            }
        }
        // printf("%d\n",cnt);
        std::sort(elist,elist+cnt,cmp);
        double ans = 0;
        for(int i = 0;i<cnt;i++){
            Edge e = elist[i];
            if(query(e.pre1) != query(e.pre2)){
                update(e.pre1,e.pre2);
                ans += e.dist;
            }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}