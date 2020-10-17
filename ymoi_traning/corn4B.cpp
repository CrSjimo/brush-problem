#include<cstdio>
#include<cstdlib>
#include<utility>
#include<functional>
#include<vector>
#include<algorithm>
using std::max;
using std::sort;
using std::vector;
typedef std::pair<int,int> pii;
vector<pii> a;
int main(){
    int n;scanf("%d",&n);
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    sort(a.begin()+1,a.end());
    int maxn=-19260817;
    for(int i=1;i<=n;i++){
        int res=1;
        for(int j=1;j<i;j++){
            if(a[j].second<a[i].second)res++;
        }
        for(int j=i+1;j<=n;j++){
            if(a[j].second<a[i].second)res++;
        }
        maxn=max(maxn,res);
    }
    //wrong program
    printf("%d\n",maxn);
    return 0;
}