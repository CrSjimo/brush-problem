#include<stdio.h>
#include<string>
#include<vector>
#include<stack>
#include<iostream>
#include<stdlib.h>
struct Node{
    Node(){}
    Node(int t,int v){
        this->t=t;
        this->v=v;
    }
    bool t;
    int v;
};
inline int calc(int c1,int c2,int op){
    if(op=='+')return c1+c2;
    if(op=='-')return c1-c2;
    if(op=='*')return c1*c2;
    if(op=='/')return c1/c2;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::string s;
    std::getline(std::cin,s);
    std::vector<Node> a;
    std::string tmp="";
    for(int i=0;i<s.size();i++){
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            a.push_back(Node(0,(int)s[i]));
        }else if(s[i]==' '){
            a.push_back(Node(1,atoi(tmp.c_str())));
            tmp="";
        }else if(s[i]>='0'||s[i]<='9'){
            tmp+=s[i];
        }
    }
    std::stack<int> stack;
    for(int i=0;i<a.size();i++){
        if(a[i].t)stack.push(a[i].v);
        else{
            int c1 = stack.top();stack.pop();
            int c2 = stack.top();stack.pop();
            stack.push(calc(c2,c1,a[i].v));
        }
    }
    printf("%d\n",stack.top());
    return 0;
}