#include<cstdio>
#include<cstdlib>
#include<stack>
using std::stack;

char s[256];
int f[256];

bool check(int l,int r){
    stack<bool> st;
    for(int i=l;i<=r;i++){
        if(s[i]=='('){
            st.push(1);
        }else{
            if(st.empty())return false;
            st.pop();
        }
    }
    return st.empty();
}

int main(){
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w",stdout);
    int n;scanf("%d",&n);
    scanf("%s",s+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int l=1;l<=i;l++){
            for(int r=l;r<=i;r++){
                f[i]+=check(l,r);
            }
        }
        // printf("test: %d %d\n",i,f[i]);
        ans^=i*f[i];
    }
    printf("%d\n",ans);
    return 0;
}