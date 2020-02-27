#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int ans=0;
int trie[40000][30];
inline void add(const string& s){
    int j=0;
    for(int i=0;i<s.size();i++){
        int u=s[i]-'A';
        if(!trie[j][u])trie[j][u]=++ans;
        j=trie[j][u];
    }
}
int main(){
    string s;
    while(cin>>s){
        add(s);
    }
    printf("%d\n",ans+1);
    return 0;
}