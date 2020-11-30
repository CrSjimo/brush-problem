#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
using std::vector;
typedef long long ll;
ll* dp;
struct Node{
    int w,c;
    Node(){}
    Node(int w,int c){
        this->w=w;
        this->c=c;
    }
};
vector<Node> a;
int max(int a,int b){return a>b?a:b;}
int main(){
    freopen("running.in","r", stdin);
    freopen("running.out","w",stdout);
    int n,m;scanf("%d%d",&n,&m);
    dp=(ll*)calloc((2*m+5),sizeof(ll));
    memset(dp,0xc0,(2*m+5)*sizeof(ll));
    dp+=m+2;
    dp[0]=0;
    if(m<=2e3)a.reserve(8*n);
    else a.reserve(11*n);
    for(int i=1;i<=n;i++){
        int w,c,num;scanf("%d%d%d",&w,&c,&num);
        for(int j=1;j<=num;j<<=1){
            a.push_back(Node(w*j,c*j));
            num-=j;
        }
        if(num>0)a.push_back(Node(w*num,c*num));
    }
    for(int i=0;i<a.size();i++){
        if(a[i].w>=0)for(int j=m;j>=-m+a[i].w;j--){
            dp[j]=max(dp[j],dp[j-a[i].w]+a[i].c);
        }
        else for(int j=-m;j<=m+a[i].w;j++){
            dp[j]=max(dp[j],dp[j-a[i].w]+a[i].c);
        }
    }
    ll maxn=0;
    for(int i=-m;i<=m;i++){
        //fprintf(stderr,"%d %lld\n",i,dp[i]);
        maxn=max(maxn,dp[i]);
    }
    printf("%lld\n",maxn);
    return 0;
}