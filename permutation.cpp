#include <bits/stdc++.h>
using namespace std;
int arr[1010];
bool used[1010];
void permu(int i,int n){
    if(i==n+1){
        for(int j=1;j<=n;j++){
            printf("%5d",arr[j]);
        }
        printf("\n");
    }
    for(int j=1;j<=n;j++){
        if(used[j]==0){
            used[j]=1;
            arr[i]=j;
            permu(i+1,n);
            used[j]=0; 
        }
    }    
}
int main(){
    int n;
    cin>>n;
    permu(1,n);
    return 0;
}