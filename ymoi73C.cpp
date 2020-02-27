#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string sm,sf;

void dfs(int lm,int rm,int lf,int rf){
    if(lm>rm)return;
    int u=sf.find(sm[lm]);
    if(u>lf)dfs(lm+1,lm+u-lf,lf,u-1);
    if(u<rf)dfs(lm+u-lf+1,rm,u+1,rf);
    printf("%c",sm[lm]);
}

int main(){
    cin>>sf;
    cin>>sm;
    dfs(0,sm.size()-1,0,sf.size()-1);
    printf("\n");
    return 0;
}