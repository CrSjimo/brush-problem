#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::max;
int mp[105][105];
int main(){
    int n,m,s,l;scanf("%d%d%d%d",&n,&m,&s,&l);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mp[i][j]);
        }
    }
    int maxn = -19260817;
    for(int i=1;i+s-1<=n;i++){
        for(int j=1;j+l-1<=m;j++){
            int i2 = i+s-1,j2=j+l-1;
            int minn = 2147483647;
            int minnw = -19260817;
            int mini,minj;
            for(int ii = i;ii<=i2;ii++){
                for(int jj=j;jj<=j2;jj++){
                    int mid = mp[ii][jj];
                    int ans = 0;
                    for(int i_ = i;i_<=i2;i_++){
                        for(int j_=j;j_<=j2;j_++){
                            ans+=abs(mp[i_][j_]-mid);
                        }
                    }
                    if(ans<=minn && mid>minnw){
                        minn=ans;
                        minnw=mid;
                        mini=ii;
                        minj=jj;
                    }
                }
            }
            maxn = max(maxn,minnw);
        }
    }
    printf("%d\n",maxn);
    return 0;
}