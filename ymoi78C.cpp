#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::min;
typedef long long ll;
int n;
int* a;
ll* f;//1~x sum
ll* f_cost;//x~1 sum
int mid = 1;
ll now;
int* cost;
inline int md(int i){
    return (i-1)%n+1;
}
int main(){
    scanf("%d",&n);
    a=(int*)calloc(n+1,sizeof(int));
    f=(ll*)calloc(2*n+1,sizeof(ll));
    f_cost=(ll*)calloc(2*n+2,sizeof(ll));
    cost=(int*)calloc(n+1,sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d%d",cost+i,a+i);
    }
    for(int i=2;i<=2*n;i++){
        f[i]=f[i-1]+a[md(i-1)];
    }
    for(int i=1;i<=2*n;i++){
        f_cost[i]=f_cost[i-1]+cost[md(i)];
    }
    //printf("test: %d %d\n",f[4]-f[1],f[7]-f[4]);
    int tot_len = f[n+1];
    ll minn=1926081019260810192;
    for(int i=1;i<=n;i++){
        int delta = 0;
        while(f[mid+delta]-f[i]<=tot_len/2){
            delta++;
        }
        if(i==1)for(int j=i;j<=n+i-1;j++){
            //printf("test: %d %d\n",md(j),min(f[j]-f[i],f[n+i]-f[j]));
            now+=cost[md(j)]*min(f[j]-f[i],f[n+i]-f[j]);
        }else{
            now+=a[i]*((f_cost[n+i]-f_cost[mid+1])-(f_cost[mid]-f[i]));
        }
        //printf("test: %d %d\n\n",i,now);
        minn=min(minn,now);//TODO
        now=0;
    }
    printf("%lld\n",minn);
    return 0;
}