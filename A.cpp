#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int n;
int m;
int a,b,x;
int s,t;
bool visited[209];
int mdist[209];
int dist[209][209];
int main(){
	while(cin>>n>>m){
		memset(visited,0,sizeof(visited));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j]=1e9;
			}
		}
		for(int i=0;i<n;i++) mdist[i]=1e9;
		for(int i=1;i<=m;i++){
			cin>>a>>b>>x;
			if (dist[a][b] > x){
				dist[a][b]=x;
				dist[b][a]=x;
			}
		}
		cin>>s>>t;
		for(int i=0;i<n;i++){
			mdist[i]=dist[s][i];
		}
		mdist[s] = 0;
		visited[s]=1;
		for(int j=0;j<n;j++){
			int minn=1e9,temp=-1;
			for(int i=0;i<n;i++){
				if(visited[i]==0){
					if(mdist[i]<minn){
						minn=mdist[i];
						temp=i;
					}
				}
			}
			if(temp==-1)break;
			visited[temp]=1;
			for(int i=0;i<n;i++){
				if(dist[temp][i]+mdist[temp]<mdist[i]){
					mdist[i]=dist[temp][i]+mdist[temp];
				}
			}
		}
		if(mdist[t]==1e9)cout<<-1<<endl;
		else cout<<mdist[t]<<endl;
	}
	return 0;
}