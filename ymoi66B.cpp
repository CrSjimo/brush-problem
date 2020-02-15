#include<cstdio>
#include<cstdlib>
int main(){
    int n;scanf("%d",&n);
    int* a = (int*)malloc((n+1)*sizeof(int));
    int avg = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        avg+=a[i];
    }
    avg/=n;
    int ans = 0;
    for(int i=1;i<n;i++){
        if(a[i]!=avg){
            ans++;
            a[i+1]+=a[i]-avg;
        }
    }
    printf("%d\n",ans);
    return 0;
}