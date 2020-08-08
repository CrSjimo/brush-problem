#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
char a[105][105];
int f1[105][105];
int f2[105][105];
using std::min;
using std::max_element;
using std::max;
inline bool dir_up(int i,int j){
    return (i&1)^(j&1);
}
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        memset(a,0,sizeof(a));
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        for(int i=1;i<=n;i++){
            scanf("%s",&a[i][i]);
        }
        int maxn=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=2*n-1;j++){
                if(a[i][j]=='-')f1[i][j]=f2[i][j]=1;
                if(a[i][j]=='-' && !dir_up(i,j)){
                    if(f1[i-1][j])f1[i][j]+=min(f1[i-1][j-1],f1[i-1][j+1]);
                    maxn=max(maxn,f1[i][j]);
                }
                //printf("%d ",f1[i][j]);
            }
            //printf("\n");
        }
        for(int i=n;i>=1;i--){
            for(int j=1;j<=2*n-1;j++){
                if(a[i][j]=='-' && dir_up(i,j)){
                    if(f2[i+1][j])f2[i][j]=min(f2[i+1][j-1],f2[i+1][j+1])+1;
                    maxn=max(maxn,f2[i][j]);
                }
            }
        }
        printf("%d\n",maxn*maxn);
    }
    return 0;
}