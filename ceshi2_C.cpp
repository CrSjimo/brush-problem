#include<stdio.h>
#include<vector>
std::vector<bool> s[100010];
int fa[100030];
int query(int i){
    return (fa[i]==i)?(i):(fa[i]=query(fa[i]));
}
int update(int i,int j){
    fa[query(i)]=query(j);
}
int init(int l){
    while(l--)fa[l]=l;
}
int a[100010];
bool f(int i,int j){
    if(s[i][j]==1)return 1;
    if(query(i)==query(j)){
        // printf("no:%d %d\n",i,j);
        return 0;
    }
    update(i,j);
    s[i][j] = s[j][i] = 1;
    // printf("set:%d %d\n",i,j);
    return f(a[i],a[j]);
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i = 0;i<n+5;i++){
            s[i].clear();
            s[i].resize(n+10);
        }
        for(int i = 1;i<=n;i++){
            scanf("%d",a+i);
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<i;j++){
                init(n+5);
                if(!f(i,j)){
                    goto no;
                }
            }
        }
        printf("Yes\n");
        continue;
        no:
        printf("No\n");
        continue;
    }
}