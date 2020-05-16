#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<vector>
#include<algorithm>
using std::vector;
using std::sort;
using std::max;
struct Bcj{
    int n;
    int* f;
    Bcj(int n){
        this->n=n;
        f=(int*)malloc((n+2)*sizeof(int));
        for(int i=0;i<=n;i++)f[i]=i;
    }
    ~Bcj(){
        free(f);
    }
    int find(int x){
        return f[x]==x?x:f[x]=find(f[x]);
    }
    inline void update(int x,int y){
        f[find(x)]=find(y);
    }
    inline int max_set(){
        for(int i=1;i<=n;i++){
            f[i]=find(i);
        }
        // for(int i=1;i<=n;i++){
        //     printf("test:%d %d\n",i,f[i]);
        // }
        sort(f+1,f+n+1);
        f[n+1]=-1;
        int cnt=0,maxn=0;
        for(int i=1;i<=n;i++){
            if(f[i]==f[i+1])cnt++;
            else{
                cnt++;
                maxn=max(cnt,maxn);
                cnt=0;
            }
        }
        return maxn;
    }
};
vector< vector<int> > G;
int main(){
    int n;scanf("%d",&n);
    G.resize(n+1);
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        while(k--){
            int v;scanf("%d",&v);G[i].push_back(v);
        }
    }
    for(int k=0;k<=n;k++){
        Bcj bcj = Bcj(n);
        for(int u=k+1;u<=n;u++){
            for(int i=0;i<G[u].size();i++){
                int v=G[u][i];
                if(v<=k)continue;
                bcj.update(u,v);
            }
        }
        int mss=bcj.max_set();
        //printf("testmss:%d %d\n",k,mss);
        if(mss<=n/2){
            printf("%d\n",k);
            return 0;
        }
    }
}/*
7
2 2 5
3 1 3 4
2 2 4
2 2 3
3 1 6 7
2 5 7
2 5 6
*/