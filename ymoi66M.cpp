#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::max;
int n;
int* s;
int* a;
bool* vis;
int maxp = 0;
inline int calc_val(int next){
    if(next<=maxp)return a[next];
    else return 2*(s[next]-s[maxp])+a[next];
}
int main(){
    int n;
    scanf("%d",&n);
    s=(int*)malloc((n+1)*sizeof(int));
    a=(int*)malloc((n+1)*sizeof(int));
    vis=(bool*)calloc((n+1),sizeof(bool));
    for(int i=1;i<=n;i++)scanf("%d",s+i);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    int now = 0;
    a[0]=s[0]=0;
    int ans = 0;
    for(int i=1;i<=n;i++){
        int maxn = -19260817;
        int maxnp=0;
        for(int j=1;j<=n;j++){
            if(vis[j])continue;
            if(maxn<calc_val(j)){
                maxn = calc_val(j);
                maxnp = j;
            }
        }
        vis[maxnp]=1;
        maxp = max(maxp,maxnp);
        ans+=maxn;
        printf("%d\n",ans);
    }
    return 0;
}