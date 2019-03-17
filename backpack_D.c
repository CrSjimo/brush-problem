#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool dp[1005][1005];//一边 i 一边 j 能不能构成三角形
int n,c,m;
int sides[1005];
int calc(int a,int b,int c){
    double p = 1.0*(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c))*100;
}
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",sides+i);
        c+=sides[i];
    }
    //xiangshang quzheng[c/2-1]
    m=c/2-(!(c%2));
    dp[0][0]=1;
    //TODO
    //can do with one d array?
    for(int k=0;k<n;k++){
        for(int i=m;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(dp[i][j]){
                    dp[i+sides[k]][j]=dp[i][j+sides[k]]=true;
                }
            }
        }
    }
    int ans=-1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=i;j++){
            if(dp[i][j]){
                int k=c-i-j;
                if(i+j>k&&i+k>j&&j+k>i)
                    ans=max(ans,calc(i,j,c-i-j));
            }
        }
    }
    printf("%d",ans);
    return 0;
}
