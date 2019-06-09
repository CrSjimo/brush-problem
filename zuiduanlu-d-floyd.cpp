#include<cstdio>
#include<cstring>
double dp[40][40];
char currName[40][101];
inline double max(double a,double b){
    return a>b?a:b;
}
void f(int n){
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                dp[i][j] = max(dp[i][j],dp[i][k]*dp[k][j]);
            }
        }
    }
}
int indexOf(char* str,int len){
    for(int i = 0;i<len;i++){
        if(!strcmp(currName[i],str))return i;
    }
    return -1;
}
int main(){
    int n,m;
    int cas = 0;
    while(~scanf("%d",&n) && n){
        for(int i = 0;i<n;i++){
            scanf("%s",currName[i]);
        }
        for(int i = 0;i<n;i++){
            for(int j= 0;j<n;j++){
                if(i==j){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        scanf("%d",&m);
        for(int i = 0;i<m;i++){
            char s1[101],s2[101];
            double r;
            scanf("%s%lf%s",s1,&r,s2);
            dp[indexOf(s1,n)][indexOf(s2,n)] = r;
        }
        f(n);
        printf("Case %d: ",++cas);
        for(int i = 0;i<n;i++){
            if(dp[i][i]>1){
                goto cando;
            }
        }
        nocando:
        printf("No\n");
        continue;
        cando:
        printf("Yes\n");
    }
}