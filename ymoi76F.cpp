#include<cstdio>
#include<cstdlib>
#include<vector>
#include<utility>
#include<algorithm>
using std::sort;
using std::pair;
using std::make_pair;
typedef pair<int,int> pii;
using std::vector;
int* w;
vector< vector<int> > G;
bool* vis;
struct CC{
    vector<int> nodes;
    pii p;
};
vector<CC> cclist;
void dfs(int u,CC& cc){
    cc.p.first+=w[u];
    cc.p.second++;
    cc.nodes.push_back(u);
    vis[u]=true;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(vis[v])continue;
        dfs(v,cc);
    }
}
int main(){
    int n;scanf("%d",&n);
    G.resize(n+1);
    vis=(bool*)calloc(n+1,sizeof(bool));
    w=(int*)malloc((n+1)*sizeof(int));
    cclist.resize(n+1);
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);w[i]=k;
    }
    int m;scanf("%d",&m);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    int cnt=0;
    CC* max_w_cc=NULL;
    CC* max_num_cc=NULL;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            CC& cc=cclist[++cnt];
            dfs(i,cc);
            if(max_w_cc==NULL||cc.p.first>max_w_cc->p.first){
                max_w_cc = &cc;
            }
            if(max_num_cc==NULL||cc.p.second>max_num_cc->p.second){
                max_num_cc = &cc;
            }
        }
    }
    sort(max_num_cc->nodes.begin(),max_num_cc->nodes.end());
    for(int i=0;i<max_num_cc->nodes.size();i++){
        printf("%d ",max_num_cc->nodes[i]);
    }
    printf("\n");
    sort(max_w_cc->nodes.begin(),max_w_cc->nodes.end());
    for(int i=0;i<max_w_cc->nodes.size();i++){
        printf("%d ",max_w_cc->nodes[i]);
    }
    printf("\n");
    return 0;
}