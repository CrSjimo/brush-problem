#include<cstdio>
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=n,j=m;k;k--){
        printf("%d %d\n",i=(i%n)+1,j=(j%m)+1);
    }
    return 0;
}