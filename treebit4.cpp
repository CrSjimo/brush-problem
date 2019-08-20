#include<stdio.h>
#include<string.h>
int cas;
int n;
int nn = 32768;
int tree[50010];
int query(int x){
    int ans = 0;
    // printf("test: %d %d\n",x,(x & (-x)));
    for(;x>0;x-=(x & (-x))){
        ans += tree[x];
    }
    return ans;
}
void update(int x,int num){
    for(;x<=nn;x+=(x & (-x))){
        tree[x]+=num;
    }
}
int anses[50010];
int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x++,y++;
        anses[query(x)]++;
        //printf("query%d: %d\n",x,query(x));
        update(x,1);
    }
    // for(int i = 1;i<=10;i++){
    //     printf("test%d: %d\n",i,query(i));
    // }
    for(int i = 0;i<n;i++){
        printf("%d\n",anses[i]);
    }
    return 0;
}