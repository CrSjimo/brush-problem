#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<utility>
#include<vector>
using std::vector;
using std::pair;
using std::make_pair;
using std::lower_bound;
using std::sort;
typedef pair<int,int> pii;
pii* a;
int main(){
    int n;scanf("%d",&n);
    a=(pii*)malloc((n+1)*sizeof(pii));
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    sort(a+1,a+n+1);
    vector<int> b(2);
    b[1]=a[1].second;
    int ans = 1;
    for(int i=2;i<=n;i++){
        if(a[i].second>b[ans]){
            ans++;
            b.push_back(a[i].second);
        }else{
            *lower_bound(b.begin()+1,b.end(),a[i].second) = a[i].second;
        }
    }
    printf("%d\n",ans);
    return 0;
}