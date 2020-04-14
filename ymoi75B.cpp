#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
bool* in_stack;
bool* vis;
vector<int> st;
vector< vector<int> > G;
int n,m;
void dfs(int u,int s){
    vis[u]=1;
    in_stack[u]=1;
    st.push_back(u);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==s&&st.size()>2){
            for(int i=0;i<st.size();i++){
                printf("%d ",st[i]);
            }
            printf("%d\n",v);
            break;
        }else{
            if(!in_stack[v]){
                dfs(v,s);
            }
        }
    }
    st.pop_back();
    in_stack[u]=0;
}
int main(){
    scanf("%d%d",&n,&m);
    st.reserve(m+1);
    G.resize(n+1);
    in_stack=(bool*)calloc((n+1),sizeof(bool));
    vis=(bool*)calloc((n+1),sizeof(bool));
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,i);
        }
    }
    return 0;
}