#include<cstdio>
#include<cstdlib>
#pragma OPT_LEVEL 2
int* p;
int* a;
typedef long long ll;
int n,m;
int minn = 0x19260817;
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
void dfs(int i,int t){
    if(t>=minn)return;
    if(i>n){
        minn = min(t,minn);
        return;
    }
    for(int j=1;j<=m;j++){
        if(p[j]+a[i]<minn){
            p[j]+=a[i];
            dfs(i+1,max(t,p[j]));
            p[j]-=a[i];
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    a = (int*)malloc((n+1)*sizeof(int));
    p = (int*)malloc((m+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    dfs(1,0);
    printf("%d\n",minn);
    return 0;
}