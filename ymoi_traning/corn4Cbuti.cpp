#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
vector< vector<int> >G;
int* f;
int* _f;
int n;
bool* tmp;
int* steps;
struct Node{
    int t;
    int i;
}* cache;
bool checkA(){
    if(n>2*1e4)return false;
    if(f[1]!=n)return false;
    for(int i=2;i<=n;i++){
        if(f[i]!=f[i-1])return false;
    }
    return true;
}
bool checkB(){
    for(int i=1;i<=n;i++){
        if(tmp[f[i]])return false;
        tmp[f[i]]=true;
    }
    for(int i=1;i<=n;i++){
        if(!tmp[i])return false;
    }
    return true;
}
bool checkC(){
    for(int i=1;i<=n;i++){
        if(f[i]>i)return false;
        _f[f[i]]=i;
    }
    return true;
}
int dfs(int s,int i,int t){
    if(i==s){
        steps[s]=t;
        return t;
    }
    if(i<0)i=-i;
    int step = dfs(s,f[i],t+1);
    // fprintf(stderr,"testd: %d %d %d\n",i,s,step-t);
    steps[i]=step;
    return step;
}
int type=0;
int main(){
    freopen("naive.in","r",stdin);
    freopen("naive.out","w",stdout);
    scanf("%d",&n);
    f=(int*)malloc((n+1)*sizeof(int));
    _f=(int*)malloc((n+1)*sizeof(int));
    tmp=(bool*)malloc((n+1)*sizeof(bool));
    for(int i=1;i<=n;i++){
        scanf("%d",f+i);
    }
    bool isA=checkA();
    if(isA){
        type=1;
    }else{
        bool isB=checkB();
        if(isB){
            type=2;
            steps=(int*)malloc((n+1)*sizeof(int));
            cache=(Node*)malloc((n+1)*sizeof(Node));
            dfs(1,-1,0);
            // for(int i=1;i<=n;i++){
            //     fprintf(stderr,"test: 1 %d %d %d\n",i,cache[i].i,cache[i].t);
            // }
            for(int i=2;i<=n;i++){
                if(!steps[i])dfs(i,-i,0);
                // for(int j=1;j<=n;j++){
                //     fprintf(stderr,"test:%d %d %d %d\n",i,j,cache[j].i,cache[j].t);
                // }
            }
            // for(int i=1;i<=n;i++){
            //     fprintf(stderr,"test: %d %d\n",i,steps[i]);
            // }
        }else if(checkC()){

        }
    }
    int m;scanf("%d",&m);
    while(m--){
        int x,t;scanf("%d%d",&x,&t);
        int ans=x;
        if(type==1){
            printf("%d\n",((x-1-t)%n+n)%n+1);
        }else{
            if(type==2)t%=steps[x];
            while(t--){
                ans=f[ans];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}