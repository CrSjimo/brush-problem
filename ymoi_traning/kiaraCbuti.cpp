#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include<cstring>
using std::max;
using std::max_element;
int w[25];
int c[25][25];
int dp[25][1 << 16];
int dpp[25][1<<16];
int v[25];
int f[25];

int main() {
    // freopen("store.in", "r", stdin);
    freopen("store.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    if (m == 1) {
        int* _c = (int*)malloc((n + 1) * sizeof(int));
        int* _w = (int*)malloc((n + 1) * sizeof(int));
        for (int i = 1; i <= n; i++) scanf("%d", _w + i);
        int _v;
        scanf("%d", &_v);
        for (int i = 1; i <= n; i++) scanf("%d", _c + i);
        int* _dp = (int*)calloc((_v + 1), sizeof(int));
        for (int i = 1; i <= n; i++) {
            for (int j = _w[i]; j <= _v; j++) {
                _dp[j] = max(_dp[j], _dp[j - _w[i]] + _c[i]);
            }
        }
        printf("%d\n", _dp[_v]);
    } else {
        for (int i = 0; i < n; i++) scanf("%d", w + i);
        for (int i = 1; i <= m; i++) scanf("%d", v + i);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &c[i][j]);
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int S = 1; S < (1 << (n)); S++) {
                memset(f,0,sizeof(f));
                for(int k=0;k<n;k++){
                    if((S>>k)&1)
                    for(int j=w[k];j<=v[i];j++){
                        f[j]=max(f[j],f[j-w[k]]+c[k][i]);
                    }
                }
                dp[i][S]=f[v[i]];
            }
        }
        // for(int i=1;i<=m;i++){
        //     for(int S=0;S<(1<<(n));S++){
        //         printf("test: %d %d %d\n",i-1,S,dp[i][S]);
        //     }
        // }
        for(int S=1;S<(1<<(n));S++){
            dpp[1][S]=dp[1][S];
        }
        for(int i=2;i<=m;i++){
            for(int S=0;S<(1<<(n));S++){
                dpp[i][S]=max(dpp[i-1][S],dp[i][S]);
                for(int T=S&(S-1);T;T=(T-1)&S){
                    dpp[i][S]=max(dpp[i][S],dpp[i-1][T]+dp[i][S^T]);
                }
            }
        }
        printf("%d\n",dpp[m][(1<<(n))-1]);
    }
    return 0;
}
