#include<cstdio>
int main(){
    int dep,n;
    scanf("%d%d",&dep,&n);
    int ans=1;
    for(int i=1,j=n;i<dep;i++,j=(j+1)/2){
        ans<<=1;
        ans|=(j&1^1);
    }
    printf("%d\n",ans);
    return 0;
}