#include<cstdio>
#include<cstdlib>
#include<vector>
int n,m;
using std::vector;
vector< vector<int> >G;
inline void addedge(int x,int y){
    G[x].push_back(y);
}
char tmp[3];
int tmmp;
vector<bool> vis;
void dfs(int u){
    //printf("ttt:%d\n",u);
    vis[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!vis[v])dfs(v);
    }
    //printf("r\n");
}
bool cando(int u){
    for(int i=1;i<=2*n;i++)vis[i]=0;
    dfs(u);
    for(int i=1;i<=n;i++){
        //printf("tvis: %d %d %d\n",i,vis[2*i]?1:0,vis[2*i-1]?1:0);
        if(vis[2*i]&&vis[2*i-1])return false;
    }
    //printf("\n");
    return true;
}
int main(){
    scanf("%d%d",&n,&m);
    G.resize(2*n+5);
    vis.resize(2*n+5);
    while(m--){
        int x,y;
        scanf("%d%s",&tmmp,tmp);
        if(*tmp=='Y')x=tmmp*2-1;
        else x=tmmp*2;
        scanf("%d%s",&tmmp,tmp);
        if(*tmp=='Y')y=tmmp*2-1;
        else y=tmmp*2;
        int _x=(x&1)?x+1:x-1;
        int _y=(y&1)?y+1:y-1;
        addedge(_x,y);
        addedge(_y,x);
    }
    // for(int i=1;i<=2*n;i++){
    //     printf("%d: ",i);
    //     for(int v:G[i]){
    //         printf("%d ",v);
    //     }
    //     printf("\n");
    // }
    vector<char> s;
    for(int i=1;i<=n;i++){
        //printf("t: %d\n",i);
        bool a=cando(i*2);
        bool b=cando(i*2-1);
        if(!a&&!b){
            printf("IMPOSSIBLE\n");
            exit(0);
        }else if(a&&b){
            s.push_back('?');
        }else if(a){
            s.push_back('N');
        }else if(b){
            s.push_back('Y');
        }
    }
    for(int i=0;i<n;i++){
        printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}