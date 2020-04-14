#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
using std::vector;
int* link;
bool* found;
vector< vector<int> > G;
// bool** G;
int n,m;
bool dfs(int u){
    for(int v:G[u]){
        // if(!G[u][v])continue;
        if(!found[v]){
            found[v]=true;
            if(!link[v]||dfs(link[v])){
                link[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hungry(){
    int ans = 0;
    for(int i=1;i<=n;i++){
        memset(found,0,(m+1)*sizeof(bool));
        if(dfs(i))ans++;
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    link = (int*)calloc(m+1,sizeof(int));
    found = (bool*)calloc(m+1,sizeof(bool));
    G.resize(m+1);
    // G = (bool**)malloc(m+1*sizeof(bool*));
    // for(bool**p=G;p<=G+m;p++)*p=(bool*)calloc(m+1,sizeof(bool));
    int x,y;
    while(~scanf("%d%d",&x,&y)&&x!=-1&&y!=-1){
        //G[x][y-n]=1;
        G[x].push_back(y-n);
    }
    printf("%d\n",hungry());
    return 0;
}