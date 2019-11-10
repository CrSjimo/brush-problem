#include<stdio.h>
#include<vector>
#include<algorithm>
const int MOD = 10007;
std::vector< std::vector<int> > map;
std::vector<int> w;
int ans1 = -1;
int ans2 = 0;
int dfs(int u,int pth,int v,int orig){
    if(pth==2){
        ans1=std::max(w[orig]*w[v],ans1);
        ans2+=(w[orig]*w[v])%MOD;
        ans2%=MOD;
    }
    for(int i=0;i<map[v].size();i++){
        if(map[v][i]==u)continue;
        dfs(v,pth+1,map[v][i],orig);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    map.resize(n+10);
    w.resize(n+10);
    for(int i=0;i<n-1;i++){
        int s,t;
        scanf("%d%d",&s,&t);
        map[s].push_back(t);
        map[t].push_back(s);
    }
    for(int i = 1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        dfs(i,0,i,i);
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}