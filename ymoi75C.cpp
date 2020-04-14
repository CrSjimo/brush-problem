#include<cstdio>
#include<cstdlib>
#include<vector>
using std::max;
using std::vector;
int** G;
int* d;
vector<int> st;
int n,m;
void dfs(int u){
    for(int v=1;v<=n;v++){
        if(!G[u][v])continue;
        G[u][v]--;
        G[v][u]--;
        dfs(v);
    }
    st.push_back(u);
}
int main(){
    n=500;
    scanf("%d",&m);
    st.reserve(m+4);
    d=(int*)calloc((n+1),sizeof(int));
    G=(int**)malloc((n+1)*sizeof(int*));
    for(int**p=G;p<=G+n;p++)*p=(int*)calloc((n+1),sizeof(int));
    n=0;
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        G[x][y]++;G[y][x]++;
        d[x]++;d[y]++;
        n=max(x,n);
        n=max(y,n);
    }
    for(int i=1;i<=n;i++){
        if(d[i]&1){
            dfs(i);
            goto print;
        }
    }
    dfs(1);
    print:;
    while(st.size()){
        printf("%d\n",st.back());st.pop_back();
    }
    return 0;
}