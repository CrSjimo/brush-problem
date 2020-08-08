#include<cstdio>
#include<cctype>
int getint(){
    int x=0,k=1;
    int c = 1919810;
    while(!isdigit(c)){
        c=getchar();
        if(c=='-')k=-1;
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*k;
}
void _putint(int x,bool t){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x==0&&t)return;
    _putint(x/10,1);
    putchar(x%10+'0');
}
void putint(int x){
    _putint(x,0);
}
int main(){
    int n=getint();
    while(n--){
        putint(getint()+1);
        putchar(' ');
    }
    putchar('\n');
    return 0;
}