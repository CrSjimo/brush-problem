#include<cstdio>
#include<cstdlib>
#include<deque>
#include<map>
using std::map;
using std::deque;
#define int long long
template<typename T>inline T& max(T a,T b){
    return a>b?a:b;
}
int n,m,delta,num;
int** dp;
inline int h(int i,int j){
    return i*n+j;
}
map<int,int> mp;
signed main(){
    scanf("%lld%lld%lld%lld",&n,&m,&delta,&num);
    dp=(int**)malloc((2)*sizeof(int*));
    for(int**p=dp;p<=dp+1;p++)*p=(int*)calloc((m+1),sizeof(int));
    for(int i=1;i<=num;i++){
        int x,y,k;scanf("%lld%lld%lld",&x,&y,&k);
        mp[h(y,x)]=k;
    }
    if(n<500&&m<500){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=j-delta;k<=j+delta;k++){
                    if(k<0||k>=m)continue;
                    int x=0;
                    if(mp.count(h(i,j)))x=mp[h(i,j)];
                    dp[i&1][j]=max(dp[i&1][j],x+dp[(i-1)&1][k]);
                }
                // printf("test:%d %d %d\n",i,j,dp[i&1][j]);
            }
        }
    }else{
        for(int i=0;i<n;i++){
            deque<int> q;
            for(int j=0;j<m;j++){
                while(!q.empty()&&j-q.front()>delta)q.pop_front();
                while(!q.empty()&&j+delta<m&&dp[(i-1)&1][q.back()]<dp[(i-1)&1][j+delta])q.pop_back();
                if(j==0){
                    int maxarg=0;
                    for(int k=0;k<=j+delta;k++){
                        if(k>=m)break;
                        if(dp[(i-1)&1][k]>dp[(i-1)&1][maxarg]){
                            maxarg=k;
                        }
                    }
                    q.push_back(maxarg);
                }else if(j+delta<m){
                    q.push_back(j+delta);
                }
                // for(int _:q){
                //     printf("test %d %d - %d %d\n",i,j,_,dp[(i-1)&1][_]);
                // }
                int x=0;
                if(mp.count(h(i,j)))x=mp[h(i,j)];
                dp[i&1][j]=x+dp[(i-1)&1][q.front()];
                // printf("test:%d %d %d %d %d\n",i,j,dp[i&1][j],q.front(),dp[(i-1)&1][q.front()]);
            }
        }
    }
    
    int ans=0;
    for(int j=0;j<m;j++){
        ans=max(ans,dp[(n-1)&1][j]);
    }
    printf("%lld\n",ans);
    return 0;
}