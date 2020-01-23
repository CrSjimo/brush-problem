#include<stdio.h>
#include<vector>
#include<utility>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
int n,r,c;
std::map<std::pair<int,int>,int> mp_id;
std::vector<int> mp_t;
std::map<int,std::vector<int> > lis_x;
std::map<int,std::vector<int> > lis_y;
int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{1,-1},{1,0},{1,1},{0,-1},{0,1}};
std::vector< std::vector<int> > G;
std::vector< std::vector<int> > G2;
std::vector<int> dfn;
std::vector<int> low;
std::vector<bool> ins;
std::vector<int> color;
std::vector<int> color_w;
int cnt=0;
int T=0;
std::stack<int> s;
int maxn=-1;
void tarjan(int u){
    dfn[u]=low[u]=++T;
    ins[u]=true;
    s.push(u);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=std::min(low[u],low[v]);
        }else if(ins[v]){
            low[u]=std::min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        int v;int num=0;
        do{
            v=s.top();s.pop();ins[v]=0;
            color[v]=cnt;
            num++;
        }while(u!=v);
        color_w.push_back(num);
       cnt++;
    }
}
void suodian(){
    G2.resize(cnt+5);
    for(int i=0;i<n;i++){
        int u=color[i];
        for(int j=0;j<G[i].size();j++){
            int v=color[G[i][j]];
            if(u==v)continue;
            G2[u].push_back(v);
        }
    }
}
std::vector<int> dis;
void dfs(int u,int k){
    dis[u]=std::max(k,dis[u]);
    for(int i=0;i<G2[u].size();i++){
        int v=G2[u][i];
        dfs(v,k+color_w[v]);
    }
}
void find(){
    dis = std::vector<int>(cnt+5,1);
    std::vector<bool> ind(cnt+5);
    for(int i=0;i<cnt;i++){
        if(ind[i]==false){
            //printf("test:%d(%d)\n",i,color_w[i]);
            dfs(i,color_w[i]);
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&r,&c);
    mp_t.resize(n+5);
    G.resize(n+5);
    dfn.resize(n+5);
    low.resize(n+5);
    ins.resize(n+5);
    color.resize(n+5);
    for(int i=0;i<n;i++){
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        lis_x[x].push_back(i);
        lis_y[y].push_back(i);
        auto p = std::make_pair(x,y);
        mp_id[p]=i;
        mp_t[i]=t;
    }
    for(auto ptr = mp_id.begin();ptr!=mp_id.end();ptr++){
        int u=ptr->second,x=ptr->first.first,y=ptr->first.second;
        int t=mp_t[u];
        if(t==1){
            for(int j=0;j<lis_x[x].size();j++){
                int v = lis_x[x][j];
                G[u].push_back(v);
            }
        }
        if(t==2){
            for(int j=0;j<lis_y[y].size();j++){
                int v = lis_y[y][j];
                G[u].push_back(v);
            }
        }
        if(t==3){
            for(int j=0;j<8;j++){
                auto p = std::make_pair(x+dir[j][0],y+dir[j][1]);
                if(mp_id.count(p)!=0){
                    G[u].push_back(mp_id[p]);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!dfn[i])tarjan(i);
    }
    suodian();
    // for(int i=0;i<cnt;i++){
    //     printf("%d(%d):",i,color_w[i]);
    //     for(int j=0;j<G2[i].size();j++){
    //         printf("%d ",G2[i][j]);
    //     }
    //     printf("\n");
    // }
    find();
    printf("%d\n",*std::max_element(dis.begin(),dis.end()));
    return 0;
}