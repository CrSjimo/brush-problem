#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::max;
#include<vector>
using std::vector;
vector<int> v,w;
int* dp;
int main(){
    int n,m;
    scanf("%d%d",&m,&n);
    dp=(int*)calloc((m+1),sizeof(int));
    for(int i=1;i<=n;i++){
        int vi,wi,si;
        scanf("%d%d%d",&wi,&vi,&si);
        if(si==0)si=m/wi;
        for(int k=1;k<=si;si-=k,k<<=1){
            v.push_back(vi*k);
            w.push_back(wi*k);
        }
        if(si){
            v.push_back(vi*si);
            w.push_back(wi*si);
        }
    }
    for(int i=0;i<v.size();i++){
        for(int j=m;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    printf("%d\n",dp[m]);
    return 0;
}