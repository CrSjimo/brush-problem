#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<functional>
using std::greater;
using std::map;
using std::max;
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y){
        this->x=x;
        this->y=y;
    }
    Point(const std::pair<double,double>& pdd){
        x=pdd.first;
        y=pdd.second;
    }
};
struct Line{
    Point p1,p2;
    Line(){}
    Line(Point p1,Point p2){
        this->p1=p1;
        this->p2=p2;
    }
    double slope()const{
        return (p1.y-p2.y)/(p1.x-p2.x);
    }
    bool operator<(const Line& ln)const{
        return slope()<ln.slope();
    }
};
map<double,double,greater<double> >mp_max;
map<double,double>mp_min;
inline void add_map(const Point& p){
    if((!mp_max.count(p.x))||mp_max[p.x]<p.y){
        mp_max[p.x]=p.y;
    }
    if((!mp_min.count(p.x))||mp_min[p.x]>p.y){
        mp_min[p.x]=p.y;
    }
}
int main(){
    freopen("fruit.in","r",stdin);
    freopen("fruit.out","w",stdout);
    int n;scanf("%d",&n);
    Line maxn;
    if(n==1)return 0;
    scanf("%lf%lf%lf%lf",&maxn.p1.y,&maxn.p1.x,&maxn.p2.y,&maxn.p2.x);
    add_map(maxn.p1);add_map(maxn.p2);
    printf("%.2lf\n",maxn.slope());
    for(int i=3;i<=n;i++){
        Point p;scanf("%lf%lf",&p.y,&p.x);
        add_map(p);
        map<double,double>::iterator t1p = mp_max.upper_bound(p.x);
        if(t1p!=mp_max.end()){
            Point t1(*t1p);
            // printf("testt1: (%.2lf,%.2lf) %.2lf\n",t1.x,t1.y,Line(p,t1).slope());
            maxn=max(maxn,Line(p,t1));
        }
        map<double,double>::iterator t2p = mp_min.upper_bound(p.x);
        if(t2p!=mp_min.end()){
            Point t2(*t2p);
            // printf("testt2: (%.2lf,%.2lf)\n",t2.x,t2.y);
            maxn=max(maxn,Line(p,t2));
        }
        printf("%.2lf\n",maxn.slope());
    }
    return 0;
}