#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e4+10,M=5e5+10,L=16;
struct edge{
	int to,nt,val;
	inline void init(int t,int n,int v){
		to=t,nt=n,val=v;	
	}	
}e[M<<1];
int h[N],c;
int n,m,x,y,z,q;
inline void adde(int x,int y,int z){
	e[++c].init(y,h[x],z),h[x]=c;
	e[++c].init(x,h[y],z),h[y]=c;	
}
struct edge1{
	int x,y,val;
	inline void init(int _x,int _y,int v){
		x=_x,y=_y,val=v;
	}
	inline bool operator<(const edge1& e)const {
		return val>e.val;
	}
}e1[M];
int f[N];
inline void init(){
	for(int i=1;i<=n;++i)f[i]=i;	
}
inline int fnd(int x){
	return f[x]==x?x:f[x]=fnd(f[x]);	
}
inline void merge(int x,int y){
	x=fnd(x),y=fnd(y),f[x]=y;	
}
int dep[N],fa[N][L],mn[N][L];
void dfs(int pos,int pnt=0){
	dep[pos]=dep[pnt]+1;		
	for(int i=h[pos];i;i=e[i].nt){
		int tmp=e[i].to;
		if(tmp==pnt)continue;
		mn[tmp][0]=e[i].val;
		fa[tmp][0]=pos;
		for(int i=0;i+1<L;++i){
			fa[tmp][i+1]=fa[fa[tmp][i]][i];
			mn[tmp][i+1]=min(mn[tmp][i],mn[fa[tmp][i]][i]);
		}
		dfs(tmp,pos);
	}
}
inline int lca(int x,int y){
	int res=0x7fffffff;
	if(dep[x]<dep[y])x^=y^=x^=y;
	for(int i=L-1;i>=0;--i)
		if(dep[fa[x][i]]>=dep[y]){
			res=min(res,mn[x][i]);
			x=fa[x][i];
		}
	if(x==y)return res;
	for(int i=L-1;i>=0;--i)
		if(fa[x][i]!=fa[y][i]){
			res=min(res,min(mn[x][i],mn[y][i]));
			x=fa[x][i],y=fa[y][i];	
		}
	res=min(res,min(mn[x][0],mn[y][0]));
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&z);
		e1[i].init(x,y,z);
	}
	sort(e1+1,e1+m+1);
	init();
	for(int i=1;i<=m;++i){
		if(fnd(e1[i].x)!=fnd(e1[i].y)){
			merge(e1[i].x,e1[i].y);
			adde(e1[i].x,e1[i].y,e1[i].val);
		}
	}
	for(int i=1;i<=n;++i)
		if(!dep[i])dfs(i);
	for(int i=1;i<=n;i++){
		for(int j=0;j<L;j++){
			printf("%d ",mn[i][j]);
		}
		printf("\n");
	}
    for(int i=1;i<=n;i++){
		for(int j=0;j<L;j++){
			printf("%d ",fa[i][j]);
		}
		printf("\n");
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&x,&y);
		if(fnd(x)==fnd(y)){
			// printf("%d\n",lca(x,y));
		}else{
			// printf("%d\n",-1);	
		}
	}
	return 0;
}

