#include<cstdio>
#include<cstdlib>

long long* dp[11+4+5+1+4][1+9+1+9+81+0];


int* valid;
int tot=0;

int* siz;

inline bool cando(int S){
    return !(S&(S<<1));
}
inline bool cando(int S,int T){
    return !((S&T)||(S&(T<<1))||(S&(T>>1)));
}

int main(){
    int n,k;scanf("%d%d",&n,&k);
    if(k>81){
        printf("0\n");
        return 0;
    }
    siz=(int*)calloc((1<<n),sizeof(int));
    valid=(int*)malloc((4000)*sizeof(int));
    for(int i=0;i<n+1;i++)for(int j=0;j<=100;j++){
        dp[i][j]=(long long*)calloc((4000),sizeof(long long));
    }
    tot=0;
    for(int i=0;i<(1<<n);i++){
        if(cando(i)){
            valid[++tot]=i;
        }
        siz[i]=siz[i>>1]+(i&1);
    }
    dp[0][0][1]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            for(int _1=1;_1<=tot;_1++){int S=valid[_1];
                for(int _2=1;_2<=tot;_2++){int T=valid[_2];
                    if(cando(S,T)){
                        if(j+siz[T]>81)continue;
                        dp[i+1][j+siz[T]][_2]+=dp[i][j][_1];
                    }
                }
            }
        }
    }
    long long ans=0;
    for(int _=1;_<=tot;_++){int S=valid[_];
        ans+=dp[n][k][_];
    }
    printf("%lld\n",ans);
    return 0;
}