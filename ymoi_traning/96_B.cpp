#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
using std::vector;
#include<utility>
typedef std::pair<int,int> pii;
using std::make_pair;
using std::map;
int tot=0;
struct Bcj{
    int* f;
    Bcj(int n){
        f=(int*)malloc((n+1)*sizeof(int));
    }
    ~Bcj(){
        free(f);
    }
    int find(int x){
        return f[x]==x?x:f[x]=find(f[x]);
    }
    void update(int x,int y){
        f[find(x)]=find(y);
    }
};
map<int,int> s;
inline int id(int i){
    if(!s[i]){
        return s[i]=++tot;
    }
    return s[i];
}
int main(){
    int cas;scanf("%d",&cas);
    bool flag;
    Bcj bcj(4*10e6);
    while(cas--){
        s.clear();tot=0;
        flag=false;
        int n;scanf("%d",&n);
        vector<pii> a1,a0;
        a1.reserve(n),a0.reserve(n);
        for(int k=1;k<=n;k++){
            int i,j,e;scanf("%d%d%d",&i,&j,&e);
            if(flag)continue;
            i=id(i),j=id(j);
            if(e==1){
                a1.push_back(make_pair(i,j));
            }else if(e==0){
                a0.push_back(make_pair(i,j));
            }
        }
        for(int i=0;i<=tot;i++){
            bcj.f[i]=i;
        }
        for(int i=0;i<a1.size();i++){
            bcj.update(a1[i].first,a1[i].second);
        }
        for(int i=0;i<a0.size();i++){
            if(bcj.find(a0[i].first)==bcj.find(a0[i].second)){
                printf("NO\n");
                goto next;
            }
        }
        printf("YES\n");
        next:;
    }
    return 0;
}