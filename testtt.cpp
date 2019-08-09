#include<stdio.h>
#define MAXN 1<<20
int max(int a,int b){
    return a>b?a:b;
}
int a[MAXN];
int n;
int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",a+i);
    }
    a[n] = -2147483648;
    int ans = -1;
    int t = 1;
    for(int i = 0;i<n;i++){
        if(a[i]<a[i+1])t++;
        else{
            ans = max(ans,t);
            t = 1;
        }
    }
    printf("%d\n",ans);
    return 0;
}