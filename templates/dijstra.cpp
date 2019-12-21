#include<stdio.h>
#include<vector>
#include<queue>
#define DEBUG
//HDU_1874
struct Edge{
	int dist;
	int next;
	Edge(){}
	Edge(int dist,int next){
		this->dist = dist;
		this->next = next;
	}
	bool operator<(const Edge& e)const{
		return dist>e.dist;
	}
};
std::vector< std::vector<Edge> > map;
std::vector<int> dist;
int n,m,s,t;
void dijstra(){
	std::priority_queue<Edge> q;
	q.push(Edge(0,s));
	dist[s] = 0;
	while(!q.empty()){
		Edge tmp = q.top();q.pop();
		if(tmp.next==t)return;
		if(dist[tmp.next]<tmp.dist)continue;
		for(int i = 0;i<map[tmp.next].size();i++){
			Edge e = map[tmp.next][i];
			if(dist[e.next]>dist[tmp.next]+e.dist){
				dist[e.next]=dist[tmp.next]+e.dist;
				e.dist = dist[e.next];
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
		map.resize(n+5);
		map.clear();
		for(int i=0;i<m;i++){
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			map[u].push_back(Edge(d,v));
			map[v].push_back(Edge(d,u));
		}
		scanf("%d%d",&s,&t);
		dist = std::vector<int>(n+5,0x3f3f3f3f);
		dijstra();
		printf("%d\n",dist[t]!=0x3f3f3f3f?dist[t]:-1);
	}
	return 0;
}