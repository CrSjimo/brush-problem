#include<cstdio>
#include<cstdlib>
#include<set>
#include<cmath>
using std::set;
set<int> st;
int* a;
int main(){
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    a=(int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        st.insert(a[i]);
    }
    while(m--){
        int l,r;scanf("%d%d",&l,&r);
        int ans=0;
        for(set<int>::iterator p=st.begin();p!=st.end();p++){
            int x=0,y=0;
            for(int i=1;i<=n;i++){
                if(a[i]==*p){
                    if(i<l||i>r){
                        y++;
                    }else{
                        x++;
                    }
                }
            }
            if(x!=0&&abs(x-y)<=k){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}