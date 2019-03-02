#include<bits/stdc++.h>
using namespace std;
int f[1010][1010];
int w[1010];
int c[1010];
int main(){
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=f[i-1][j];
            if(j>=w[i]){
                f[i][j]=max(f[i][j],f[i-1][j-w[i]]+c[i]);
            }
        }
    }
    cout<<f[n][m];
    return 0;
}