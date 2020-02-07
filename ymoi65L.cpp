#include<cstdio>
#include<vector>
using std::vector;
using std::max;
vector< vector<int> > G;
vector<bool> nocando;
vector<int> in_stack;
vector<int> ans;
int n,m;
int maxn = -1;
void dfs(int i,int tot){
    if(i>n){
        if(tot>maxn){
            maxn=tot;
            ans = in_stack;
        }
        return;
    }
    if(!nocando[i]){
        for(int j=0;j<G[i].size();j++){
            int v = G[i][j];
            nocando[v]=true;
        }
        in_stack[i]=1;
        dfs(i+1,tot+1);
        in_stack[i]=0;
        for(int j=0;j<G[i].size();j++){
            int v = G[i][j];
            nocando[v]=false;
        }
    }else{
        dfs(i+1,tot);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    G.resize(n+5);
    nocando.resize(n+5);
    in_stack.resize(n+5);
    ans.resize(n+1);
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        G[x].push_back(y);G[y].push_back(x);
    }
    dfs(1,0);
    printf("%d\n",maxn);
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}