#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<utility>
#include<cmath>
#include<algorithm>
using std::make_pair;
typedef std::pair<double,double> PT;
using std::vector;
using std::sort;
int n;
struct EdgeE{
    int u,v;
    double w;
    EdgeE(int u,int v,double w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
    bool operator<(const EdgeE& e)const{
        return w<e.w;
    }
};
vector<EdgeE> a;
struct Bcj{
    int n;
    int* f;
    Bcj(int n){
        this->n=n;
        f=(int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;i++){
            f[i]=i;
        }
    }
    ~Bcj(){
        free(f);
    }
    int find(int x){
        return f[x]==x?x:f[x]=find(f[x]);
    }
    void update(int x,int y){
        f[find(x)]=find(y);
    }
};
vector<PT> p;
inline double calc(PT& p1,PT& p2){
    return sqrt(pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2));
}
int main(){
    scanf("%d",&n);
    Bcj bcj = Bcj(n);
    p.resize(n+1);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&p[i].first,&p[i].second);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            double w=calc(p[i],p[j]);
            a.push_back(EdgeE(i,j,w));
        }
    }
    sort(a.begin(),a.end());
    int cnt=0;
    double ans=0;
    for(int i=0;cnt<=n-1&&i<a.size();i++){
        EdgeE& e=a[i];
        if(bcj.find(e.u)!=bcj.find(e.v)){
            bcj.update(e.u,e.v);
            cnt++;
            ans+=e.w;
        }
    }
    printf("%.2lf\n",ans);
    return 0;
}