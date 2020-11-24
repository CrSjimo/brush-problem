#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
#include<queue>
using std::queue;
const int MAXN=10010;
vector< int > _G[10010];
vector< int > G[10010];
bool in_path[10010];
bool cando[10010];
int dis[10010];
int n,m,s,t;
queue<int> q;
void bfs1(){
	q.push(t);
	in_path[t]=true;
	while(!q.empty()){
		int u=q.front();q.pop();
		//printf("test1: %d\n",u);
		for(int i=0;i<_G[u].size();i++){
			int v=_G[u][i];
			if(!in_path[v]){
				q.push(v);
				in_path[v]=true;
			}
			
		}
	}
}
void judge(){
	for(int u=1;u<=n;u++){
		if(in_path[u]){
			cando[u]=true;
			for(int i=0;i<G[u].size();i++){
				int v=G[u][i];
				if(!in_path[v]){
					cando[u]=false;
					break;
				}
			} 
		}
	}
}

void bfs2(){
	if(!cando[s])return;
	while(!q.empty())q.pop();
	q.push(s);
	dis[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		//printf("test2: %d\n",u);
		if(u==t){
			return;
		}
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(!cando[v])continue;
			if(dis[v])continue;
			q.push(v);
			dis[v]=dis[u]+1;
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	//G.resize(n+1);
	//_G.resize(n+1);
	//in_path=(bool*)calloc((n+1),sizeof(bool));
	//cando=(bool*)calloc((n+1),sizeof(bool));
	//dis=(int*)calloc((n+1),sizeof(int));
	while(m--){
		int u,v;scanf("%d%d",&u,&v);
		if(u==v)continue;
		G[u].push_back(v);
		_G[v].push_back(u);
	}
	scanf("%d%d",&s,&t);
	bfs1();
	judge();
	bfs2();
	printf("%d\n",dis[t]-1);
	return 0;
}

