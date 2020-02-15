#include<cstdio>
#include<string>
using std::string;
#include<iostream>
using std::cin;
using std::cout;
#include<algorithm>
using std::sort;
#include<vector>
using std::vector;
bool cmp(string a,string b){
    return a+b>b+a;
}
int main(){
    int n;scanf("%d",&n);
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<"\n";
    return 0;
}