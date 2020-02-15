#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
using std::vector;
#include<queue>
using std::queue;
bool* vis1;
bool* visn;
vector< vector<int> > G1,REVG1;
struct Edge{
    int w,v;
    Edge(){};
    Edge(int w,int v){
        this->v=v;
        this->w=w;
    }
};
vector< vector<Edge> > G;
int n,m;
vector<Edge> EL;
void dfs1(int u){
    vis1[u]=1;
    for(int i=0;i<G1[u].size();i++){
        int v = G1[u][i];
        if(!vis1[v])dfs1(v);
    }
}
void dfsn(int u){
    visn[u]=1;
    for(int i=0;i<REVG1[u].size();i++){
        int v = REVG1[u][i];
        if(!visn[v])dfsn(v);
    }
}
int* dis;
int* cnt;
bool* inq;
void spfa(int s){
    std::queue<int> q;
	q.push(s);
	inq[s]=true;
	dis[s] = 0;
	while(!q.empty()){
		int u = q.front();q.pop();
		inq[u] = false;
		for(int i = 0;i<G[u].size();i++){
			Edge& e = G[u][i];
			if(dis[e.v]<dis[u]+e.w){
				dis[e.v]=dis[u]+e.w;
				if(!inq[e.v]){
					inq[e.v]=1;
					q.push(e.v);
					cnt[e.v]++;
					if(cnt[e.v]>n){
                        printf("No\n");
                        exit(0);
                    }
				}
			}
		}
	}
}
int main(){
    scanf("%d%d",&n,&m);
    G1.resize(n+5);REVG1.resize(n+5);G.resize(n+5);EL.resize(m+5);
    vis1 = (bool*)calloc(n+5,sizeof(bool));
    visn = (bool*)calloc(n+5,sizeof(bool));
    dis = (int*)calloc(n+5,sizeof(int));
    inq = (bool*)calloc(n+5,sizeof(bool));
    cnt = (int*)calloc(n+5,sizeof(int));
    memset(dis,-0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        scanf("%d%d",&EL[i].w,&EL[i].v);
        G1[EL[i].w].push_back(EL[i].v);
        REVG1[EL[i].v].push_back(EL[i].w);
    }
    dfs1(1);dfsn(n);
    for(int i=1;i<=m;i++){
        if(vis1[EL[i].w]&&vis1[EL[i].v]&&visn[EL[i].w]&&visn[EL[i].v]){
            G[EL[i].w].push_back(Edge(1,EL[i].v));
            G[EL[i].v].push_back(Edge(-2,EL[i].w));
        }
    }
    spfa(1);
    printf("Yes\n");
    for(int i=1;i<=m;i++){
        if(vis1[EL[i].w]&&vis1[EL[i].v]&&visn[EL[i].w]&&visn[EL[i].v]){
            printf("%d\n",dis[EL[i].v]-dis[EL[i].w]);
        }else{
            printf("1\n");
        }
    }
    return 0;
}