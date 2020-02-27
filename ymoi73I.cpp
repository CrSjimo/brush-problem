#include<cstdio>
#include<cstdlib>
#include<stack>
using std::stack;
#include<utility>
using std::pair;
pair<int,int> G[30];
void dfs(int u){
    if(G[u].first)dfs(G[u].first);
    if(G[u].second)dfs(G[u].second);
    printf("%c",u-1+'A');
}
int main(){
    char c;
    stack<char> s;
    char rt=0;
    while(~scanf("%c",&c)&&c!='@'){
        if(s.empty())rt=c;
        if(c!=')'){
            s.push(c);
        }else if(c==')'){
            char u,k1=0,k2=0,comma=0;
            while(s.top()!='('){
                char k=s.top();s.pop();
                if(k==','){
                    comma=k;
                }else if(comma){
                    k1=k;
                }else{
                    k2=k;
                }
            }
            s.pop();
            u=s.top();
            if(k1!=0)G[u-'A'+1].first=k1-'A'+1;
            if(k2!=0)G[u-'A'+1].second=k2-'A'+1;
        }//A(B,C(,E(G,F)))@
    }
    dfs(rt-'A'+1);
    printf("\n");
    return 0;
}