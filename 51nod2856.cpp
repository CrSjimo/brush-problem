#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
using std::vector;
#define calloc2d(T,ptr,n,m) ptr = (T**)malloc((n+1)*sizeof(T*));for(T**p=ptr;p<=ptr+m;p++)*p=(T*)calloc((m+1),sizeof(T));
int* link;
bool* found;
vector< vector<int> > G;
bool** mp;
int n,m;
int** h_color;
int** v_color;
int h_siz;
int siz = 0;
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
    for(int i=1;i<=h_siz;i++){
        memset(found,0,(siz+1)*sizeof(bool));
        if(dfs(i))ans++;
    }
    return ans;
}
void color(){
    int T=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]&&!h_color[i][j]){
                h_color[i][j]=++T;
                for(int k=j+1;k<=m&&mp[i][k];k++){
                    h_color[i][k]=T;
                }
            }
        }
    }
    siz+=T;h_siz=T;
    T=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]&&!v_color[i][j]){
                v_color[i][j]=++T;
                for(int k=i+1;k<=n&&mp[k][j];k++){
                    v_color[k][j]=T;
                }
            }
        }
    }
    siz+=T;
    link = (int*)calloc(siz+1,sizeof(int));
    found = (bool*)calloc(siz+1,sizeof(bool));
    G.resize(siz+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]){
                G[h_color[i][j]].push_back(v_color[i][j]);
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    calloc2d(bool,mp,n,m);
    calloc2d(int,h_color,n,m);
    calloc2d(int,v_color,n,m);
    for(int i=1;i<=n;i++){
        char* s=(char*)malloc((m+2)*sizeof(char));
        scanf("%s",s+1);
        for(int j=1;j<=m;j++){
            mp[i][j]=(s[j]=='*');
        }
    }
    color();
    printf("%d\n",hungry());
    return 0;
}