#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::next_permutation;
int main(){
    int n;
    scanf("%d",&n);
    char* a = (char*)malloc((n+1)*sizeof(int));
    scanf("%s",a);
    int cnt = 0;
    do{
        cnt++;
        printf("%s",a);
        printf("\n");
    }while(next_permutation(a,a+n));
    printf("%d\n",cnt);
    return 0;
}