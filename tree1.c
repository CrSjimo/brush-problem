#include<stdio.h>
#include<string.h>
int cas;
int n;
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
    for(;x<=n;x+=(x & (-x))){
        tree[x]+=num;
    }
}
void input(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        int num;
        scanf("%d",&num);
        update(i,num);
    }
}
int main(){
    scanf("%d",&cas);
    for(int i = 1;i<=cas;i++){
        memset(tree,0,sizeof(tree));
        input();
        printf("Case %d:\n",i);
        char opp[10];
        while(1){
            scanf("%s",opp);
            char op = opp[0];
            if(op == 'Q'){
                int x1,x2;
                scanf("%d%d",&x1,&x2);
                printf("%d\n",query(x2)-query(x1-1));
            }else if(op == 'A' || op == 'S'){
                int x1,x2;
                scanf("%d%d",&x1,&x2);
                x2 = (op == 'A')?(x2):(-x2);
                update(x1,x2);
            }else{
                break;
            }
        }
    }
    return 0;
}