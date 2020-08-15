#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::max;

int dp[12][100][100];
int valid[2048];
int siz[1<<10];
int tot=0;

inline bool cando(int S){
    return !((S&(S<<1)))||((S&(S<<2)));
}
inline bool cando(int S,int T,int U){
    return !((S&T)||(S&U)||(T&U));
}
char s[12];
int _lm[105];
int* lm=_lm+1;
int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<(1<<n);i++){
        if(cando(i)){
            valid[++tot]=i;
        }
        siz[i]=siz[i>>1]+(i&1);
    }
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        for(int j=0;j<m;j++){
            if(s[j]=='H')lm[i]|=(1<<j);
        }
    }
    
    dp[0][0][1]=1;
    //TODO 处理第一行和第二行
    for(int i=0;i<n;i++){
        for(int _s=1;_s<=tot;_s++){
            int S=valid[_s];if(S&lm[i-1])continue;
            for(int _t=1;_t<=tot;_t++){
                int T=valid[_t];if(T&lm[i])continue;
                for(int _u=1;_u<=tot;_u++){
                    int U=valid[_u];if(U&lm[i+1])continue;
                    if(!cando(S,T,U))continue;
                    dp[i+1][_t][_u]=max(dp[i+1][_t][_u],dp[i][_s][_t]+siz[U]);
                }
            }
        }
    }
    int ans=0;
    for(int _s=1;_s<=tot;_s++){
        int S=valid[_s];
        for(int _t=1;_t<=tot;_t++){
            int T=valid[_t];
            ans=max(ans,dp[n][_s][_t]);
        }
    }
    printf("%d\n",ans);
    return 0;
}