#include<stdio.h>
#include<math.h>
int n;
void mov(int sum,int from,int to){
    if(sum == 0){
        return;
    }
    mov(sum-1,from,6-from-to);
    printf("%d:%d -> %d\n",sum,from,to);
    mov(sum-1,6-from-to,to);
}
int main(){
    // freopen("./a.txt","w",stdout);
    while(~scanf("%d",&n)){
    mov(n,1,3);
    printf("%d\n",((int)pow(2,n))-1);}
    return 0;
}