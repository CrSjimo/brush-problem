/*
title: 喷水装置
category: 区间覆盖问题
*/
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<utility>
typedef std::pair<double,double> pdd;
using std::make_pair;
using std::max;
using std::min;
using std::sort;
pdd a[15005];
int n,l,w;
pdd calc_range(int p,int r){
    double k = sqrt(pow(r,2)-pow(w,2)/4);
    return make_pair(max(p-k,0.0),min(p+k,l*1.0));
}
int main(){
    int cas;scanf("%d",&cas);
    while(cas--){
        scanf("%d%d%d",&n,&l,&w);
        for(int i=1;i<=n;i++){
            int p,r;
            scanf("%d%d",&p,&r);
            if(r<w/2.0){
                i--;n--;
                continue;
            }
            a[i] = calc_range(p,r);
        }

        //区间覆盖模板
        sort(a+1,a+n+1);
        double covered = 0;
        double next_cover = 0;
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