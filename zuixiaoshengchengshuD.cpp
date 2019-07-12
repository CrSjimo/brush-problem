#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int arr[550];
struct Edge{
    int pre1;
    int pre2;
    double dist;
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
Edge elist[124800];
bool cmp(Edge e1,Edge e2){
    return e1.dist < e2.dist;
}
double nodeCd[505][2];
int n;
int cas;
inline double calc(double x1,double y1,double x2,double y2){
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}
double dlist[1000];
int main(){
    scanf("%d",&cas);
    while(cas--){
        int cnt = 0;
        int stltNum;
        scanf("%d%d",&stltNum,&n);
        memset(elist,0,sizeof(elist));
        memset(nodeCd,0,sizeof(nodeCd));
        init(n+10);
        for(int i = 0;i<n;i++){
            scanf("%lf%lf",nodeCd[i],nodeCd[i]+1);
        }
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                Edge e;
                e.pre1 = i;
                e.pre2 = j;
                double x1 = nodeCd[i][0];
                double y1 = nodeCd[i][1];
                double x2 = nodeCd[j][0];
                double y2 = nodeCd[j][1];
                e.dist = calc(x1,y1,x2,y2);
                elist[cnt++] = e;
            }
        }
        std::sort(elist,elist+cnt,cmp);
        int dcnt = 0;
        for(int i = 0;i<cnt;i++){
            Edge e = elist[i];
            if(query(e.pre1) != query(e.pre2)){
                update(e.pre1,e.pre2);
                dlist[dcnt++] = e.dist;
                if(dcnt == n)break;
            }
        }
        // for(int i = 0;i<n;i++){
        //     printf(
        //         "test: %.2lf %s\n",
        //         dlist[i],
        //         (i == n - stltNum - 1)?"(ans)":"");
        // }
        printf("%.2lf\n",dlist[n - stltNum - 1]);
    }
    return 0;
}