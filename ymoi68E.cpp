#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
using std::vector;
using std::max;
vector< vector<int> > G;
vector< vector<int> > GR;
int a[55][55];
int n,m;
inline bool inRange(int i,int j){
    return i>=1&&i<=n&&j>=1&&j<=m;
}
inline int f(int i,int j){
    return (i-1)*m+j;
}
inline int xf(int u){
    return (u-1)/m+1;
}
inline int yf(int u){
    return (u-1)%m+1;
}
int op[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
int color[55];
int cnt = 0;
int maxn = -19260817;
int curr = 0;
vector<int> colorNum(1);
void dfs(int u){
    color[u]=cnt+1;
    curr++;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if(!color[v]){
            dfs(v);
        }
    }
}
int main(){
    scanf("%d%d",&m,&n);
    G.resize(n*m+10);GR.resize(n*m+10);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            bool p[4] = {0,0,0,0};
            for(int k=0;k<4;k++){
                if(a[i][j]&(1<<k) && inRange(i+op[k][0],j+op[k][1])){
                    p[k]=1;
                    if(k==1||k==2)GR[f(i,j)].push_back(f(i+op[k][0],j+op[k][1]));
                }
            }
            for(int k=0;k<4;k++){
                if(!p[k] && inRange(i+op[k][0],j+op[k][1])){
                    G[f(i,j)].push_back(f(i+op[k][0],j+op[k][1]));
                    G[f(i+op[k][0],j+op[k][1])].push_back(f(i,j));
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!color[f(i,j)]){
                curr=0;
                dfs(f(i,j));
                cnt++;
                maxn = max(maxn,curr);
                colorNum.push_back(curr);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%d ",color[f(i,j)]);
    //     }
    //     printf("\n");
    // }
    printf("%d\n%d\n",cnt,maxn);
    int nmaxn = -19260817;
    int nmaxnp = 0;
    int nmaxnv = 0;
    char nmaxnpk = 0;
    for(int j=1;j<=m;j++){
        for(int i=n;i>=1;i--){
            int u = f(i,j);
            for(int l=0;l<GR[u].size();l++){
                int v = GR[u][l];
                if(v-u==1)continue;
                if(color[u] == color[v])continue;
                int ncurr = colorNum[color[u]]+colorNum[color[v]];
                if(ncurr>nmaxn){
                    nmaxn = ncurr;
                    nmaxnp = u;
                    nmaxnv = v;
                    nmaxnpk = 'N';
                }
            }
        }
        for(int i=n;i>=1;i--){
            int u = f(i,j);
            for(int l=0;l<GR[u].size();l++){
                int v = GR[u][l];
                if(v-u!=1)continue;
                if(color[u] == color[v])continue;
                int ncurr = colorNum[color[u]]+colorNum[color[v]];
                if(ncurr>nmaxn){
                    nmaxn = ncurr;
                    nmaxnp = u;
                    nmaxnv = v;
                    nmaxnpk = 'E';
                }
            }
        }
    }
    printf("%d\n",nmaxn);
    //printf("t:%d %d\n",nmaxnp,nmaxnv);
    printf("%d %d %c\n",xf(nmaxnp),yf(nmaxnp),nmaxnpk);
    return 0;
}