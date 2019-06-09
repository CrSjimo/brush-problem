#include<cstdio>
using namespace std;
int a[500];
int b[500];
int n,m;
int used[500];
int dp[50][50][50][50];
int num[10];
int max(int a,int b){
    return a>b?a:b;
}
int dfs(int i){
    if(i>n)return 0;
    int maxn = 0;
    for(int j = 1;j<=m;j++){
        if(used[j])continue;
        used[j] = 1;
        int cans = dfs(i+b[j]);
        used[j] = 0;
        maxn = max(maxn,cans);
    }
    return a[i]+maxn;
}
int main(){
    //freopen("./tmp/b_in.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i = 1;i<=m;i++){
        scanf("%d",b+i);
        num[b[i]]++;
    }
    dp[0][0][0][0] = a[1];
    if(n<=-100 && m<=-100)printf("%d\n",dfs(1));
    //FUCK THOSE DP
    else{
        for(int i1 = 0;i1<=num[1];i1++){
            for(int i2 = 0;i2<=num[2];i2++){
                for(int i3 = 0;i3<=num[3];i3++){
                    for(int i4 = 0;i4<=num[4];i4++){
                        int step = i1 + i2*2 +i3*3+i4*4+1;
                        if(i1)dp[i1][i2][i3][i4] = max(dp[i1-1][i2][i3][i4]+a[step],dp[i1][i2][i3][i4]);
                        if(i2)dp[i1][i2][i3][i4] = max(dp[i1][i2-1][i3][i4]+a[step],dp[i1][i2][i3][i4]);
                        if(i3)dp[i1][i2][i3][i4] = max(dp[i1][i2][i3-1][i4]+a[step],dp[i1][i2][i3][i4]);
                        if(i4)dp[i1][i2][i3][i4] = max(dp[i1][i2][i3][i4-1]+a[step],dp[i1][i2][i3][i4]);
                    }
                }
            }
        }
        printf("%d\n",dp[num[1]][num[2]][num[3]][num[4]]);
    }
    return 0;
}