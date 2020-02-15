#include<cstdio>
#include<cstdlib>
#include<cstring>
char* s;
int n,step=0;
int p;
inline void move(int i){
    s[p] = s[i];
    s[i] = '-';
    s[p+1] = s[i+1];
    s[i+1] = '-';
    p=i;
    printf("step%2d:%s\n",step++,s+1);
}
void dfs(int i){
    if(i==4){
        move(4);
        move(8);
        move(2);
        move(7);
        move(1);
    }else{
        move(i);
        move(2*i-1);
        dfs(i-1);
    }
}
int main(){
    int n;scanf("%d",&n);
    s = (char*)malloc((2*n+5)*sizeof(char));
    memset(s+1,'o',n*sizeof(char));
    memset(s+n+1,'*',n*sizeof(char));
    s[2*n+1] = s[2*n+2] = '-';
    p = 2*n+1;
    printf("step%2d:%s\n",step++,s+1);
    dfs(n);
    return 0;
}