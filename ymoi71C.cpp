#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<algorithm>
using std::max;
using std::string;
using std::cin;
using std::cout;
typedef long long ll;
ll dp[50][50];
ll a[50][50];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    string s;
    cin>>s;
    s="a"+s;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            a[i][j]=atoll(s.substr(i,j-i+1).c_str());
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=a[1][i];
    }
    for(int k=1;k<=m;k++){
        for(int j=k+1;j<=n;j++){
            for(int i=k;i<j;i++){
                dp[j][k]=max(dp[i][k-1]*a[i+1][j],dp[j][k]);
            }
        }
    }
    printf("%lld\n",dp[n][m]);
}