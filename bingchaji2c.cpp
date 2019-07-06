#include<stdio.h>
#include<string.h>
#define A 50011
#define isSame 0
#define childEatParent 1
#define ParentEatChild 2
// #define DEBUG
int arr[A+10];
int type[A+10];
int query(int i){
    if(arr[i] == i)
        return i;
    int tmp = query(arr[i]);
    type[i] = (type[i] + type[arr[i]])%3;
    return arr[i] = tmp;
}
bool update(int i,int j,int t){//0: same, 1: i eat j, 2: j eat i
    if(t && i == j)return 1;
    int aliasI = query(i);
    int aliasJ = query(j);
    if(aliasI == aliasJ){
        //conflict return 1, no conflict return 0
        return ((type[i] - type[j]+3) % 3 != t);
    }
    arr[aliasI] = aliasJ;
    type[aliasI] = (type[j] - type[i] + t + 3) % 3;
    return 0;
    
}
void init(int len){
    while(len--){
        arr[len] = len;
    }
}
int ans = 0;
int n,m;
inline bool inRange(int a,int b){
    return a<=n && b<=n;
}
int main(){
    memset(type,0,sizeof(type));
    scanf("%d%d",&n,&m);
    init(n);
    while(m--){
        int op,a,b;
        scanf("%d%d%d",&op,&a,&b);
        if(!inRange(a,b)||update(a,b,op-1)){
            ans++;
            //printf("conflict\n");
        }
    }
    printf("%d\n",ans);
    return 0;
}