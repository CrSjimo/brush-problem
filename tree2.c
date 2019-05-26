#include<stdio.h>
#include<string.h>
void swap(int* a,int* b) {
    int _a0e9=*a;
    *a=*b;
    *b=_a0e9;
}
int lb(int x) {
    return ((x)&(-x));
}
int min(int a,int b){
    return a<b?a:b;
}
int map[1010][1010];
int arr[1010][1010];
int query(int i,int j){
    int ans=0;
    for(int x = i;x>0;x-=lb(x)){
        for(int y = j;y>0;y-=lb(y)){
            ans+=map[x][y];
        }
    }
    return ans;
}
void update(int i,int j,int num){
    for(int x = i;x<1005;x+=lb(x)){
        for(int y = j;y<1005;y+=lb(y)){
            map[x][y]+=num;
        }
    }
    arr[i][j]+=num;
}
// #define sum query
// #define f map
// #define low lb
// int sum(int x, int y)
// {
// 	int tot = 0;
// 	for (int i = x; i > 0; i -= low(i))
// 		for (int j = y; j > 0; j -= low(j)) tot += f[i][j];
// 	return tot;
// }
// #define maxn 1010
// #define add update
// void add(int x, int y, int z)
// {
// 	for (int i = x; i < maxn - 3; i += low(i))
// 		for (int j = y; j < maxn - 3; j += low(j)) f[i][j] += z;
//     arr[x][y] += z;
// }
int queryRect(int x1,int y1,int x2,int y2){
    if(x1>x2)swap(&x1,&x2);
    if(y1>y2)swap(&y1,&y2);
    x1--;y1--;
    return 
        query(x2,y2)
        -query(x1,y2)
        -query(x2,y1)
        +query(x1,y1);
}
int cas;
int main(){
    scanf("%d",&cas);
    for(int i = 1;i<=cas;i++){
        printf("Case %d:\n",i);
        memset(map,0,sizeof(map));
        memset(arr,0,sizeof(arr));
        for(int i = 1;i<1005;i++){
            for(int j = 1;j<1005;j++){
                update(i,j,1);
            }
        }
        // printf("%d\n",map[4][4]);
        int opc;
        scanf("%d",&opc);
        for(int j = 1;j<=opc;j++){
            char op;
            char opt[10];
            scanf("%s",opt);
            op=opt[0];
            if(op=='S'){
                int x1,x2,y1,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                if(x1>x2)swap(&x1,&x2);
                if(y1>y2)swap(&y1,&y2);
                x2++;y2++;
                int ans = query(x2,y2)-query(x1,y2)-query(x2,y1)+query(x1,y1);
                printf("%d\n",ans);
            }else if(op=='A'||op=='D'){
                int x,y,num;
                scanf("%d%d%d",&x,&y,&num);
                x++;y++;
                num=((op=='A')?(num):(-min(arr[x][y],num)));
                update(x,y,num);
            }else if(op=='M'){
                int x1,x2,y1,y2;
                int num;
                scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&num);
                x1++;x2++;y1++;y2++;
                num = min(arr[x1][y1],num);
                update(x1,y1,-num);
                update(x2,y2,num);
            }
        }
    }
    return 0;
} 