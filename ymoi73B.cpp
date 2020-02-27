#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<iostream>
#include<utility>
using std::pair;
using std::make_pair;
using std::string;
using std::cin;
using std::cout;

typedef pair<int,int> pii;
pii G[30];
string s;
void dfs(int& i){
    //printf("t:%d %c\n",i,s[i]);
    int u=s[i]-'A'+1;
    if(s[++i]!='.'){
        G[u].first=s[i]-'A'+1;
        dfs(i);
    }
    if(s[++i]!='.'){
        G[u].second=s[i]-'A'+1;
        dfs(i);
    }
}
void dfs2(int u){
    if(u==0)return;
    dfs2(G[u].first);
    printf("%c",u-1+'A');
    dfs2(G[u].second);
}
void dfs3(int u){
    if(u==0)return;
    dfs3(G[u].first);
    dfs3(G[u].second);
    printf("%c",u-1+'A');
}
int main(){
    cin>>s;
    int i=0;
    dfs(i);
    dfs2(s[0]-'A'+1);
    printf("\n");
    dfs3(s[0]-'A'+1);
    printf("\n");
    return 0;
}