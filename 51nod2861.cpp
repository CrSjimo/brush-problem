#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<vector>
using std::vector;
using std::min;
using std::stack;
vector<int> G[2010];
char tmp1[4],tmp2[4];
inline void addedge(int x,int y){
    G[x].push_back(y);
}
template<typename T>
inline void clr(T* a,int siz){
    memset(a,0,sizeof(T)*siz);
}
int dfn[2010];
int low[2010];
int color[2010];
bool vis[2010];
int T=0;
int cnt=0;
std::stack<int> s;
void tarjan(int u){
    dfn[u]=low[u]=++T;
    vis[u]=true;
    s.push(u);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=std::min(low[u],low[v]);
        }else if(vis[v]){
            low[u]=std::min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        ++cnt;
        int v;
        do{
            v=s.top();s.pop();vis[v]=0;
            color[v]=cnt;
        }while(u!=v);
    }
}
int main(){
    int cas;scanf("%d",&cas);
    while(cas--){
        int n,m;
        scanf("%d%d",&n,&m);
        T=cnt=0;
        clr(G,n<<1|1);
        clr(dfn,n<<1|1);
        clr(low,n<<1|1);
        clr(color,n<<1|1);
        clr(vis,n<<1|1);
        for(int i=1;i<=m;i++){
            scanf("%s%s",tmp1,tmp2);
            int x = atoi(tmp1+1),y = atoi(tmp2+1);
            if(*tmp1=='h')x<<=1;
            else x=(x<<1)-1;
            if(*tmp2=='h')y<<=1;
            else y=(y<<1)-1;
            int _x = (x&1)?x+1:x-1;
            int _y = (y&1)?y+1:y-1;
            //printf("ttt %s %s %d %d %d %d\n",tmp1,tmp2,x,y,_x,_y);
            addedge(_x,y);
            addedge(_y,x);
        }
        // for(int i=1;i<=(n<<1);i++){
        //     printf("t %d:\n",i);
        //     for(int v:G[i]){
        //         printf("%d ",v);
        //     }
        //     printf("\n");
        // }
        for(int i=1;i<=(n<<1);i++){
            if(!dfn[i])tarjan(i);
        }
        for(int i=1;i<=n;i++){
           // printf("t:%d %d %d\n",i,color[i<<1],color[(i<<1)-1]);
            if(color[i<<1]==color[(i<<1)-1]){
                printf("BAD\n");
                goto match;
            }
        }
        printf("GOOD\n");
        match:;
    }
    return 0;
}