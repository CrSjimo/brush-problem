#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
#include<functional>
#include<algorithm>
using namespace std;
//#define DEBUG
vector< priority_queue< int,vector<int>,greater<int> > > map;
vector< pair<int,int> > list;
vector<int> ans;
vector<int> best;
bool operator<(vector<int>& a,vector<int>& b){
    int i=0;
    for(;i<a.size()&&a[i]==b[i];i++){
        
    }
    return a[i]<b[i];
}
vector<bool> vis;
void dfs(int i){
    ans.push_back(i);
    while(!map[i].empty()){
        int next = map[i].top();
        map[i].pop();
        if(vis[next])continue;
        //ans.push_back(next);
        vis[i]=1;
        dfs(next);
    }
}
bool flag = true;
bool dfs2(int i){
    #ifdef DEBUG
    printf("Testcmp:%d %d\n",i,best[ans.size()]);
    #endif
    if(i<best[ans.size()]){
        flag=true;
    }
    if(!flag&&i>best[ans.size()]){
        return false;
    }
    ans.push_back(i);
    while(!map[i].empty()){
        int next = map[i].top();
        map[i].pop();
        if(vis[next])continue;
        //ans.push_back(next);
        vis[i]=1;
        if(!
        dfs2(next)){
            return false;
        }
    }
    return true;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    map.resize(n+5);
    vis.resize(n+5);
    for(int i=0;i<n+5;i++){
        best.push_back(0x3f3f3f3f);
    }
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        list.push_back(make_pair(x,y));
    }
    if(m==n-1){
        for(int i=0;i<m;i++){
            map[list[i].first].push(list[i].second);
            map[list[i].second].push(list[i].first);
        }
        dfs(1);
        for(int i=0;i<ans.size();i++){
            printf("%d ",ans[i]);
        }
    }else{
        for(int k=0;k<m;k++){
            for(int i=0;i<m;i++){
                if(i==k)continue;
                map[list[i].first].push(list[i].second);
                map[list[i].second].push(list[i].first);
            }
            for(int i=0;i<n;i++){
                if(map[n].empty()){
                    goto nextctn;
                }
            }
            #ifdef DEBUG
            printf("test:liantong\n");
            #endif
            flag=false;
            if(dfs2(1)&&ans.size()==n){
                #ifdef DEBUG
                printf("test:better\n");
                #endif
                best=ans;
                #ifdef DEBUG
                for(int i=0;i<best.size();i++){
                    printf("%d ",best[i]);
                }
                printf("\n");
                #endif
            }
            ans.clear();
            map.clear();
            vis.clear();
            map.resize(n+5);
            vis.resize(n+5);
            //printf("\n");
            nextctn:;
        }
        #ifdef DEBUG
                for(int i=0;i<best.size();i++){
                    printf("%d ",best[i]);
                }
                printf("\n");
                #endif
        for(int i=0;i<best.size();i++){
            printf("%d ",best[i]);
        }
    }
    return 0;
}