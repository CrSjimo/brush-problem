#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string szx;
string calcsc(int l,int r,string sc){
    string s="";
    for(int i=0;i<sc.size();i++){
        int pos=szx.find(sc[i]);
        if(pos>=l&&pos<=r)s+=sc[i];
    }
    return s;
}
void dfs(int l,int r,string sc){
    char u=sc[0];
    int m=szx.find(u);
    printf("%c",u);
    if(m>l){
        dfs(l,m-1,calcsc(l,m-1,sc));
    }
    if(m<r){
        dfs(m+1,r,calcsc(m+1,r,sc));
    }
}
int main(){
    string s2;
    cin>>szx>>s2;
    int l,r;
    string sc;
    dfs(0,szx.size()-1,s2);
    printf("\n");
    return 0;
}