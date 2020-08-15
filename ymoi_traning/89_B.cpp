#include<cstdio>
#include<cstdlib>
#include<utility>
#include<algorithm>
#include<cstring>
using std::min;
typedef std::pair<double,double> pdd;
pdd cd[20];
const double EPS = 1e-7;
inline bool eq(double a,double b){
    return (a>b?a-b:b-a)<EPS;
}
int dp[1<<18];
inline pdd calc(int i,int j){
    pdd p;
    double x1=cd[i].first,y1=cd[i].second,x2=cd[j].first,y2=cd[j].second;
    p.first=(y1*x2-y2*x1)/(x1*x1*x2-x2*x2*x1);
    p.second=(y1/x1)-p.first*x1;
    return p;
}
inline bool on_para(int i,pdd p){
    double x=cd[i].first,y=cd[i].second,a=p.first,b=p.second;
    return eq(a*x*x+b*x,y);
}
int paras[400];
int tot=0;
int main(){
    int cas;scanf("%d",&cas);
    while(cas--){
        int n,trash;scanf("%d%d",&n,&trash);
        memset(dp,0x3f,(1<<n)*sizeof(int));
        memset(paras,0,sizeof(paras));
        tot=0;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&cd[i].first,&cd[i].second);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                pdd parabola=calc(i,j);
                if(parabola.first>=0)continue;
                ++tot;
                // printf("test: %d %d | %lfx^2+%lfx\n",i,j,parabola.first,parabola.second);
                for(int k=0;k<n;k++){
                    // printf("test: %d\n",k);
                    if(on_para(k,parabola)){
                        paras[tot]|=(1<<k);
                    }
                }
                // printf("0x%x\n\n",paras[tot]);
            }
            paras[++tot]|=(1<<i);
        }
        dp[0]=0;
        for(int S=0;S<(1<<n);S++){
            for(int j=1;j<=tot;j++){
                dp[S|paras[j]]=min(dp[S|paras[j]],dp[S]+1);
            }
        }
        printf("%d\n",dp[(1<<n)-1]);
    }
    return 0;
}