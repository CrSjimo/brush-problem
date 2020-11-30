#include<cstdio>
#include<cstdlib>
int* f;
int* d;
void init(int n){
    f=(int*)malloc((n+1)*sizeof(int));
    d=(int*)calloc((n+1),sizeof(int));
    for(int i=0;i<=n;i++){
        f[i]=i;
    }
}
int find(int i){
    if(f[i]==i)return i;
    int fi = f[i];
    f[i]=find(f[i]);
    d[i]+=d[fi];
    return f[i];
}
int update(int i,int j){
    int fi=find(i),fj=find(j);
    if(fi==fj){
        return d[i]+d[j]+1;
    }else{
        f[fi]=fj;
        d[i]=d[j]+1;
        return 0x3f3f3f3f;
    }
}
template<typename T>T min(T a,T b){return a<b?a:b;}
int main(){
    int n;scanf("%d",&n);
    int maxn = 0x3f3f3f3f;
    init(n);
    for(int u=1;u<=n;u++){
        int v;scanf("%d",&v);
        maxn=min(maxn,update(u,v));
    }
    printf("%d\n",maxn);
    return 0;
}
