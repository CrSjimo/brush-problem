#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[1010],b[1010];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    int r[2020];
    int k=0,i=1,j=1;
    for(;;){
        if(i<=n&&j<=m){
            if(a[i]<b[j]){
                r[++k]=a[i++];
            }else{
                r[++k]=b[j++];
            }
        }else if(i<=n&&j==m+1){
            r[++k]=a[i++];
        }else if(i==n+1&&j<=m){
            r[++k]=b[j++];
        }else if(i==n+1&&j==m+1){
            break;
        }
    }
    for(int i=1;i<=k;i++)cout<<r[i]<<' ';
    return 0;
}