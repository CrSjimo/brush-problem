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
    string nowop = s.substr(i++,1);
    int nowprio = prio(nowop[0]);
    if(nowprio == INF)return s.substr(i-1,1);
    string rop = s.substr(i,1);
    int rprio = prio(rop[0]);
    string r = f(i,s);
    string lop = s.substr(i,1);
    int lprio = prio(lop[0]);
    string l = f(i,s);
    if(lprio<nowprio)l="("+l+")";
    if(rprio<nowprio || ((nowop=="-"||nowop=="/")&&rprio == nowprio))r="("+r+")";
    return l+nowop+r;
}

int main(){
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int p = 1;
    cout<<f(p,s)<<"\n";
    return 0;
}