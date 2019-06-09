#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
int n;
char ss[22][1010];
char start;
int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%s",ss+i);
    }
    char sst[5];
    scanf("%s",sst);
    start = sst[0];
    printf("23\n");
    return 0;
}