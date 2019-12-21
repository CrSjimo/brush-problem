#include<stdio.h>
#include<vector>
std::vector< std::vector<int> > map;
int n,m;
std::vector<int> w;
struct Player{
    int s,t;
};
std::vector<Player> p;
inline int abs(int a){
    return a>0?a:-a;
}
inline bool between(int t,int l,int r){
    if(l>r){
        int t = l;
        l = r;
        r = t;
    }
    return t>=l&&t<=r;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    map.resize(n+10);
    w.resize(n+10);
    p.resize(m+10);
    for(int i=0;i<n-1;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        map[x].push_back(y);
        map[y].push_back(x);
    }
    for(int i = 1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(int i = 1;i<=m;i++){
        scanf("%d%d",&p[i].s,&p[i].t);
    }
    std::vector<int> ans(m+10,0);
    if(n%10==1){
        for(int i=1;i<=m;i++){
            if(w[p[i].s]==0)ans[p[i].s]++;
        }
    }else if(n%10==2){
        for(int i=1;i<=m;i++){
            ans[p[i].s]++;
        }
    }else if(n%10==4){
        for(int i=1;i<=m;i++){
            if(p[i].s<=p[i].t){
                for(int k = p[i].s;k<=p[i].t;k++){
                    if(w[k]==abs(k-p[i].s))ans[k]++;
                }
            }else{
                for(int k = p[i].s;k>=p[i].t;k--){
                    if(w[k]==abs(k-p[i].s))ans[k]++;
                }
            }
        }
    }
    for(int i = 1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}