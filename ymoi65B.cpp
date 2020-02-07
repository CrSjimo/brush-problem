#include<cstdio>
// bool isPrime[50] = {1,1};
// void initPrime(){
//     for(int k=2;k<45;k++){
//         for(int i=2;i*i<=k;i++){
//             if(k%i==0){
//                 goto not_prime;
//             }
//         }
//         isPrime[k] = true;
//         not_prime:;
//     }
// }
//int ans = 0;
int n;
// int a[25];
// bool vis[25];
// void dfs(int i){
//     //printf("t:%d\n",i);
//     if(i>n){
//         if(isPrime[a[i-1]+a[1]])ans++;
//     }
//     for(int j=1;j<=n;j++){
//         if((i==1||isPrime[j+a[i-1]])&&!vis[j]){
//             a[i]=j;
//             vis[j]=1;
//             //printf("T:%d\n",j);
//             dfs(i+1);
//             vis[j]=0;
//         }
//     }

// }
int anses[20] = {0,0,2,0,8,0,12,0,32,0,960,0,12288,0,40320,0,1296384};
int main(){
    // initPrime();
    // printf("int ans[20] = {0,0,");
    // for(n=2;n<=16;n++){
    //     ans=0;
    //     dfs(1);
    //     printf("%d,",ans);
    // }
    // printf("};");
    scanf("%d",&n);
    printf("%d\n",anses[n]);
    return 0;
}