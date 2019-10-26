#include<stdio.h>
int a[1000010],flag,n;
int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",a+i);
    }
    flag = a[2]>=a[1];
    int cnt = 0;
    cnt++;
    for(int i = 1;i<=n;i++){
        if((!flag)&&i==n){
            cnt++;
            break;
        }
        if((flag&&a[i+1]<a[i])||((!flag)&&a[i+1]>a[i])){
            cnt++;flag = !flag;}
    }
    printf("%d\n",cnt);
    return 0;
}