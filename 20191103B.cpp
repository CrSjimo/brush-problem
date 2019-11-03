#include<stdio.h>
int casCnt[200005],colorCnt[200005],pos[200005];
//Every xuanxue problem can be solved by rewriting code.
//--big philosophier CRS
int main(){
    int n,k,p;
    scanf("%d%d%d",&n,&k,&p);
    int ans = 0;
    int tmp;
    for (int i=1;i<=n;i++){
        int color,price;
        //online gkd
        scanf("%d%d",&color,&price);
        if (price<=p){
            tmp = i;
        }
        if (tmp>=pos[color]){
            casCnt[color] = colorCnt[color];
        }
        colorCnt[color]++;
        ans+=casCnt[color];
        pos[color] = i;
    }
    printf("%d\n",ans);
    return 0;
}