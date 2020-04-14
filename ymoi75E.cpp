#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<utility>
#include<vector>
using std::vector;
using std::pair;
using std::min;
using std::max;
double** f;
double* md;
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
    md=(double*)calloc((n+1),sizeof(double));
    fr(i){f[i]=(double*)malloc((n+1)*sizeof(double));fr(j)f[i][j]=INF;}
    fr(i)scanf("%lf%lf",&pts[i].first,&pts[i].second);
    fr(i)f[i][i]=0;
    fr(i){
        char*s=(char*)malloc((n+2)*sizeof(char));
        scanf("%s",s+1);
        fr(j)if(s[j]=='1')f[i][j]=f[j][i]=calc(pts[i],pts[j]);
    }
    fr(k)fr(i)fr(j)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    fr(i)fr(j)if(f[i][j]!=INF)md[i]=max(md[i],f[i][j]);
    double minn=INF;
    fr(i)fr(j)if(f[i][j]==INF)minn=min(minn,md[i]+md[j]+calc(pts[i],pts[j]));
    fr(i)minn=max(minn,md[i]);
    printf("%.6lf\n",minn);
    return 0;
}
