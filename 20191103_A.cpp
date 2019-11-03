#include<stdio.h>
#include<stack>
struct Node{
    int x,y,xl,yl;
    int id;
    bool in(int xx,int yy){
        int xoffset = xx-x;
        int yoffset = yy-y;
        return xoffset>=0&&xoffset<xl&&yoffset>=0&&yoffset<yl;
    }
};
std::stack<Node> map;
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        Node aa;
        scanf("%d%d%d%d",&aa.x,&aa.y,&aa.xl,&aa.yl);
        aa.id = i;
        map.push(aa);
    }
    int xx,yy;
    scanf("%d%d",&xx,&yy);
    while(!map.empty()){
        Node aa = map.top();
        map.pop();
        if(aa.in(xx,yy)){
            printf("%d\n",aa.id);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}