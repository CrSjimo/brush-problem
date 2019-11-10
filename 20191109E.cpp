#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector< vector<int> > map;
vector< vector<int> > revmap;
bool pre_inPth[10010];
int n,m,s,t;
void dfs(int k){
    pre_inPth[k]=1;
    for(int i=0;i<revmap[k].size();i++){
        if(pre_inPth[revmap[k][i]])continue;
        dfs(revmap[k][i]);
    }
}
bool inPth[10010];
void judge(){
    for(int k=1;k<=n;k++){
        if(pre_inPth[k]){
            inPth[k]=1;
            for(int i = 0;i<map[k].size();i++){
                if(!pre_inPth[map[k][i]]){
                    inPth[k]=0;
                    break;
                }
            }
        }
    }
}
struct Node{
    int id;
    int dist;
};
bool vis[10010];
int bfs(){
    queue<Node> q;
    Node st;
    st.id = s;
    st.dist = 0;
    q.push(st);
    while(!q.empty()){
        Node tmp = q.front();
        q.pop();
        if(tmp.id==t){
            return tmp.dist;
        }
        for(int i=0;i<map[tmp.id].size();i++){
            if(!inPth[map[tmp.id][i]])continue;
            if(vis[map[tmp.id][i]])continue;
            Node nxtnode;
            nxtnode.id = map[tmp.id][i];
            nxtnode.dist = tmp.dist+1;
            q.push(nxtnode);
        }
    }
    return -1;
}
int main(){
    scanf("%d%d",&n,&m);
    map.resize(n+10);
    revmap.resize(n+10);
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        map[x].push_back(y);
        revmap[y].push_back(x);
    }
    scanf("%d%d",&s,&t);
    dfs(t);
    judge();
    printf("%d\n",bfs());
    return 0;

}