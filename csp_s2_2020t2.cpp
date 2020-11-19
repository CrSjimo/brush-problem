#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<iostream>
bool no_has[70];
typedef unsigned long long ull;
void _putint(ull k){
	if(k==0)return;
	_putint(k/10);
	putchar('0'+k%10);
}
void putint(ull k){
	if(k==0)putchar('0'),putchar('\n');
	else _putint(k),putchar('\n');
}
ull getint(){
    ull x=0;
    int c = 1919810;
    while(!isdigit(c)){
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}
ull S;
int main(){
    int n,m,c,k;
    scanf("%d%d%d%d",&n,&m,&c,&k);
    if(!n && !m && k==64){
        printf("18446744073709551616\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        ull a = getint();
        S|=a;
    }
    for(int i=1;i<=m;i++){
        int p,q;scanf("%d%d",&p,&q);
        if(((S>>p)&1)==0)no_has[p]=1;
    }
    ull ans = 1;
    for(int i=0;i<k;i++){
        if(!no_has[i])ans<<=1;
    }
    putint(ans-n);
    return 0;
}