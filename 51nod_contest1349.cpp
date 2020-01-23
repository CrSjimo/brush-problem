#include<stdio.h>
#include<vector>
#include<queue>
#include<set>
std::vector<bool> in;
struct Edge{
    int dis;
    int v;
    Edge(){}
    Edge(int dis,int v){
        this->dis = dis;
        this->v = v;
    }
    bool operator<(const Edge& e)const{
        return dis>e.dis;
    }
};
struct HeapNode{
    long long dis;
    int v;
    int e_num;
    HeapNode(){};
    HeapNode(int dis,int v,int e_num){
        this->dis=dis;this->v=v;this->e_num=e_num;
    }
    bool operator<(const HeapNode& e)const{
        return dis>e.dis;
    }
};
std::vector< std::vector<Edge> > G;
std::vector<long long> dis;
int dijstra(int s,int t,bool op,int c){
    dis.assign(dis.size(),__LONG_LONG_MAX__);
    std::priority_queue<HeapNode> q;
    q.push(HeapNode(0,s,0));
    dis[s] = 0;
    while(!q.empty()){
        HeapNode tmp = q.top();q.pop();
        if(tmp.v==t)return tmp.e_num;
        if(dis[tmp.v]<tmp.dis)continue;
        for(int i = 0;i<G[tmp.v].size();i++){
            Edge e = G[tmp.v][i];
            if(op && !in[e.v])continue;
            if(dis[e.v]>dis[tmp.v]+e.dis+c){
                dis[e.v]=dis[tmp.v]+e.dis+c;
                q.push(HeapNode(dis[e.v],e.v,tmp.e_num+1));
            }
        }
    }
    return -1;
}
int n,m,s,t;
int bs(int l,int r){
    if(l>=r)return l-1;
    int m=(l+r)/2;
    
    dijstra(s,t,0,m);
    long long dis1=dis[t];
    
    dijstra(s,t,1,m);
    long long dis2=dis[t];
    //printf("test:%d %lld %lld\n",m,dis1,dis2);
    if(dis1>=dis2) return bs(m+1,r);
    else return bs(l,m);
}
int bs2(){
    for(int c=105;c>0;c--){
        dijstra(s,t,0,c);
        long long dis1=dis[t];
        
        dijstra(s,t,1,c);
        long long dis2=dis[t];
        if(dis1==dis2)return c;
    }
    return -1;
}
int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d%d%d",&n,&m,&s,&t);
        G.resize(n+5);
        dis.resize(n+5);
        in.resize(n+5);
        while(m--){
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            G[x].push_back(Edge(k,y));
            G[y].push_back(Edge(k,x));
        }
        int k;
        scanf("%d",&k);
        while(k--){
            int x;scanf("%d",&x);
            in[x]=true;
        }
        dijstra(s,t,0,0);
        long long dis1=dis[t];
        
        dijstra(s,t,1,0);
        long long dis2=dis[t];
        //printf("%d %d\n",dis1,dis2)
        // int ans = bs(-1,1e9+10);
        // if(ans>1e9+5)printf("Infinity\n");
        // else if(ans<0)printf("Impossible\n");
        int ans = bs2();
        if(ans==-1)printf("Impossible\n");
        else if(ans>100)printf("Infinity\n");
        else printf("%d\n",ans);
    }
    return 0;

}