#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using std::sort;
int main(){
    int lim;scanf("%d",&lim);
    int n;scanf("%d",&n);
    int* a = (int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    sort(a+1,a+n+1);
    int l = 1;
    int r = n;
    int ans = 0;
    while(l<=r){
        if(l!=r&&a[l]+a[r]<=lim){
            l++;r--;ans++;
        }else{
            r--;ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}