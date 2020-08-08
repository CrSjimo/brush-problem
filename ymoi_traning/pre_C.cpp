#include<cstdio>
#include<cstdlib>
int * f;
int main(){
    int n,q;scanf("%d%d",&n,&q);
    f=(int*)calloc(n+1,sizeof(int));
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        f[i]=f[i-1]+k;
    }
    while(q--){
        int l,r;scanf("%d%d",&l,&r);
        printf("%d\n",f[r]-f[l-1]);
    }
    return 0;
}