#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::max;
using std::sort;
using std::max_element;
int dp[105][105];
int ans=0;
int n,m;
int op[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct Node{
    int x,y;
    int w;
    bool operator<(const Node& nd)const{
        return w<nd.w;
    }
}* a;
int w[105][105];
inline bool cando(int i,int j){
    return i>=1&&i<=n&&j>=1&&j<=m;
}
int main(){
    scanf("%d%d",&n,&m);
    a=(Node*)malloc((n*m+1)*sizeof(int*));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[(i-1)*m+j].w);
            a[(i-1)*m+j].x=i;
            a[(i-1)*m+j].y=j;
            w[i][j]=a[(i-1)*m+j].w;
            dp[i][j]=1;
        }
    }
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        for(int k=0;k<4;k++){
            int nx=a[i].x+op[k][0];
            int ny=a[i].y+op[k][1];
            if(cando(nx,ny)&&w[nx][ny]>a[i].w){
                dp[nx][ny]=max(dp[nx][ny],dp[a[i].x][a[i].y]+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,*max_element(dp[i]+1,dp[i]+m+1));
    }
    printf("%d\n",ans);
    return 0;
}