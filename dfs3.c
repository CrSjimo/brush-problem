#include<stdio.h>
#include<string.h>
int a,b;
int m,n;
char carpet[25][25];
char row[25];
//char trashbin;
int dfs(int a,int b){
    if(carpet[a][b] == '#' || a >= m||b >= n || a < 0 || b < 0)return 0;
    carpet[a][b]='#';
    return 1 + dfs(a,b+1) + dfs(a,b-1) + dfs(a-1,b) + dfs(a+1,b);
}
int main(){
    while(~scanf("%d%d",&n,&m) && m && n){
        
        for(int i = 0;i<m;i++){
            scanf("%s",row);
            for(int j = 0;j<n;j++){
                carpet[i][j] = row[j];
                if(carpet[i][j] == '@'){
                    a = i;
                    b = j;
                }
            }
        }
        printf("%d\n",dfs(a,b));
    }
    return 0;
}