#include<cstdio>
#include<cstdlib>
#include<stack>
using std::stack;
int* a;
int main(){
    int n;scanf("%d",&n);
    a=(int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    int ans=0;
    stack<int> st;
    for(int i=n;i>=1;i--){
        while((!st.empty())&&a[i]>a[st.top()])st.pop();
        ans+=st.size();
        st.push(i);
    }
    printf("%d\n",ans);
    return 0;
}