#include<stdio.h>
#include<algorithm>
using namespace std;
int tid[1000005];
bool has[1000005];
int n,v;
inline bool jumpout(int j,int i,int v,int op){
	if(op==1)return j<=i+v;
	else return j>=i-v;
}
int maxt=-1;
int dfs(int i,int t){
	if(t>maxt)return 0;
	int ans = 0;
	if(has[t]&&(tid[t]>=i-v||tid[t]<=i+v)){
		ans=dfs(tid[t],t+1)+1;
	}else{
		ans=dfs(i,t+1);
	}
	return ans;
}
int list[100010];
int main(){
	//freopen("fight.in","r",stdin);
	//freopen("fight.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		int x,t;
		maxt=max(t,maxt);
		scanf("%d%d",&x,&t);
		tid[t]=x;
		has[t]=1;
		list[i]=x;
	}
	scanf("%d",&v);
	printf("%d",dfs(0,0));
	return 0;
}
