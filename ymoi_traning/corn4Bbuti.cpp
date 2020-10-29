#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
#include<algorithm>
#include<functional>
using std::lower_bound;
using std::greater;
using std::less;
using std::sort;
using std::max;
int n;
struct Point{
    int x,y;
    Point(){}
    Point(int x,int y){
        this->x=x;
        this->y=y;
    }
    bool operator<(const Point& p)const{
        return y<p.y;
    }
    bool operator>(const Point& p)const{
        return y>p.y;
    }
}* a;
bool cmp(const Point& p1,const Point& p2){
    return p1.x<p2.x;
}
int lis(Point* s,Point* t){
    vector<Point>b;
    b.reserve(t-s);
    b.push_back(*s);
    int ans=0;
    for(Point*p=s+1;p<t;p++){
        if(p->y>b[ans].y){
            ans++;
            b.push_back(*p);
        }else{
            *lower_bound(b.begin(),b.end(),*p)=*p;
        }
    }
    return ans+1;
}
int lds(Point* s,Point* t){
    vector<Point>b;
    b.reserve(t-s);
    b.push_back(*s);
    int ans=0;
    for(Point*p=s+1;p<t;p++){
        if(p->y<b[ans].y){
            ans++;
            b.push_back(*p);
        }else{
            *lower_bound(b.begin(),b.end(),*p,greater<Point>())=*p;
        }
    }
    return ans+1;
}
int main(){
    freopen("simple.in","r",stdin);
    freopen("simple.out","w",stdout);
    scanf("%d",&n);
    a=(Point*)malloc((n+1)*sizeof(Point));
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].x,&a[i].y);
    }
    sort(a+1,a+n+1,cmp);
    int ans=0;int maxn=0;
    for(int i=1;i<=n;i++,ans=0){
        ans+=lis(a+1,a+i);
        //printf("test: %d - %d\n",i,ans);
        ans+=lds(a+i+1,a+n+1);
        //printf("test: %d - %d\n",i,ans);
        maxn=max(ans,maxn);
    }
    printf("%d\n",maxn);
    return 0;
}