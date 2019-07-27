#include<stdio.h>
#include<algorithm>
int a[510];
int main(){
    int n;
    scanf("%d",&n);
    int cnt = 0;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x%2){
            a[cnt++] = x;
        }
    }
    std::sort(a,a+cnt);
    for(int i = 0;i<cnt-1;i++){
        printf("%d,",a[i]);
    }
    printf("%d\n",a[cnt-1]);
    return 0;
}