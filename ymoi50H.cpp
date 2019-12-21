#include<stdio.h>
#include<vector>
inline int abs(int a){
    return a>0?a:-a;
}
int x,y;
inline bool cando(int i,int j){
    return !(i == x && j == y || abs(i - x) == 1 && abs(j - y) == 2 || abs(i - x) == 2 && abs(j - y) == 1);}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    std::vector<std::vector <long long> > map(n+2,std::vector<long long>(m+2));
    scanf("%d%d",&x,&y);
    x++;y++;
    map[0][1]=1;
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=m+1;j++){
            map[i][j]=map[i-1][j]+map[i][j-1];
            if(!cando(i,j))map[i][j]=0;
        }
    }
    printf("%lld\n",map[n+1][m+1]);
    return 0;
}