#include<cstdio>
#include<cstdlib>
int* f;
int main(){
    freopen("naive.in","r",stdin);
    freopen("naive.out.diff","w",stdout);
    int n;scanf("%d",&n);
    f=(int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",f+i);
    }
    int m;scanf("%d",&m);
    while(m--){
        int x,t;scanf("%d%d",&x,&t);
        int ans=x;
        while(t--){
            ans=f[ans];
        }
        printf("%d\n",ans);
    }
    return 0;
}