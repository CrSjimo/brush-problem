#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>
#include<functional>
using std::greater;
using std::sort;
using std::stable_sort;
using std::vector;
using std::set;
struct Edge{
    double w;
    int v;
    Edge(){}
    Edge(double w,int v){
        this->w=w;
        this->v=v;
    }
};
vector< vector<Edge> >G;
struct Point{
    int x,y,z;
    Point(){}
    Point(int x,int y,int z){
        this->x=x;
        this->y=y;
        this->z=z;
    }
    double operator-(const Point& p)const{
        return sqrt(pow(x-p.x,2)+pow(y-p.y,2)+pow(z-p.z,2));
    }
}* a;
struct Query{
    int r;
    int i;
    int ans;
    bool operator<(const Query& q)const{
        return r<q.r;
    }
    bool operator>(const Query& q)const{
        return i<q.i;
    }
}* qs;
set<int> s;
struct Edge2{
    int u;int v;double w;
    Edge2(){}
    Edge2(int u,int v,double w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
    bool operator<(const Edge2& e)const{
        return w<e.w;
    }
}* elist;
int tot = 0;
namespace bcj{
    int ans=0;
    int* f;
    int* siz;
    void init(int n){
        f=(int*)malloc((n+1)*sizeof(int));
        siz=(int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;i++)f[i]=i,siz[i]=1;
    }
    int find(int i){
        if(f[i]==i)return i;
        int fi = f[i];
        f[i]=find(f[i]);
        siz[i]=siz[f[i]];
        return f[i];
    }
    void update(int i,int j){
        int fi=find(i),fj=find(j);
        if(fi==fj)return;
        f[fi]=fj;
        siz[fj]+=siz[fi];
        siz[fi]=siz[fj];
    }
}
int main(){
    freopen("invade.in","r",stdin);
    freopen("invade.out","w",stdout);
    int n,m;scanf("%d%d",&n,&m);
    bool op1 = n*m<=5e5;
    a=(Point*)malloc((n+1)*sizeof(int));
    qs=(Query*)malloc((m+1)*sizeof(Query));
    elist=(Edge2*)malloc((n+2)*(n+2)*sizeof(Edge2));
    G.resize(n+1);
    bcj::init(n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    }
    a[0]=Point(0,0,0);
    for(int i=1;i<=m;i++){
        scanf("%d",&qs[i].r);
        qs[i].i=i;
    }
    sort(qs+1,qs+m+1);
    for(int i=0;i<=n;i++){
        for(int j=0;j<i;j++){
            elist[++tot]=Edge2(i,j,a[i]-a[j]);
        }
    }
    stable_sort(elist+1,elist+tot+1);
    int i=1;
    for(int j=1;j<=m;j++){
        int r = qs[j].r;
        //printf("test-q: %d %d\n",qs[j].i,r);
        for(;i<=tot&&elist[i].w<=r;i++){
            Edge2& e = elist[i];
            bcj::update(e.u,e.v);
            //printf("test: %d %d %lf\n",e.v,e.u,e.w);
        }
        qs[j].ans=0;
        for(int k=0;k<=n;k++){
            //printf("test: %d %d %d\n",k,bcj::find(k),bcj::find(0));
            qs[j].ans+=(bcj::find(k)==bcj::find(0));
        }
    }
    sort(qs+1,qs+m+1,greater<Query>());
    for(int i=1;i<=m;i++){
        printf("%d\n",qs[i].ans-1);
    }
    return 0;
}