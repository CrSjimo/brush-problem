#include<cstdio>
#include<vector>
#include<queue>
using std::vector;
using std::priority_queue;
#define DEBUG
//HDU_1874
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
vector< vector<Edge> > G;
int* dis;
int n,m,s,t;
void dijstra(){
	std::priority_queue<Edge> q;
	q.push(Edge(0,s));
	dis[s] = 0;
	while(!q.empty()){
		Edge tmp = q.top();q.pop();
		if(tmp.v==t)return;
		if(dis[tmp.v]<tmp.dis)continue;
		for(int i = 0;i<G[tmp.v].size();i++){
			Edge e = G[tmp.v][i];
			if(dis[e.v]>dis[tmp.v]+e.dis){
				dis[e.v]=dis[tmp.v]+e.dis;
				e.dis = dis[e.v];
				q.push(e);
			}
		}
	}
}
int main(){
	#ifndef DEBUG
	freopen("dijstra.in","r",stdin);
	freopen("dijstra.out","w",stdout);
	#endif
	while(~scanf("%d%d",&n,&m)){
		G.resize(n+5);
		G.clear();
		for(int i=0;i<m;i++){
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			G[u].push_back(Edge(d,v));
			G[v].push_back(Edge(d,u));
		}
		scanf("%d%d",&s,&t);
		dis = std::vector<int>(n+5,0x3f3f3f3f);
		dijstra();
		printf("%d\n",dis[t]!=0x3f3f3f3f?dis[t]:-1);
	}
	return 0;
}