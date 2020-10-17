#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::min;
using std::max;
int cube[102][102][102];
const int INF = 2147483647;
int main(){
    freopen("cube.in","r",stdin);
    freopen("cube.out","w",stdout);
    int a,b,c,n;scanf("%d%d%d%d",&a,&b,&c,&n);
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=c;k++){
                int _;scanf("%d",&_);
                cube[i][j][k]=_;
            }
        }
    }
    int ans=INF;
    for(int i=1;i+n-1<=a;i++){
        for(int j=1;j+n-1<=b;j++){
            for(int k=1;k+n-1<=c;k++){
                int maxn=-INF,minn=INF;
                for(int i1=i;i1<=i+n+1;i1++){
                    for(int j1=j;j1<=j+n+1;j1++){
                        for(int k1=k;k1<=k+n+1;k1++){
                            maxn=max(maxn,cube[i1][j1][k1]);
                            minn=min(minn,cube[i1][j1][k1]);
                        }
                    }
                }
                ans=min(ans,maxn-minn);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}