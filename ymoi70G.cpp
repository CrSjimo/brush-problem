#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
using std::max;
int* wa;
int* va;
int* dp;
struct Node{
    int t;
    vector<int> a;
};
vector< Node > colorpre;
vector< vector<int> > color;
vector<int> w;
vector<int> v;
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    dp=(int*)calloc((m+1),sizeof(int));
    wa=(int*)malloc((n+1)*sizeof(int));
    va=(int*)malloc((n+1)*sizeof(int));
    colorpre.resize(n+1);
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d%d%d",wa+i,va+i,&t);
        if(t==0){
            colorpre[i].t=i;
        }else{
            colorpre[t].a.push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(colorpre[i].t==0)continue;
        vector<int> tmp = *new vector<int>;
        w.push_back(wa[colorpre[i].t]);
        v.push_back(va[colorpre[i].t]*wa[colorpre[i].t]);
        tmp.push_back(w.size()-1);
        if(colorpre[i].a.size()==1){
            w.push_back(wa[colorpre[i].t]+wa[colorpre[i].a[0]]);
            v.push_back(va[colorpre[i].t]*wa[colorpre[i].t]+va[colorpre[i].a[0]]*wa[colorpre[i].a[0]]);
            tmp.push_back(w.size()-1);
        }else if(colorpre[i].a.size()==2){
            w.push_back(wa[colorpre[i].t]+wa[colorpre[i].a[0]]);
            v.push_back(va[colorpre[i].t]*wa[colorpre[i].t]+va[colorpre[i].a[0]]*wa[colorpre[i].a[0]]);
            tmp.push_back(w.size()-1);
            w.push_back(wa[colorpre[i].t]+wa[colorpre[i].a[1]]);
            v.push_back(va[colorpre[i].t]*wa[colorpre[i].t]+va[colorpre[i].a[1]]*wa[colorpre[i].a[1]]);
            tmp.push_back(w.size()-1);
            w.push_back(wa[colorpre[i].t]+wa[colorpre[i].a[0]]+wa[colorpre[i].a[1]]);
            v.push_back(va[colorpre[i].t]*wa[colorpre[i].t]+va[colorpre[i].a[0]]*wa[colorpre[i].a[0]]+va[colorpre[i].a[1]]*wa[colorpre[i].a[1]]);
            tmp.push_back(w.size()-1);
        }
        color.push_back(tmp);
    }
    for(int k=0;k<color.size();k++){
        for(int j=m;j>0;j--){
            for(int i:color[k]){
                if(j<w[i])continue;
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
    }
    printf("%d\n",dp[m]);
    return 0;
}