/*
title: 种树
category: 贪心 区间
*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::sort;
struct Node{
    int l,r,t;
    bool operator<(const Node& nd)const{
        return r<nd.r;
    }
};
Node* a;
bool* used;
int main(){
    int n, m;scanf("%d%d",&n,&m);
    a=(Node*)malloc((m+1)*sizeof(Node));
    used=(bool*)calloc(n+1,sizeof(bool));
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].t);
    }

    /*将区间按照终点从小到大排序。如此，对于编号小的区间，如果从后向前遍历，可以尽可能位于其与其后区间的交集中*/
    sort(a+1,a+m+1);

    int ans=0;
    for(int i=1;i<=m;i++){

        /*判断是否有已经种过树的位置*/
        for(int j=a[i].l;j<=a[i].r&&a[i].t>0;j++){
            if(used[j])a[i].t--;
        }

        /*从后向前，尽可能在交集中种树*/
        for(int j=a[i].r;j>=a[i].l&&a[i].t>0;j--){
            if(!used[j]){
                used[j]=1;
                ans++;
                a[i].t--;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}