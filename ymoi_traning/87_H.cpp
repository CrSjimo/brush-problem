#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using std::min;
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
        dp[u]+=min(dp[v],pd[v]);
        pd[u]+=dp[v];
    }
}
int main(){
    scanf("%d",&n);
    G.resize(n+1);
    dp=(int*)calloc((n+1),sizeof(int));
    pd=(int*)calloc((n+1),sizeof(int));
    int M=n*(n-1)/2;
    for(int i=1;i<=n;i++){
        int k,p;scanf("%d%d",&k,&p);
        dp[k]=1;
        while(p--){
            int l;scanf("%d",&l);
            G[k].push_back(l);
            M-=l;
        }
    }
    dfs(M);
    printf("%d\n",min(dp[M],pd[M]));
    return 0;
}