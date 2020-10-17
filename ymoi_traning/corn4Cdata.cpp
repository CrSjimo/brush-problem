#include<cstdio>
#include<cstdlib>
#include<ctime>
int main(){
    srand((unsigned)time(NULL));
    int n=rand()%100+1;
    printf("%d\n",n);
    for(int i=1;i<=n;i++){
        if(i==1)printf("%d\n",n);
        else printf("%d\n",i-1);
    }
    int m=rand()%100+1;
    printf("%d\n",m);
    m-=1;
    while(m--){
        printf("%d %d\n",rand()%n+1,rand()%100+1);
    }
    printf("%d %d",rand()%n+1,rand()%100+1);
    return 0;
}