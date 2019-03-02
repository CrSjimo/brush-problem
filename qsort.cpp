#include<bits/stdc++.h>
using namespace std;
int a[1010];
void qusort(int l,int r){
    int i=l,j=r,k=a[(l+r)/2];
    while(i<j){
        while(a[i]<k) ++i;
        while(a[j]>k) --j;
        if(i<=j){
            swap(a[i++],a[j--]);
        }
    }
    if(l<j)qusort(l,j);
    if(i<r)qusort(i,r);
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    qusort(1,n);
    for(int i=1;i<=n;i++)cout<<a[i];
    return 0;
}