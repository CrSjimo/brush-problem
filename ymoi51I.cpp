#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using std::cin;
using std::cout;
using std::string;
using std::stack;
using std::reverse;

const int INF = 0x3f3f3f3f;

inline int prio(char op){
    if(op == '+' || op == '-')return 1;
    if(op == '*' || op == '/')return 2;
    if(op == '^')return 3;
    return INF;
}

string f(int& i,string& s){
    char nowop = s[i++];
    int nowprio = prio(nowop);
    if(nowprio == INF)return string({s[i-1],0});
    char rop = s[i];
    int rprio = prio(rop);
    string r = f(i,s);
    char lop = s[i];
    int lprio = prio(lop);
    string l = f(i,s);
    if(lprio<nowprio)l="("+l+")";
    if(rprio<nowprio || ((nowop=='-'||nowop=='/')&&rprio == nowprio))r="("+r+")";
    return l+string({nowop,0})+r;
}

int main(){
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int p = 1;
    cout<<f(p,s)<<"\n";
    return 0;
}