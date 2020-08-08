#include<cstdio>
#include<cstdlib>
int *w,*v,*dp;
inline int max(int x,int y){return x>y?x:y;}
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    dp=(int*)calloc(m+1,sizeof(int));
    v=(int*)malloc((n+1)*sizeof(int));
    w=(int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",v+i);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",w+i);
    }
    for(int i=1;i<=n;i++){
        for(int j=w[i];j<=m;j++){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    printf("%d\n",dp[m]);
    return 0;
}