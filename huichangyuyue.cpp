#include<stdio.h>
#define MAXN 100001
int tree[MAXN+10];
int endDateList[MAXN+10];
int query(int x){
    int ans = 0;
    // printf("test: %d %d\n",x,(x & (-x)));
    for(;x>0;x-=(x & (-x))){
        ans += tree[x];
    }
    return ans;
}
void update(int x,int num){
    for(;x<=MAXN;x+=(x & (-x))){
        tree[x]+=num;
    }
}
int tot = 0;
int main(){
    int n;
    scanf("%d",&n);
    for(;n;n--){
        char ops[5];
        scanf("%s",ops);
        if(*ops == 'A'){
            int start;
            int end;
            scanf("%d%d",&start,&end);
            int removedCnt = 0;
            for(int endTot = query(end);;endTot = query(end)){
                int l = 0,r = end;
                while(l<r){
                    int m = (l+r)/2;
                    if(query(m)+1<=endTot)l=m+1;
                    else r=m;
                }
                if(endDateList[l]>=start){
                    update(l,-1);
                    tot--;
                    removedCnt++;
                }else break;
            }
            update(start,1);
            endDateList[start] = end;
            tot++;
            printf("%d\n",removedCnt);
        }else{
            printf("%d\n",tot);
        }
    }
    return 0;
}