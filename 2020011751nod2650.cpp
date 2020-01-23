#include<stdio.h>
#include<vector>
#include<queue>
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
std::vector< std::vector<Edge> > G;
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
		for(int i = 0;i<G[tmp.next].size();i++){
			Edge e = G[tmp.next][i];
			if(dist[e.next]>dist[tmp.next]+e.dist){
				dist[e.next]=dist[tmp.next]+e.dist;
				e.dist = dist[e.next];
				q.push(e);
			}
		}
	}
}
int main(){
    scanf("%d%d",&n,&m);
    G.resize(2*n+5);
    dist=std::vector<int>(2*n+5,0x3f3f3f3f);
    for(int i=0;i<m;i++){
        int x,y,k;
        scanf("%d%d%d",&x,&y,&k);
        G[x].push_back(Edge(k,y));
        G[y].push_back(Edge(k,x));
        G[x].push_back(Edge(k/2,y+n));
        G[y].push_back(Edge(k/2,x+n));
        G[x+n].push_back(Edge(k,y+n));
        G[y+n].push_back(Edge(k,x+n));
    }
    scanf("%d%d",&s,&t);
    dijstra();
    printf("%d\n",std::min(dist[t],dist[t+n]));
    return 0;
}