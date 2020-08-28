#include<cstdio>
#include<cstdlib>
#include<cstring>
const int MAXN = 1e3+7;
char s[MAXN],t[MAXN];
int next[MAXN];
int n,m;
void init(){
    next[0]=-1;next[1]=0;
    for(int i=2;i<=m;i++){
        int j=next[i-1];
        while(j!=-1&&t[i]!=t[j+1]){
            j=next[j];
        }
        next[i]=j+1;
    }
}
int find(){
    int ans=0;
    for(int i=1,j=0;i<=n;i++){
        while(j!=-1&&s[i]!=t[j+1])j=next[j];
        j++;
        if(j==m){
            ans++;
            j=0;
        }
    }
    return ans;
}
int main(){
    while(scanf("%s",s+1)){
        if(s[1]=='#'&&s[2]==0)return 0;
        scanf("%s",t+1);
        n=strlen(s+1);m=strlen(t+1);
        memset(next,0,sizeof(next));
        init();
        printf("%d\n",find());
    };
    return 0;
}