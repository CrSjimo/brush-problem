#include<stdio.h>
#include<stack>
#include<string>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<deque>
#include<math.h>
#include<algorithm>
const int MOD = 10007;
typedef std::pair<int,int> pair;
struct Node{
    Node(){}
    Node(char op){
        this->t=0;
        this->v.op=op;
    }
    Node(pair f){
        this->t=1;
        this->v.f=f;
    }
    bool t;
    struct V{
        char op;
        pair f;
    } v;
};
#include<map>
typedef std::vector<Node> expr;
typedef std::string string;
std::map<char,int> prio;
inline bool is_digit(char c){
    return c>='0'&&c<='9';
}
inline string convNega(string& s){
    string ans = "";
    for(int i=0;i<s.size();i++){
        if(s[i]=='-' && (i==0||(s[i-1]!=')'&&(!is_digit(s[i-1]))))){

            ans+="0-";

        }else{
            ans+=s[i];
        }
    }
    return ans;
}
inline void printExp(expr b){
    for(int i=0;i<b.size();i++){
        printf(b[i].t?"%d ":"%c ",b[i].v);
    }
}
//8-(3+2*6)/5+4
expr convert(expr a){
    expr b;
    std::deque<Node> stack;
    stack.push_back(Node('#'));
    for(int i=0;i<a.size();i++){
        if(a[i].t)b.push_back(a[i]);
        else{
            if(a[i].v.op=='('){
                stack.push_back(a[i]);
            }else if(a[i].v.op==')'){
                while(stack.back().v.op!='('){
                    b.push_back(stack.back());
                    stack.pop_back();
                }
                stack.pop_back();
            }else{
                while(prio[stack.back().v.op]>=prio[a[i].v.op]){
                    b.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(a[i]);
            }

        }
    }
    while(!stack.empty()&&stack.back().v.op!='#'){
        b.push_back(stack.back());
        stack.pop_back();
    }
    return b;
}
expr str2expr(string& s){
    string tmp="";
    expr b;
    for(int i=0;i<s.size();i++){
        if(is_digit(s[i]))tmp+=s[i];
        else{
            if(tmp!=""){
                b.push_back(Node(atoi(tmp.c_str())));
                tmp="";
            }
            b.push_back(Node(s[i]));
        }
    }
    if(tmp!=""){
        b.push_back(Node(atoi(tmp.c_str())));
    }
    return b;
}
inline pair calc(pair c1,pair c2,int op){
    pair p;
    if(op=='+'){
        p.first=(c1.first*c2.first)%MOD;
        p.second=((c1.second*c2.first)%MOD+(c1.first*c2.second)%MOD+(c1.second*c2.second)%MOD)%MOD;
    }else{
        p.second=(c1.second*c2.second)%MOD;
        p.first=((c1.second*c2.first)%MOD+(c1.first*c2.second)%MOD+(c1.first*c2.first)%MOD)%MOD;
    }
    return p;
}
inline char getLeft(std::string& s,int i){
    if(i-1>=0)return s[i-1];
    return ' ';
}
inline char getRight(std::string& s,int i){
    if(i+1<s.size())return s[i+1];
    return ' ';
}
expr toExp(std::string& s){
    expr b;
    int i=0;
    for(;i<s.size();i++){
        char l = getLeft(s,i);
        char r = getRight(s,i);
        if(s[i]=='('||l==')'){
            b.push_back(Node(s[i]));
        }else if(l!=')'){
            b.push_back(Node(std::make_pair(1,1)));
            b.push_back(Node(s[i]));
        }
    }
    if(s[s.size()-1]!=')')b.push_back(Node(std::make_pair(1,1)));
    return b;
}
pair calcExp(expr a){
    std::stack<pair> stack;
    for(int i=0;i<a.size();i++){
        if(a[i].t)stack.push(a[i].v.f);
        else{
            pair c1 = stack.top();stack.pop();
            pair c2 = stack.top();stack.pop();
            stack.push(calc(c2,c1,a[i].v.op));
        }
    }
    return stack.top();
}
int main(){
    int tmp;
    scanf("%d",&tmp);
    prio['#']=-0x3f3f3f3f;
    prio['(']=-1;
    prio['+']=1;
    prio['-']=1;
    prio['*']=2;
    prio['/']=2;
    prio['^']=3;
    std::string s;
    std::cin>>s;
    expr bb = toExp(s);
    expr b = convert(bb);
    printf("%d\n",calcExp(b).first);
    return 0;
}
