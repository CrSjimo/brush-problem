#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<cstring>
using std::max;
struct Node{
    int v[2];
    bool tag;
} b [400010*32];
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
int s[400010];
int a[400010];
int l[400010];
int r[400010];
int main(){
    int n;scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    insert(0);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]^a[i];
        insert(s[i]);
        // printf("test: %d\n",s[i]);
        l[i]=max(l[i-1],find(s[i]));
        // printf("test1: %d\n",l[i]);
    }
    memset(b,0,sizeof(b));
    insert(0);
    for(int i=n;i>=0;i--){
        s[i]=s[i+1]^a[i];
        insert(s[i]);
        // printf("test: %d\n",s[i]);
        r[i]=max(r[i+1],find(s[i]));
        // printf("test1: %d\n",r[i]);
    }
    for(int i=1;i<=n-1;i++){
        ans=max(ans,l[i]+r[i+1]);
    }
    printf("%d\n",ans);
    return 0;
}