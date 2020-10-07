#include<cstdio>
#include<cstdlib>
#include<ctime>
int main(){
    srand((unsigned)time(NULL));
    int delta=rand()%200;
    printf("200 200 %d 100\n",delta);
    for(int i=1;i<=100;i++){
        printf("%d %d %d\n",rand()%200,rand()%200,rand()%10000);
    }
    return 0;
}