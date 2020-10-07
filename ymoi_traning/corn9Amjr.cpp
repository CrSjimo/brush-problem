#include <iostream>
#include <cstdio>

using namespace std;
int n,m,delta,num;
int a[1010][1010];
long long dp[1010][1010];
int x,y,p;
long long sum;

int main()
{
    scanf("%d%d%d%d",&n,&m,&delta,&num);
    for(int i=1;i<=num;i++)
    {
        scanf("%d%d%d",&x,&y,&p);
        a[x][y]=p;
    }
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
        int l=max(0,j-delta);
        int r=min(m-1,j+delta);
        for(int k=l;k<=r;k++)
        dp[j][i]=max(dp[j][i],dp[k][i-1]+a[j][i]);
    }
    for(int i=0;i<n;i++)
    sum=max(dp[i][m-1],sum);
    printf("%lld\n",sum);
    return 0;
}