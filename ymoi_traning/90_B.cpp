#include<cstdio>
#include<cstdlib>
#include<utility>
#include<cmath>
typedef std::pair<int,int> pii;
typedef std::pair<double,double> pdd;
const int MOD = 100000007;
pii cd[24];
const double EPS = 1e-7;
inline bool eq(double a,double b){
    return fabs(a-b)<EPS;
}
inline bool collinear(int i,int j,int k){
    int xi=cd[i].first,xk=cd[k].first,xj=cd[j].first;
    int yi=cd[i].second,yk=cd[k].second,yj=cd[j].second;
    return eq(1.0*(yi-yk)/(xi-xk),1.0*(yj-yk)/(xj-xk))||eq(1.0*(xi-xk)/(yi-yk),1.0*(xj-xk)/(yj-yk));
}
int* dp[24];
int lines[24][24];
int* siz;
inline bool belong_to(int i,int S){
    return (S&(1<<i));
}
inline bool between(int i,int k,int j){
    int xi=cd[i].first,xk=cd[k].first,xj=cd[j].first;
    int yi=cd[i].second,yk=cd[k].second,yj=cd[j].second;
    return
        ((xi==xk&&xk==xj)||(abs(xi-xj)>abs(xk-xi) && abs(xi-xj)>abs(xk-xj))) &&
        ((yi==yk&&yk==yj)||(abs(yi-yj)>abs(yk-yi) && abs(yi-yj)>abs(yk-yj)));
}
int main(){
    int n;scanf("%d",&n);
    siz=(int*)calloc((1<<n),sizeof(int));
    for(int i=0;i<n;i++){
        dp[i]=(int*)calloc((1<<n),sizeof(int));
        dp[i][1<<i]=1;
        scanf("%d%d",&cd[i].first,&cd[i].second);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            for(int k=0;k<n;k++){
                if(k==i||k==j)continue;
                if(between(i,k,j)&&collinear(i,k,j)){
                    lines[i][j]|=1<<k;
                    lines[j][i]|=1<<k;
                }
            }
        }
    }
    for(int S=0;S<(1<<n);S++){
        siz[S]=siz[S>>1]+(S&1);
        for(int i=0;i<n;i++){
            if(belong_to(i,S)){
                for(int j=0;j<n;j++){
                    if(!belong_to(j,S)&&((S&lines[i][j])==lines[i][j]))
                    dp[j][S|(1<<j)]+=dp[i][S];
                    dp[j][S|(1<<j)]%=MOD;
                }
            }
        }
    }
    int ans=0;
    for(int S=0;S<(1<<n);S++){
        for(int i=0;i<n;i++){
            if(siz[S]>=4 && (S&(1<<i))){
                ans+=dp[i][S];
                ans%=MOD;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}