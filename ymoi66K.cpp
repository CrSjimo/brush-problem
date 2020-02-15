#include<cstdio>
#include<vector>
using std::vector;
using std::max;
using std::min;
#include<utility>
using std::pair;
using std::make_pair;
typedef pair<int,int> pii;
#include<algorithm>
using std::sort;
#include<cmath>
inline int dist2(pii p1,pii p2){
    return pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2);
}
pii p1,p2;
bool cmp(pii pa,pii pb){
    return dist2(p1,pa)<dist2(p1,pb);
}
int main(){
    scanf("%d%d%d%d",&p1.first,&p1.second,&p2.first,&p2.second);
    int n;
    scanf("%d",&n);
    vector<pii> a(n+2);
    for(int i =1;i<=n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    a[n+1]=p2;
    a[0]=p1;
    sort(a.begin()+1,a.end()-1,cmp);
    int minn = 19260817,max2 = 0;
    for(int i=n+1;i>0;i--){
        max2 = max(max2,dist2(a[i],p2));
        minn = min(minn,max2+dist2(a[i-1],p1));
    }
    printf("%d\n",minn);
    return 0;
}