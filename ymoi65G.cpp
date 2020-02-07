#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::next_permutation;
int main(){
    int n;
    scanf("%d",&n);
    int* a = (int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++)a[i]=i;
    do{
        for(int i=1;i<=n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }while(next_permutation(a+1,a+n+1));
    return 0;
}