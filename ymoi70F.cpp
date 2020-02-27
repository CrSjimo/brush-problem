#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
using std::max;
vector< vector<int> > color;
int* w;
int* v;
int* dp;
int main(){
    int m,n,t;
    scanf("%d%d%d",&m,&n,&t);
    color.resize(t+1);
    w=(int*)malloc((n+1)*sizeof(int));
    v=(int*)malloc((n+1)*sizeof(int));
    dp=(int*)calloc((m+1),sizeof(int));
    for(int i=1;i<=n;i++){
        int ti;
        scanf("%d%d%d",w+i,v+i,&ti);
        color[ti].push_back(i);
    }
    for(int k=1;k<=t;k++){
        for(int j=m;j>=0;j--){
            for(int i:color[k]){
                if(j<w[i])continue;
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
    }
    printf("%d\n",dp[m]);
    return 0;
}