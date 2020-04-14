#include<vector>
using std::vector;
vector< vector<int> > G;
bool* found;
int* link;
bool hungary(int u){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!found[v]){
            found[v]=true;
            if(!link[v]||hungary(link[v])){
                link[v]=u;
                return true;
            }
        }
    }
    return false;
}