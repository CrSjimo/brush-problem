#include<cstdio>
#include<cstdlib>
#include<vector>

using std::vector;
int n;
char* s;
vector< vector<int> >G;
vector<int> st;
long long* f;
int* g;
long long ans=0;
void dfs(int u){
    for(int i=0;i<G[u].size();i++){
        int top=-1;
        int v=G[u][i];
        if(s[v]=='('){
            st.push_back(u);
        }else{
            if(!st.empty()){
                top=st.back();st.pop_back();
                g[v]=g[top]+1;
            }
        }
        f[v]=f[u]+g[v];
        // fprintf(stderr,"test: %d %c %d %d\n",v,s[v],f[v],g[v]);
        ans^=(long long)v*f[v];
        dfs(v);
        if(st.back()==u)st.pop_back();
        else if(top!=-1)st.push_back(top);
    }
}

signed main(){
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w",stdout);
    scanf("%d",&n);
    s=(char*)malloc((n+2)*sizeof(char));
    f=(long long*)calloc((n+1),sizeof(long long));
    g=(int*)calloc((n+1),sizeof(int));
    G.resize(n+1);
    st.reserve(n+1);
    scanf("%s",s+1);
    for(int v=2;v<=n;v++){
        int u;scanf("%d",&u);
        G[u].push_back(v);
    }
    G[0].push_back(1);
    dfs(0);
    printf("%lld\n",ans);
    return 0;
}