// #include<stdio.h>
// #include<vector>
// #include<utility>
// typedef std::pair<int,int> node ;
// std::vector<int> maps[1010];
// node maxdist[1010];
// int parent[1010];
// bool operator<(node p1,node p2){
//     if(p1.second == p2.second){
//         return p1.first>p2.first;
//     }
//     return p1.second<p2.second;
// }
// node operator+(node p1,int x){
//     p1.second+=x;
//     return p1;
// }
// int s;
// void dfs0(int s){
//     printf("test:%d\n",s);
//     for(int i = 0;i<maps[s].size();i++){
//         if(maps[s][i]==parent[s])continue;
//         parent[maps[s][i]] = s;
//         dfs0(maps[s][i]);
//     }
// }
// void dfs1(int s){
//     node p;
//     p.first = s;
//     p.second = 0;
//     for(int i = 0;i<maps[s].size();i++){
//         if(maps[s][i] == parent[s])continue;
//         dfs1(maps[s][i]);
//         p = std::max(p,maxdist[maps[s][i]]+1);
//     }
//     maxdist[s] = p;
//     printf("testttt:%d\n",s);
// }
// int up(int d,int cnt){
//     if(d==-1){
//         return cnt;
//     }
//     for(int i = 0;i<maps[d].size();i++){
//         parent[maps[d][i]] = s;
//         maps[s].push_back(maps[d][i]);
//     }
//     return up(parent[d],cnt+1);
// }
// int main(){
//     int n;
//     scanf("%d",&n);
//     int m = n-1;
//     while(m--){
//         int x,y;
//         scanf("%d%d",&x,&y);
//         maps[x].push_back(y);
//         maps[y].push_back(x);
//     }
//     scanf("%d",&s);
//     parent[s] = -1;
//     dfs0(s);
//     dfs1(s);
//     printf("test");
//     int cnt = n-1;
//     while(cnt){
        
//         node maxn;
//         maxn.first = -1;
//         maxn.second = -1;
//         for(int i = 0;i<maps[s].size();i++){
//             maxn = std::max(maxn,maxdist[maps[s][i]]);
//         }
//         printf("%d ",maxn.first);
//         cnt-=up(maxn.first,0);
//     }
// }
#include<stdio.h>
#include<string.h>
#include<utility>
#include<algorithm>
#include<vector>
struct edge{
    int dist;
    int nextId;
    bool vis;
};
typedef std::pair<int,int> pair;
bool cmp(pair p1,pair p2){
    if(p1.second==p2.second){
        return p1.first>p2.first;
    }
    return p1.second<p2.second;
}
pair operator+(pair p1,int x){
    p1.second+=x;
    return p1;
}
pair maxdist[1010];
std::vector<edge> maps[1010];
int dfs0(int s){
    pair maxd = pair(s,0);
    for(int i = 0;i<maps[s].size();i++){
        dfs0(maps[s][i].nextId);
        maxd = std::max(maxdist[maps[s][i].nextId]+1,maxd,cmp);
    }
    maxdist[s] = maxd;
}
int parent[1010];
int n,s;
void up(int d,int pre){
    if(d == s){
        for(int i = 0;i<maps[s].size();i++){
            if(maps[s][i].nextId==pre){
                maps[s][i].vis = 1;
            }
        }
    }
    for(int i = 0;i<maps[d].size();i++){
        if(maps[d][i].nextId!=pre){
            parent[maps[d][i].nextId] = s;
            edge e;
            maps[s].push_back(maps[d][i]);
        }
    }
    up(parent[d],d);
}
int main(){
    // printf("%d",cmp(pair(7,3),pair(8,3)));
    scanf("%d%d",&n,&s);
    parent[s] = -1;
    for(int i = 0;i<n-1;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        edge e;
        e.nextId = y;
        e.vis = 0;
        maps[x].push_back(e);
        parent[y] = x;
    }
    printf("test");
    dfs0(s);
    // for(int i = 1;i<=n;i++){
    //     printf("test %d:%d,%d",i,maxdist[i].first,maxdist[i].second);
    // }
    while(1){
        pair maxd = pair(-1,-1);
        for(int i = 0;i<maps[s].size();i++){
            if(!maps[s][i].vis){
                maxd = std::max(maxd,maxdist[maps[s][i].nextId]);
            }
            
        }
        if(maxd.first!=-1){
            printf("%d ",maxd.first);
            up(parent[maxd.first],maxd.first);
        }else{
            break;
        }
        break;
        
    }
    return 0;
}