#include<cstdio>
#include<cstdlib>
int* col;
int n;
bool flag = false;
void dfs(int i){
    if(i>n){
        for(int j=1;j<=n;j++){
            printf("%5d",col[j]);
        }
        printf("\n");
        flag = true;
        return;
    }
    for(int j=1;j<=n;j++){
        for(int k=1;k<i;k++){
            if(j==col[k] || i+j==k+col[k] || i-j==k-col[k]){
                goto not_match;
            }
        }
        col[i]=j;
        dfs(i+1);
        not_match:;
    }
}
int main(){
    scanf("%d",&n);
    col = (int*)malloc((n+1)*sizeof(int));
    dfs(1);
    if(!flag)printf("no solute!\n");
    return 0;
}