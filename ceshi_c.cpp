#include<stdio.h>
#include<string.h>
bool map[10][10];
bool a[10];
int n,k;
int tot = 0;
void dfs(int x,int y){
    if(y == k){
        tot++;
        return;
    }
    for(int i = x;i<n;i++){
        for(int j = 0;j<n;j++){
            if(!map[i][j]){
                continue;
            }
            if(a[j]){
                continue;
            }
            a[j] = 1;
            dfs(i+1,y+1);
            a[j] = 0;
        }
    }
}
int main(){
    while(~scanf("%d%d",&n,&k) && ~n && ~k){
        tot = 0;
        memset(a,0,sizeof(a));
        char s[10];
        for(int i = 0;i<n;i++){
            scanf("%s",s);
            for(int j = 0;j<n;j++){
                if(s[j] == '#'){
                    map[i][j] = 1;
                }else{
                    map[i][j] = 0;
                }
            }
        }
        dfs(0,0);
        printf("%d\n",tot);
    }
    return 0;
}