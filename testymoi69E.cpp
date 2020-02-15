#include<iostream>
#include<cstring>
using namespace std;
int main(){
    long dp[201]={0},a[201],pre[201]={0};
    bool mp[201][201]={0};
    long i,j,n,x,y,l,k,maxx;
    memset(dp,0,sizeof(dp));
    memset(pre,0,sizeof(pre));
    memset(mp,false,sizeof(mp));
    cin>>n;
    for (i=1;i<=n;i++)
     cin>>a[i];                                //输入每个地窖中的地雷数
    do{
       cin>>x>>y;                               //表示从X可到Y
       if ((x!=0)&&(y!=0)) mp[x][y]=true;
    }while ((x!=0)||(y!=0));

    dp[n]=a[n];                                 //从后F[n]往前逐个找出所有的F[i]
    for (i=n-1;i>=1;i--){
        l=0;k=0;
        for (j=i+1;j<=n;j++)
        if ((mp[i][j])&&(dp[j]>l)){
            l=dp[j];
            k=j;
        }
        dp[i]=l+a[i];                             //保存从第i个地窖起能挖到最大地雷数
        pre[i]=k;                                  //k地窖是i地窖最优路径
    }
    k=1;
    for (j=2;j<=n;j++)                        //计算最多挖出的地雷数
        if (dp[j]>dp[k])
            k=j;
    maxx=dp[k];
    cout<<k;
    k=pre[k];
     while (k!=0){                              //输出挖地雷的顺序
        cout<<"-"<<k;
        k=pre[k];
    } 
    cout<<endl;
    cout<<maxx<<endl;                          //输出最多挖出的地雷数
}
