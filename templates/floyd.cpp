#include<stdio.h>
#include<vector>
#include<algorithm>
#define DEBUG
//HDU_1874
std::vector< std::vector<int> > dp;
int n,m,s,t;
void floyd(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dp[i][k]!=0x3f3f3f3f&&dp[k][j]!=0x3f3f3f3f){
					dp[i][j]=std::min(dp[i][j],dp[i][k]+dp[k][j]);
				}
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
		dp = std::vector< std::vector<int> >(n+5,std::vector<int>(n+5,0x3f3f3f3f));
		for(int i = 0;i<n;i++){
			dp[i][i]=0;
		}
		for(int i = 0;i<m;i++){
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			if(d<dp[u][v])dp[u][v]=dp[v][u]=d;
		}
		scanf("%d%d",&s,&t);
		floyd();
		printf("%d\n",dp[s][t]!=0x3f3f3f3f?dp[s][t]:-1);
	}
	return 0;
}