#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<utility>
#include<vector>
using std::vector;
using std::pair;
using std::min;
double** f;
const double INF=192608171926.0;
#define fr(x) for(int x=1;x<=n;x++)
int n;
typedef pair<double,double> plflf;
inline double calc(plflf p1,plflf p2){
    return sqrt(pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2));
}
vector<plflf> pts;
int main(){
    scanf("%d",&n);
    pts.resize(n+1);
    f=(double**)malloc((n+1)*sizeof(double*));
    fr(i){f[i]=(double*)malloc((n+1)*sizeof(double));fr(j)f[i][j]=INF;}
    fr(i)scanf("%lf%lf",&pts[i].first,&pts[i].second);
    fr(i)f[i][i]=0;
    int m;scanf("%d",&m);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        f[u][v]=f[v][u]=calc(pts[u],pts[v]);
    }
    fr(k)fr(i)fr(j)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    int s,t;scanf("%d%d",&s,&t);
    printf("%.2lf\n",f[s][t]);
    return 0;
}
