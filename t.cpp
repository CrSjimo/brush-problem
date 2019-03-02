#include <bits/stdc++.h>
using namespace std;
int arr[105][105];
int len[105];
int toInt(char s[]){
    int r=0;
    int k=1;
    for(int i=strlen(s)-1;i>=0;i--){
        r+=(s[i]-'0')*k;
        k*=10;
    }
    return r;
}
int main(){
    int n;
    cin>>n;
    string ss[105];
    for(int i=0;i<n;i++){
        cin>>ss[i];
        char num[1010];
        int k=0;
        int l=0;
        for(int j=0;j<ss[i].size();j++){
            if(ss[i].c_str()[j]!=','){
                num[k++]=ss[i].c_str()[j];
            }else{
                num[k]=0;
                // cout<<toInt(num)<<endl;
                arr[i][l++]=toInt(num);
                k=0;
            }
        }
        len[i]=l+1; 
        // cout<<len[i]<<endl;       
    }
    int maxn=-1e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<len[i];j++){
            maxn=max(maxn,arr[i][j]);
        }
    }
    cout<<maxn<<endl;
    int t=0;
    int a[105];
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<len[i];j++){
            if(arr[i][j]==maxn){
                a[k++]=i+1;
                t++;
                break;
            }
        }
    }
    for(int i=0;i<t;i++){
        cout<<a[i];
        if(i!=t-1)cout<<',';
    }
    return 0;
}