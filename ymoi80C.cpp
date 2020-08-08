/*
title: 小木棍
source: POJ1011
category: DFS
*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<cstring>
using std::sort;
using std::greater;
int n;
int a[65];
int tot;
bool used[65];
bool dfs(int i,int l_rem,int l){
    if(i==0&&l_rem==0)return true;
    if(l_rem==0)l_rem=l;
    for(int j=1;j<=n;j++){
        if(!used[j] && a[j]<=l_rem){
            used[j]=true;
            if(dfs(i-1,l_rem-a[j],l))return true;
            else {
                used[j]=false;
                if(l_rem==l||a[j]==l_rem)return false;
                while(a[j+1]==a[j])j++;
            }
        }
    }
    return false;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        tot+=a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    for(int l=a[1];l<=tot/2;l++){
        if(tot%l)continue;
        memset(used,0,sizeof(used));
        if(dfs(n,l,l)){
            printf("%d\n",l);
            return 0;
        }
    }
    printf("%d\n",tot);
    return 0;
}