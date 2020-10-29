#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;
const int N=15,L=1<<15,V=21;
int n,m,w[N],v[N],c[N][N];
int f[N][L],g[N][L],t[V];
int main(){
	// freopen("store.in","r",stdin);
	freopen("store.out1","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)scanf("%d",w+i);
	for(int i=0;i<m;++i)scanf("%d",v+i);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%d",&c[i][j]);
	
	int all=(1<<n)-1;
	for(int j=0;j<m;++j)
		for(int S=1;S<=all;++S){
			memset(t,0,sizeof(t));
			for(int i=0;i<n;++i)if(S>>i&1)
				for(int k=w[i];k<=v[j];++k)
					t[k]=max(t[k],t[k-w[i]]+c[i][j]);
			f[j][S]=t[v[j]];
		}
	for(int i=0;i<m;i++){
        for(int S=0;S<=all;S++){
            printf("test: %d %d %d\n",i,S,f[i][S]);
        }
    }
	for(int S=1;S<=all;++S)g[0][S]=f[0][S];
	for(int i=1;i<m;++i)
		for(int S=0;S<=all;++S){
			g[i][S]=max(g[i-1][S],f[i][S]);
			for(int T=S&(S-1);T;T=(T-1)&S)
				g[i][S]=max(g[i][S],g[i-1][T]+f[i][S^T]);
		}
	printf("%d\n",g[m-1][all]);
}
