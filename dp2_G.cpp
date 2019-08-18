#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN
struct Brick{
    int h,w,l;
    Brick(int x,int y,int z){
        h = x;
        l = std::max(y,z);
        w = std::min(y,z);
    }
    Brick(){}
} b[200];
int dp[200];
bool cmp(Brick& b1,Brick& b2){
    if(b1.l==b2.l){
        return b1.w<b2.w;
    }
    return b1.l<b2.l;
}
bool canDo(Brick& bTop,Brick& bBottom){
    return bTop.w<bBottom.w&&bTop.l<bBottom.l;
}
int main(){
    int n;
    int cas = 0;
    while(~scanf("%d",&n) && n){
        // if(cas!=0)printf("\n");
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<n;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            b[i*3+0]=Brick(x,y,z);
            b[i*3+1]=Brick(y,x,z);
            b[i*3+2]=Brick(z,x,y);
        }
        std::sort(b,b+n*3,cmp);
        dp[0] = b[0].h;
        for(int i = 0;i<n*3;i++){
            int maxn = 0;
            for(int j = 0;j<i;j++){
                if(canDo(b[j],b[i])){
                    maxn = std::max(maxn,dp[j]);
                }
            }
            dp[i] = maxn+b[i].h;
        }
        printf("Case %d: maximum height = %d\n",++cas,*std::max_element(dp,dp+n*3));
    }
    return 0;
}
 
// #include <iostream>
// #include <algorithm>
// using namespace std;
// struct Cuboid
// {
//     int l,w,h;
// }cd[181];
// int dp[181];
// // sort比较函数
// bool cmp( Cuboid cod1,Cuboid cod2 )
// {
//     if( cod1.l==cod2.l )    return cod1.w<cod2.w;
//     return cod1.l<cod2.l;
// }
// int main()
// {
//     int i,j,n,len,t_num=1;
//     int z1,z2,z3;
//     while( cin>>n && n )
//     {
//         len=0;
//         // 每组数都可以变换为6种长方体
//         for(i=0;i<n;++i)
//         {
//             cin>>z1>>z2>>z3;
//             cd[len].l=z1,cd[len].w=z2,cd[len++].h=z3;
//             cd[len].l=z1,cd[len].w=z3,cd[len++].h=z2;
//             cd[len].l=z2,cd[len].w=z1,cd[len++].h=z3;
//             cd[len].l=z2,cd[len].w=z3,cd[len++].h=z1;
//             cd[len].l=z3,cd[len].w=z1,cd[len++].h=z2;
//             cd[len].l=z3,cd[len].w=z2,cd[len++].h=z1;
//         }
 
//         sort(cd,cd+len,cmp);
//         dp[0]=cd[0].h;
        
//         // 构建dp数组
//         int max_h;
//         for(i=1;i<len;++i)
//         {
//             max_h=0;
//             for( j=0;j<i;++j )
//             {
//                 if( cd[j].l<cd[i].l && cd[j].w<cd[i].w )
//                     max_h=max_h>dp[j]?max_h:dp[j];
//             }
//             dp[i]=cd[i].h+max_h;
//         }
        
//         // 再次搜索 所有dp中最大值
//         max_h=0;
//         for(i=0;i<len;++i)
//             if( max_h<dp[i] )
//                 max_h=dp[i];
//         // 输出
//         cout<<"Case "<<t_num++<<": maximum height = "<<max_h<<endl;
//     }
//     return 0;
// }