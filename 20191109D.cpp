#include<stdio.h>
#include<algorithm>
using namespace std;
int d,n;
int map[130][130];
int totl = 0;
int main(){
    scanf("%d",&d);
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int x,y,k;
        scanf("%d%d%d",&x,&y,&k);
        map[x][y] = k;
    }
    int maxans = -1;
    int cas = 0;
    int ans = 0;
    for(int xc = 0;xc<=128;xc++){
        for(int yc = 0;yc<=128;yc++){
            ans = 0;
            int xd = xc-d,xu = xc+d;
            int yd = yc-d,yu = yc+d;
            xd = xd>0?xd:0;
            yd = yd>0?yd:0;
            xu = xu<128?xu:128;
            yu = yu<128?yu:128;
            for(int x=xd;x<=xu;x++){
                for(int y=yd;y<=yu;y++){
                    ans+=map[x][y];
                }
            }
            if(ans>maxans){
                cas = 1;
                maxans = ans;
            }else if(ans == maxans){
                cas++;
            }
        }
    }
    printf("%d %d\n",cas,maxans);
    return 0;
}