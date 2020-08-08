#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
using std::lower_bound;
int lis(vector<int>& a){
    vector<int> b;
    b.reserve(a.size());
    b.push_back(a[0]);
    int ans = 0;
    for(int i=1;i<a.size();i++){
        if(a[i]>b[ans]){
            ans++;
            b.push_back(a[i]);
        }else{
            *lower_bound(b.begin(),b.end(),a[i]) = a[i];
        }
    }
    return ans+1;
}
int main(){
    vector<int> a;
    a.reserve(1004);
    int k;
    while(~scanf("%d",&k)){
        a.push_back(k);
    }
    printf("%d\n",lis(a));
}