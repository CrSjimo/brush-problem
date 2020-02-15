#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
using std::vector;
typedef long long ll;
ll* a;
ll* dp;
int* pre;
vector< vector<int> > G;
#include<iostream>
using std::cin;
using std::cout;
bool mp[205][205];
int main(){
    int n;scanf("%d",&n);
    a=(ll*)calloc((n+1),sizeof(ll));
    dp=(ll*)calloc((n+1),sizeof(ll));
    pre=(int*)calloc((n+1),sizeof(int));
    G.resize(n+1);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    int x,y;
    while(~scanf("%d%d",&x,&y) && x && y){
        G[x].push_back(y);
        mp[x][y]=true;
    }
    dp[n]=a[n];
    for(int i=n-1;i>=1;i--){
        ll maxn = 0;
        int maxnp = 0;
        for(int j=0;j<G[i].size();j++){
            int v = G[i][j];
            //printf("t:%d %d\n",i,v);
            if(dp[v]>maxn){
                maxn = dp[v];
                maxnp = v;
            }
        }
        dp[i]=maxn+a[i];
        pre[i]=maxnp;
    }
    ll maxn2 = -19260817;
    int maxn2p = -1;
    for(int i=1;i<=n;i++){
        if(dp[i]>maxn2){
            maxn2 = dp[i];
            maxn2p = i;
        }
    }
    bool _=0;
    for(int k=maxn2p;k>0;k=pre[k]){
        printf(_?"-%d":(_=1,"%d"),k);
    }
    printf("\n%lld\n",maxn2);
    return 0;
}