#include<stdio.h>
#define A 50011
#define B 50012
#define C 50013
int eatWho(int type){
    return (type == A)?B:((type == B)?C:A);
}
int arr[50100];
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
bool noSameType(int i,int j){
    if(query(i) < 50010 || query(j) < 50010)return 0;
    if(query(i) == query(j))return 0;
    return 1;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    init(n);
    int ans;
    while(m--){
        int op,a,b;
        scanf("%d%d%d",&op,&a,&b);
        if(op == 1){
            if(a>n || b>n || noSameType(a,b))ans++;
            else{
                update(a,b);
                if(noHaveType)
            }
        }else{

        }
    }
}