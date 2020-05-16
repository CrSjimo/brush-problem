#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
using std::vector;
using std::queue;
int* ind;
vector< vector<int> > G;
void poorXed(){
    printf("Poor Xed\n");
    exit(0);
}
int n;
int* f;
int toposort(){
    int ans = 0;
    queue<int> q;
    for(int s=1;s<=n;s++){
        if(!ind[s]){
            q.push(s);
        }
    }
    int i=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        ans+=(f[u]+100);i++;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(!--ind[v]){
                q.push(v);
            }
            f[v]=f[u]+1;
        }
    }
    if(i!=n){
        //printf("test: %d\n",i);
        poorXed();
    }
    return ans;
}
int main(){
    int m;scanf("%d%d",&n,&m);
    G.resize(n+1);
    ind=(int*)calloc(n+1,sizeof(int));
    f=(int*)calloc(n+1,sizeof(int));
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        G[v].push_back(u);
        ind[u]++;
    }
    printf("%d\n",toposort());
    return 0;
}