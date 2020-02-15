#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>

using std::lower_bound;
using std::upper_bound;
using std::vector;

int main(){
    vector<int> a(1,0);
    int k;
    while(~scanf("%d",&k)){
        a.push_back(k);
    }
    vector<int> b(2);
    b[1]=a[1];
    int ans = 1;
    for(int i=2;i<a.size();i++){
        if(a[i]>b[ans]){
            ans++;
            b.push_back(a[i]);
        }else{
            *lower_bound(b.begin()+1,b.end(),a[i]) = a[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}