#include<stdio.h>
//long long jiecheng[30] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000};
int main(){
    int k;
    scanf("%d",&k);
    double ans = 0;
    int i = 0;
    for(;ans<=k;){
        i++;
        ans+=1.0/i;
    }
    printf("%d\n",i);
    return 0;
}