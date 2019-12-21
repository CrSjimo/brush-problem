#include<stdio.h>
#include<stack>
#include<string>
#include<iostream>
#include<map>
int main(){
    std::map<char,int> prio;
    prio['{'] = 4;
    prio['['] = 3;
    prio['('] = 2;
    prio['<'] = 1;
    prio['}'] = 8;
    prio[']'] = 7;
    prio[')'] = 6;
    prio['>'] = 5;
    //std::ios::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    while(t--){
        std::string s;
        std::cin>>s;
        std::stack<int> stack;
        for(int i=0;i<s.size();i++){
            int k = prio[s[i]];
            if(k<=4){
                if(stack.empty()||k<=stack.top())stack.push(k);
                else goto wrong;
            }else{
                if(stack.empty())goto wrong;
                if(stack.top()!=k-4)goto wrong;
                stack.pop();
            }
        }
        if(!stack.empty())goto wrong;
        printf("YES\n");
        continue;
        wrong:
        printf("NO\n");
    }
    return 0;
}