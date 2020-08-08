#include<cstdio>
void exgcd(int a,int b,int&x,int&y){
    if(b==0){
        x=1;y=0;
    }else{
        int _x,_y;
        exgcd(b,a%b,_x,_y);
        y=_x-(a/b)*_y;
        x=_y;
    }
}
int main(){
    int a,b;scanf("%d%d",&a,&b);
    int x,y;
    exgcd(a,b,x,y);
    printf("%d\n",(x%b+b)%b);
    return 0;
}