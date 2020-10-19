#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::max;
using std::max_element;
int w[20];
int c[20][20];
int dp[20][20][1<<16];
int v[20];


int main(){
    freopen("store.in","r",stdin);
    freopen("store.out","w",stdout);
    int n,m;scanf("%d%d",&n,&m);
    if(m==1){
        int* _c=(int*)malloc((n+1)*sizeof(int));
        int* _w=(int*)malloc((n+1)*sizeof(int));
        for(int i=1;i<=n;i++)scanf("%d",_w+i);
        int _v;scanf("%d",&_v);
        for(int i=1;i<=n;i++)scanf("%d",_c+i);
        int* _dp=(int*)calloc((_v+1),sizeof(int));
        for(int i=1;i<=n;i++){
            for(int j=_w[i];j<=_v;j++){
                    _dp[j]=max(_dp[j],_dp[j-_w[i]]+_c[i]);
            }
        }
        printf("%d\n",_dp[_v]);
    }else{
        for(int i=1;i<=n;i++)scanf("%d",w+i);
        for(int i=1;i<=m;i++)scanf("%d",v+i);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&c[i][j]);
            }
        }
        int U=(1<<(n+1))-1;
        for(int i=1;i<=m;i++){
            for(int S=0;S<(1<<(n+1));S++){
                int Sp=U^S;
                for(int T=Sp;T;T=(T-1)&Sp){
                    dp[i][0][S|T]=dp[i-1][v[i-1]][S];
                    for(int k=1;k<=n;k++){
                        if(!(T&(1<<k)))continue;
                        for(int j=w[k];j<=v[i];j++){
                            dp[i][j][S|T]=max(dp[i][j][S|T],dp[i][j-w[k]][S|T]+c[k][i]);
                        }
                    }
                }
            }
        }
        printf("%d\n",*max_element(dp[m][v[m]],dp[m][v[m]]+(1<<(n+1))));
    }
    return 0;
}