#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;
string sm,sf;
//f:zx,m:qx
int maxn=0;
int a[130];
int dfs(int lm,int rm,int lf,int rf,int i){
    // if(lm>rm)return;
    int u=sf.find(sm[lm]);
    maxn=max(maxn,i);
    int ans=0;
    if(u>lf)ans+=dfs(lm+1,lm+u-lf,lf,u-1,i+1);
    if(u<rf)ans+=dfs(lm+u-lf+1,rm,u+1,rf,i+1);
    if(ans==0)ans=1;
    a[sm[lm]]=ans;
    return ans;
}

int main(){
    cin>>sm;
    cin>>sf;
    dfs(0,sm.size()-1,0,sf.size()-1,0);
    for(int i=0;i<sm.size();i++){
        for(int j=0;j<a[sm[i]];j++){
            printf("%c",sm[i]);
        }
        printf("\n");
    }
    return 0;
}