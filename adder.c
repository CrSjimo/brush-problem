#include<stdio.h>
int a,b;
int x,y;
int main(){
    scanf("%d%d",&a,&b);
    x = a^b;
    y = (a&b)<<1;
    while(y&0x7fffffff){
        int s = x;
        x = x^y;
        y = (s&y)<<1;
    }
    printf("%d\n",x);
    return 0;
}