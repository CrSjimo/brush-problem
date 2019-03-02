#include <bits/stdc++.h>
using namespace std;
int len[1010];
int main(){
    int n;
    cin>>n;
    int ans=0;
    int a[1010];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int maxlen=0;
        for(int j=1;j<i;j++){
            if(a[j]<a[i])
                maxlen=max(maxlen,len[j]);
        }
        len[i]=maxlen+1;
        ans=max(ans,len[i]);
    }
    cout<<ans;
    return 0;
}