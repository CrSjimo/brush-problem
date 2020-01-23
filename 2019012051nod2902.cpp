#include<stdio.h>
#include<vector>
struct BCJ{
    std::vector<int> f;
    BCJ(int n){
        init(n);
    }
    void init(int n){
        f.resize(n+1);
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
    }
    int find(int i){
        return f[i]==i?i:(f[i]=find(f[i]));
    }
    bool update(int i,int j){
        if(find(i)==find(j))return false;
        f[find(i)]=f[find(j)];
        return true;
    }
    int size(){
        int cnt=0;
        for(int i=1;i<f.size();i++){
            if(f[i]==i)cnt++;
        }
        return cnt;
    }
};
int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        int n,m;
        scanf("%d%d",&n,&m);
        BCJ bcj(n);
        while(m--){
            int x,y;
            scanf("%d%d",&x,&y);
            if(!bcj.update(x,y)){
                printf("Yes\n");
                goto match;
            }
        }
        printf("No\n");
        match:;
    }
    
}