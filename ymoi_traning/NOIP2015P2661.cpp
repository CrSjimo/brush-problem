#include<cstdio>
#include<cstdlib>
int* f;
int* d;
int update(int x,int l){
    l++;
    return f[x]==x?x:update(f[x],l);
}
void init(int n){
    f=(int*)malloc((n+1)*sizeof(int));
    for(int i=0;i<=n;i++){
        f[i]=i;
    }
}
int main(){
    int n;scanf("%d",&n);
    init(n);
    for(int i=1;i<=n;i++){
        int f;scanf("%d",&f);
        int l=0;
        
    }
}