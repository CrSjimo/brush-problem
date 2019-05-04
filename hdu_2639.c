#include<stdio.h>
#include<string.h>
//第k优解
int n,v,K;
int w[1010],c[1010];
int dpA[31],dpB[31],dp[1010][31];
int cases;
int main(){
    scanf("%d",&cases);
    while(cases--){
        memset(dpA,0,sizeof(dpA));
        memset(dpB,0,sizeof(dpB));
        memset(dp,0,sizeof(dp));
        scanf("%d%d%d",&n,&v,&K);
        for(int i=0;i<n;i++){
            scanf("%d",c+i);
        }
        for(int i=0;i<n;i++){
            scanf("%d",w+i);
        }
        for(int i=0;i<n;i++){
            for(int j=v;j>=w[i];j--){
                for(int k=0;k<K;k++){
                    dpA[k] = dp[j-w[i]][k]+c[i];
                    dpB[k] = dp[j][k];
                }
                dpA[K]=dpB[K]=-1;
                int a=0,b=0,c=0;
                while(c<K && (~dpA[a] || ~dpB[b])){
                    if(dpA[a]<dpB[b]){
                        dp[j][c] = dpB[b++];
                    }else{
                        dp[j][c] = dpA[a++];
                    }
                    if(dp[j][c]!=dp[j][c-1])c++;
                }
            }
        }
        printf("%d\n",dp[v][K-1]);
    }
    return 0;
}