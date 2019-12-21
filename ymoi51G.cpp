#include<stdio.h>
#include<stack>
#include<string>
#include<iostream>
#include<vector>
struct Node{
    bool t;
    int v;
};
#include<map>
typedef std::vector<Node> exp;
std::map<char,int> prio;
exp convert(exp a){
    exp b;
    std::stack<Node> stack;
    for(int i=0;i<a.size();i++){
        if(a[i].t)b.push_back(a[i]);
        else{
            if(a[i].v=='('){
                stack.push(a[i]);
            }
            if(a[i].v==')'){
                while(!stack.empty() && stack.top().v!='('){
                    b.push_back(stack.top());
                    stack.pop();
                }
            }else{
                while(!stack.empty() && prio[stack.top().v]>=prio[a[i].v]){
                    b.push_back(stack.top());
                    stack.pop();
                }
            }
            stack.push(a[i]);
        }
    }
    return b;
}
exp str2exp(std::string& s){
    std::string tmp="";
    for(int i=0;i<s.size();i++){
        
    }
}
int main(){
    prio['(']=-1;
    prio['+']=1;
    prio['-']=1;
    prio['*']=2;
    prio['/']=2;
    std::string s;
    std::cin>>s;

}