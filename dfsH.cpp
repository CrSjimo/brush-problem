#include<stdio.h>
#include<algorithm>
int a[310];
int cnt[100];
struct Node{
    int st;
    int interval;
    int cnt;
} s[20];

int num = 17;
int n;
bool cando(int st,int interval){
    for(;st<60;st+=interval){
        if(!cnt[st]){
            return 0;
        }
    }
    return 1;
}
bool dfs(int st,int ed){
    
}
int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",a+i);
    }
    dfs(a[0],a[1]);
    printf("%d\n",num);
    return 0;
}