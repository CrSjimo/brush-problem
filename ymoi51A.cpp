#include<stdio.h>
#include<stack>
#include<string>
#include<iostream>
int main(){
    std::ios::sync_with_stdio(false);
    std::string s;
    std::cin>>s;
    std::stack<bool> stack;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')stack.push(true);
        if(s[i]==')'){
            if(stack.empty()){
                printf("NO\n");
                return 0;
            }else{
                stack.pop();
            }
        }
    }
    printf(stack.empty()?"YES\n":"NO\n");
    return 0;
}