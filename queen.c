#include<stdio.h>
#include<stdbool.h>
int num[12];
int anses[12];
int dfs(int i,int n){
    if(i>=n)return 1;
    int ans = 0;
    for(int j = 0;j<n;j++){
        bool isOK = 1;
        for(int k = 0;k<i;k++){
            if(i+j == k+num[k] || i-j == k-num[k] || j == num[k]){
                isOK = 0;
            }
        }
        if(isOK){
            num[i] = j;
            ans+=dfs(i+1,n);
        }
    }
    return ans;
}
int n;

int main(){
    for(int i = 1;i<=10;i++){
        anses[i] = dfs(0,i);
    }
    while(~scanf("%d",&n) && n){
        printf("%d\n",anses[n]);
    }
    return 0;
}
