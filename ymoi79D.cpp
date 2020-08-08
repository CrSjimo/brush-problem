/*
title: 智力大冲浪
category: 贪心
*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::sort;
struct Node{
    int time;
    int bonus;
    bool operator<(const Node& nd)const{
        if(bonus == nd.bonus){
            return time>nd.time;
        }
        return bonus>nd.bonus;
    }
}a[505];
int n,tot;
bool used[505];
bool time_occupied[505];
int main(){
    scanf("%d%d",&tot,&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].time);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].bonus);
    }
    //贪心策略：以bonus为第一关键字，time为第二关键字从大到小排序。
    //遍历之。对于每一项活动i，找到其截止时间最近的未被占用的时段来使用
    //如果找不到截止时间前的未占用时段，则不能够进行。
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=a[i].time;j>=1;j--){
            if(!time_occupied[j]){
                time_occupied[j]=1;
                used[i]=1;
                goto next;
            }
        }
        tot-=a[i].bonus;
        next:;
    }
    printf("%d\n",tot);
    return 0;
}