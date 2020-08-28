#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<cstring>
using std::max;
struct Node{
    int v[2];
    bool tag;
} b [3300010];
int tot=1;
int rt = 1;
void insert(int x){
    int p=rt;
    for(int i=31;i>=0;i--){
        char w=(x>>i)&1;
        if(!b[p].v[w])b[p].v[w]=(++tot);
        p=b[p].v[w];
    }
    b[p].tag=true;
}
int find(int x){
    int p=rt;
    int ans=0;
    for(int i=31;i>=0;i--){
        char w=(x>>i)&1;
        if(b[p].v[w^1]){
            p=b[p].v[w^1];
            ans|=(1<<i);
        }else if(b[p].v[w]){
            p=b[p].v[w];
        }else return ans;
    }
    return ans;
}
int main(){
    int n;scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        ans=max(ans,find(k));
        insert(k);
    }
    printf("%d\n",ans);
    return 0;
}