#include<cstdio>
#include<cstdlib>
#include<vector>
#include<stack>
using std::vector;
#define queue std::stack
#define front top
vector< vector<int> >G;
int* ind;
int n;
void bfs(){
    queue<int> q;
        for(int i=1;i<=n;i++){
        if(!ind[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        printf("%d ",u);
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(--ind[v]==0){
                q.push(v);
            }
        }
    }
    printf("\n");
}
int main(){
    scanf("%d",&n);
    G.resize(n+1);
    ind=(int*)calloc((n+1),sizeof(int));
    for(int i=1;i<=n;i++){
        int v;
        while(~scanf("%d",&v)&&v){
            G[i].push_back(v);
            ind[v]++;
        }
    }
    bfs();
    return 0;
}/*
5
0
4 5 1 0
1 0
5 3 0
3 0
*/