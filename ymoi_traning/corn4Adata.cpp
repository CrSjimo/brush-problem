#include<cstdio>
#include<cstdlib>
#include<ctime>
int main(){
    srand((unsigned)time(NULL));
    int l=rand()%100,r=rand()%100+l+1;
    printf("%d %d",l,r);
    return 0;
}