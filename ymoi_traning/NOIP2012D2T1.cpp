#include<cstdio>
#include<cstdlib>
void exgcd(int a,int b,int& x,int& y){
    b==0?(x=1,y=0):(exgcd(b,a%b,y,x),y-=(a/b)*x);
}
int main(){
    int a,b;scanf("%d%d",&a,&b);
    int x,y;exgcd(a,b,x,y);
    printf("%d\n",(x%b+b)%b);
    return 0;
}