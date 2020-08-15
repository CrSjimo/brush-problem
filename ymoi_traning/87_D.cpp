#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::sort;
using std::min;
using std::min_element;
int **dp,*x,*y;
int n,m,k;
struct Node{
    int l,h;
    int i;
    bool operator<(const Node& nd)const{
        return i<nd.i;
    }
} *s;
template<typename T>T*& alloc(T*& a,size_t siz){
    return a=(T*)malloc(siz*sizeof(T));
}
int cur=1;
inline void upd(int i){
    if(i==s[cur].i)cur++;
}
inline bool is_blocked(int i,int j){
    if(cur>k)return false;
    // printf("test: %d %d\n",i,s[cur].i);
    if(i==s[cur].i){
        if(j<=s[cur].l||j>=s[cur].h){
            return true;
        }
    }
    return false;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    alloc(x,n+1);
    alloc(y,n+1);
    alloc(s,n+1);
    alloc(dp,n+1);
    memset(alloc(dp[0],m+1),0x0,(m+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        memset(alloc(dp[i],m+1),0x3f,(m+1)*sizeof(int));
        scanf("%d%d",x+i,y+i);
    }
    for(int i=1;i<=k;i++){
        scanf("%d%d%d",&s[i].i,&s[i].l,&s[i].h);
    }
    sort(s+1,s+k+1);
    for(int j=1;j<=m;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=x[i];j<=m;j++){
            dp[i][j]=min(dp[i][j],min(dp[i][j-x[i]]+1,dp[i-1][j-x[i]]+1));
            if(j==m){
                for(int k=0;k<=x[i];k++){
                    dp[i][m]=min(dp[i][j],min(dp[i][m-k]+1,dp[i-1][m-k]+1));
                }
            }
        }
        for(int j=1;j+y[i]<=m;j++){
            dp[i][j]=min(dp[i-1][j+y[i]],dp[i][j]);
        }
        if(i==s[cur].i){
            for(int j=1;j<=s[cur].l;j++){
                dp[i][j]=0x3f3f3f3f;
            }
            for(int j=m;j>=s[cur].h;j--){
                dp[i][j]=0x3f3f3f3f;
            }
        }
        // printf("\n");
        upd(i);
    }
    // printf("\n");
    // for(int j=m;j>=1;j--){
    //     for(int i=1;i<=n;i++){
    //         if(dp[i][j]<0x3f3f3f3f)printf("%d ",dp[i][j]);
    //         else printf("_ ");
    //     }
    //     printf("\n");
    // }
    int cnt=0;
    int flag=*min_element(dp[n]+1,dp[n]+m+1);
    if(flag<0x3f3f3f3f){
        printf("1\n%d\n",flag);
    }else{
        for(int i=1;i<=k;i++){
            if(*min_element(dp[s[i].i]+1,dp[s[i].i]+m+1)<0x3f3f3f3f){
                cnt++;
            }else{
                break;
            }
        }
        printf("0\n%d\n",cnt);
    }
    return 0;
}