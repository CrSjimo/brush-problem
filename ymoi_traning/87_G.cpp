#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using std::max;
using std::vector;
vector< vector<int> >G;
int* a;
int n;
int* dp;
int* pd;
void dfs(int u){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        dfs(v);
        dp[u]+=pd[v];
        pd[u]+=max(dp[v],pd[v]);
    }
}
int main(){
    scanf("%d",&n);
    G.resize(n+1);
    a=(int*)malloc((n+1)*sizeof(int));
    dp=(int*)calloc((n+1),sizeof(int));
    pd=(int*)calloc((n+1),sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        dp[i]=a[i];
        pd[i]=0;
    }
    int M=n*(n+1)/2;
    for(int i=1;i<=n-1;i++){
        int l,k;scanf("%d%d",&l,&k);
        G[k].push_back(l);
        M-=l;
    }
    dfs(M);
    printf("%d\n",max(dp[M],pd[M]));
    return 0;
}