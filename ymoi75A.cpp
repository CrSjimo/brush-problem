#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
bool** G;
int* d;
vector<int> st;
int n,m;
void dfs(int u){
    for(int v=1;v<=n;v++){
        if(!G[u][v])continue;
        G[u][v]=G[v][u]=0;
        dfs(v);
    }
    st.push_back(u);
}
int main(){
    scanf("%d%d",&n,&m);
    st.reserve(m+4);
    d=(int*)calloc((n+1),sizeof(int));
    G=(bool**)malloc((n+1)*sizeof(bool*));
    for(bool**p=G;p<=G+n;p++)*p=(bool*)calloc((n+1),sizeof(bool));
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        G[x][y]=G[y][x]=1;
        d[x]++;d[y]++;
    }
    for(int i=n;i>=1;i--){
        if(d[i]&1){
            dfs(i);
            goto print;
        }
    }
    dfs(1);
    print:;
    for(int i=0;i<st.size();i++){
        printf("%d ",st[i]);
    }
    printf("\n");
    return 0;
}