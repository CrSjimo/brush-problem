#include<stdio.h>
#include<deque>
typedef std::deque<int> deque;
int main(){
    int n;
    scanf("%d",&n);
    deque ord;
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        ord.push_back(k);
    }
    deque stack;
    for(int i=1;i<=n;i++){
        stack.push_back(i);
        while(!stack.empty() && stack.back() == ord.front()){
            stack.pop_back();
            ord.pop_front();
        }
    }
    printf(stack.empty()?"YES\n":"NO\n");
    return 0;
}