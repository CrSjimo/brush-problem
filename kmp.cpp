#include<bits/stdc++.h>
using namespace std;
int nxt[1010];
char a[1010],b[1010];
int main(){
    cin>>(a+1)>>(b+1);
    int i=0,j=1;
    while(a[j]){
        while(i && a[i+1]!=a[j+1]){
            i=nxt[i];
        }
        if(a[i+1]==a[j+1]) ++i;
        nxt[j+1]=i;
        ++j;
    }
    i=0;j=0;
    while(b[j]){
        while(i&&a[i+1]!=b[j+1]){
            i=nxt[i];
        }
        if(a[i+1]==b[j+1]) ++i;
    }
}