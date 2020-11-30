#include<cstdio>
#include<set>
#include<cstdlib>
using std::multiset;
typedef long long ll;
typedef multiset<int>::iterator sip;
int main(){
    freopen("introduction.in","r",stdin);
    freopen("introduction.out","w",stdout);
    int n,m;scanf("%d%d",&n,&m);
    multiset<int> st;
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        st.insert(k);
    }
    ll cur=0,ans=0;
    for(sip p=st.begin();p!=st.end();p++){
        cur+=*p;
        ans+=cur;
    }
    printf("%lld\n",ans);
    for(int i=1;i<=m;i++){
        int op,k;scanf("%d%d",&op,&k);
        if(op==1){
            st.insert(k);
            cur=ans=0;
            for(sip p=st.begin();p!=st.end();p++){
                cur+=*p;
                ans+=cur;
            }
            printf("%lld\n",ans);
        }else if(op==2){
            st.erase(st.find(k));
            cur=ans=0;
            for(sip p=st.begin();p!=st.end();p++){
                cur+=*p;
                ans+=cur;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}