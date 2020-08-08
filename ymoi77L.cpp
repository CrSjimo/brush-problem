#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<deque>
#include<algorithm>
using std::vector;
using std::max_element;
using std::deque;
using std::min;
using std::max;
struct Edge{
    int w;
    int v;
    Edge(){}
    Edge(int w,int v){
        this->w=w;
        this->v=v;
    }
};
vector< vector<Edge> >G;
int n,s;
int dis[305][305];
Edge far[305];
void dfs(int u,int s,int fa){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i].v,w=G[u][i].w;
        if(v==fa)continue;
        dis[s][v]=dis[s][u]+w;
        dfs(v,s,u);
    }
}
int diameter;
void find_diameter(){
    for(int i=1;i<=n;i++){
        dfs(i,i,0);
        far[i].v = max_element(dis[i]+1,dis[i]+n+1)-dis[i];
        far[i].w = dis[i][far[i].v];
        //printf("test: %d %d %d\n",i,far[i].v,far[i].w);
    }
    diameter = far[far[1].v].w;
}
int pre[305];
void dfs2(int u,int fa){
    pre[u]=fa;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i].v;
        if(v==fa)continue;
        dfs2(v,u);
    }
}
int ecc(){
    int minn = 19260817;
    for(int i=1;i<=n;i++){
        if(far[i].w==diameter){
            dfs2(i,0);
            deque<int> q;
            for(int u=far[i].v;u;u=pre[u]){
                q.push_back(u);
                while(dis[q.front()][q.back()]>s)q.pop_front();
                if(q.empty())continue;
                //printf("test: %d %d %d %d\n",u,minn,q[0],q.back());
                int maxx=0;
                for(int i=1;i<=n;i++){
                    int d=19260817;
                    for(int j=0;j<q.size();j++){
                        int v=q[j];
                        d=min(d,dis[i][v]);
                    }
                    maxx=max(maxx,d);
                }
                minn = min(minn,maxx);
            }
            q.pop_front();
            while(!q.empty()){
                //printf("test: %d %d %d\n",minn,q[0],q.back());
                int maxx=0;
                for(int i=1;i<=n;i++){
                    int d=19260817;
                    for(int j=0;j<q.size();j++){
                        int v=q[j];
                        d=min(d,dis[i][v]);
                    }
                    maxx=max(maxx,d);
                }
                minn = min(minn,maxx);
                q.pop_front();
            }
        }
    }
    return minn;
}
int main(){
    scanf("%d%d",&n,&s);
    G.resize(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(Edge(w,v));
        G[v].push_back(Edge(w,u));
    }
    find_diameter();
    printf("%d\n",ecc());
    return 0;
}