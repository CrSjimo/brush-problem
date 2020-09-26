#include<cstdio>
#include<cstdlib>
#include<queue>
#include<vector>
#include<cstring>
using std::vector;
using std::queue;
const double EPS = 1e-7;
bool* inq;
int* cnt;
double* dis;
struct Edge{
	int w,v;
	Edge(){}
	Edge(int w,int v){
		this->w=w;
		this->v=v;
	}
};
vector< vector<Edge> >G;
int n;
bool spfa(double delta){
	queue<int> q;
	q.push(1);
	inq[1]=true;
	dis[1]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=false;
		for(int i=0;i<G[u].size();i++){
			Edge& e=G[u][i];
			if(dis[e.v]>dis[u]+e.w-delta){
				dis[e.v]=dis[u]+e.w-delta;
				if(!inq[e.v]){
					q.push(e.v);
					inq[e.v]=true;
					cnt[e.v]++;
					if(cnt[e.v]>n){
						return false;
					}
				}
			}
		}
	}
	return true;
}
inline void reset(){
    memset(dis,0x7f,(n+1)*sizeof(double));
    memset(inq,0,(n+1)*sizeof(double));
    memset(cnt,0,(n+1)*sizeof(int));

}
int binary(double l,double r){
    if(r-l<=EPS){
        return l;
    }
	double m = (l+r)/2.0;
	if(spfa(m)){

    }
	
}
int main(){
    
}
