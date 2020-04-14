#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
vector<int> a;
bool* vis;
int t;
void dfs(int u){
    for(int i=0;i<2;i++){
        int v=(u<<1)|i;
        if(!vis[v]){
            vis[v]=1;
            dfs(v&t);
            a.push_back(v);
        }
    }
}
int main(){
    int k;scanf("%d",&k);
    int m=1<<k;
    t=(1<<(k-1))-1;
    printf("%d ",m);
    a.reserve(m+4);
    vis=(bool*)calloc(m+4,sizeof(bool));
    dfs(0);
    for(int i=0;i<k;i++){
        printf("%d",(a.back()&(1<<i)));
    }
    a.pop_back();
    while(a.size()>=k){
        printf("%d",a.back()&1);
        a.pop_back();
    }
    printf("\n");
    return 0;
}