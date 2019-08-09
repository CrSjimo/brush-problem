#include<stdio.h>
#define MAXN 1010
int arr[MAXN];
int query(int i){
    if(arr[i] == i)
        return i;
    return arr[i] = query(arr[i]);
}
void update(int i,int j){
    int aliasI = query(i);
    int aliasJ = query(j);
    arr[aliasI] = aliasJ;
}
void init(int len){
    while(len--){
        arr[len] = len;
    }
}