#include<cstdio>
#include<cstdlib>
#include<cstring>
const int MAXN = 1e6+7;
char s[MAXN],t[MAXN];
int nex[MAXN];
int n,m;
void init(){
    nex[0]=-1;nex[1]=0;
    for(int i=2;i<=m;i++){
        int j=nex[i-1];
        while(j!=-1&&t[i]!=t[j+1]){
            j=nex[j];
        }
        nex[i]=j+1;
    }
}
char tmp[MAXN];
int top=0;
int jmp[MAXN];
int find(){
    int ans=0;
    for(int i=1,j=0;i<=n;i++){
        tmp[++top]=s[i];
        while(j!=-1&&s[i]!=t[j+1])j=nex[j];
        j++;
        jmp[top]=j;
        if(j==m){
            top-=m;
            j=jmp[top];
        }
    }
    tmp[++top]=0;
}
int main(){
    scanf("%s%s",s+1,t+1);
    n=strlen(s+1);m=strlen(t+1);
    init();
    find();
    printf("%s\n",tmp+1);
    return 0;
}