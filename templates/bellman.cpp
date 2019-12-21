#include<stdio.h>
#include<queue>
#include<vector>
#define DEBUG
//LUOGU_P3385
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
std::vector<bool> inq;
std::vector<int> cnt;
int n,m,s,t;
bool bellmanford(){
	std::queue<int> q;
	q.push(s);
	inq[s]=true;
	dist[s] = 0;
	while(!q.empty()){
		int next = q.front();q.pop();
		inq[next] = false;
		for(int i = 0;i<map[next].size();i++){
			Edge& e = map[next][i];
			if(dist[next]!=0x3f3f3f3f&&dist[e.next]>dist[next]+e.dist){
				dist[e.next]=dist[next]+e.dist;
				if(!inq[e.next]){
					inq[e.next]=1;
					q.push(e.next);
					cnt[e.next]++;
					if(cnt[e.next]>n)return false;
				}
			}
		}
	}
	return true;
}
int main(){
	#ifndef DEBUG
	freopen("bellman.in","r",stdin);
	//freopen("dijstra.in","r",stdin);
	freopen("bellman.out","w",stdout);
	#endif
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		map.clear();map.resize(n+5);
		dist = std::vector<int>(n+5,0x3f3f3f3f);
		inq.clear();inq.resize(n+5);
		cnt.clear();cnt.resize(n+5);
		for(int i = 0;i<m;i++){
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			map[u].push_back(Edge(d,v));
			if(d>=0)map[v].push_back(Edge(d,u));
		}
		s=1;
		if(!bellmanford()){
			printf("YE5\n");
		}else{
			printf("N0\n");
		}
	}
	return 0;
}
	