#include<cstdio>
#include<cstdlib>
#include<queue>
using std::priority_queue;
using std::vector;
inline int calc(int x,int a,int b,int c){
    return a*x*x+b*x+c;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    priority_queue<int> hp;
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    for(int x=1;x<=m;x++){
        hp.push(calc(x,a,b,c));
    }
    for(int i=2;i<=n;i++){
        scanf("%d%d%d",&a,&b,&c);
        for(int x=1;x<=m;x++){
            int y=calc(x,a,b,c);
            if(y<hp.top()){
                hp.pop();
                hp.push(y);
            }
        }
    }
    vector<int> st;st.reserve(m+5);
    while(!hp.empty()){
        st.push_back(hp.top());hp.pop();
    }
    while(!st.empty()){
        printf("%d ",st.back());st.pop_back();
    }
    printf("\n");
    return 0;
}