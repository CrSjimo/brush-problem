#include<stdio.h>
#include<stack>
#include<string>
#include<iostream>
int main(){
    std::ios::sync_with_stdio(false);
    std::string s;
    std::cin>>s;
    std::stack<int> stack;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')stack.push(1);
        else if(s[i]=='[')stack.push(2);
        else if(s[i]==')'){
            if(stack.empty())goto wrong;
            if(stack.top()!=1)goto wrong;
            stack.pop();
        }else{
            if(stack.empty())goto wrong;
            if(stack.top()!=2)goto wrong;
            stack.pop();
        }
    }
    if(!stack.empty())goto wrong;
    printf("OK\n");
    return 0;
    wrong:;
    printf("Wrong\n");
    return 0;
}