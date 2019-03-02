#include <bits/stdc++.h>
using namespace std;
int arr[1010];
bool used[1010];
void permu(int i,int n,int r){
    if(i==r+1){
        for(int j=1;j<=r;j++){
            printf("%3d",arr[j]);
        }
        printf("\n");
    }
    for(int j=arr[i-1]+1;j<=n;j++){
        if(used[j]==0){
            used[j]=1;
            arr[i]=j;
            permu(i+1,n,r);
            used[j]=0; 
        }
    }    
}
int main(){
    int n,r;
    cin>>n>>r;
    permu(1,n,r);
    return 0;
}