#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<deque>
using std::deque;
using std::min;
using std::max;
struct Node{
    int i,j,k;
};
int cube[102][102][102];
const int INF = 2147483647;
int main(){
    freopen("cube.in","r",stdin);
    freopen("cube.out","w",stdout);
    int a,b,c,n;scanf("%d%d%d%d",&a,&b,&c,&n);
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=c;k++){
                int _;scanf("%d",&_);
                cube[i][j][k]=_;
            }
        }
    }
    int ans=INF;
    for(int i=1;i+n-1<=a;i++){
        deque<Node> q;
        for(int j=1;j+n-1<=b;j++){
            for(int k=1;k+n-1<=c;k++){
                
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}