#include<stdio.h>
#include<math.h>
int clac(int k,int n){
    int ans = 1;
    for(int i = 1;i<=k;i++){
        ans*=10;
        ans%=n;
    }
    return ans;
}
int clac2(int k,int n){
    int ans = 1;
    for(int i = 1;i<=k;i++){
        ans*=10;
        ans%=n;
    }
    return ans;
}
int main(){
    int n,m,k,x;
    scanf("%d%d%d%d",&n,&m,&k,&x);
    int ans;
    if(k<=3){
        ans=(x%n+(m%n)*clac(k,n))%n;
    }else{

    }
    return 0;
}