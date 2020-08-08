#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<utility>
typedef std::pair<int,int> pii;
using std::make_pair;
using std::max;
using std::min;
using std::sort;
pii a[15005];
int n,l;
int main(){
    int cas;scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&n,&l);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a[i].first,&a[i].second);
        }

        //区间覆盖模板
        sort(a+1,a+n+1);
        int covered = 0;
        int next_cover = 0;
        int ans=0;
        for(int i=1;i<=n;i++){
            while(a[i].first<=covered && i<=n){
                next_cover = max(next_cover,a[i].second);
                i++;
            }
            if(next_cover > covered){
                ans++;
                i--;
                covered = next_cover;
                if(next_cover >= l){
                    break;
                }
            }else{
                break;
            }
        }
        if(covered>=l){
            printf("%d\n",ans);
        }else{
            printf("-1\n");
        }
    }
    return 0;
}