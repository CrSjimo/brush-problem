#include<stdio.h>
#include<string.h>
#include<algorithm>
int lb(int x) {
    return ((x)&(-x));
}
int min(int a,int b){
    return a<b?a:b;
}
#define MAXN 1100
long long map[MAXN][MAXN];
int N;
long long query(int i,int j){
    long long ans=0;
    for(int x = i;x>0;x-=lb(x)){
        for(int y = j;y>0;y-=lb(y)){
            ans+=map[x][y];
        }
    }
    return ans;
}
void update(int i,int j,int num){
    for(int x = i;x<N+10;x+=lb(x)){
        for(int y = j;y<N+10;y+=lb(y)){
            map[x][y]+=num;
        }
    }
}
long long queryRect(int x1,int y1,int x2,int y2){
    x1--;y1--;
    return 
        query(x2,y2)
        -query(x1,y2)
        -query(x2,y1)
        +query(x1,y1);
}
int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        memset(map,0,sizeof(map));
        int q;
        scanf("%d%d",&N,&q);
        while(q--){
            char opc[5];
            char& op = *opc;
            scanf("%s",opc);
            if(op == 'C'){
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                x2++,y2++;
                update(x1,y1,1);
                update(x2,y2,1);
                update(x1,y2,-1);
                update(x2,y1,-1);
            }else{
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%lld\n",query(x,y)&1);
            }

        }
        if(cas){
            printf("\n");
        }
    }
    
    return 0;
} 