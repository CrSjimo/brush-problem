//AC Aut
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
using std::queue;
const int D=26;
struct Node{
    int v[D];
    int tag;
    int fail;
} b [1000000];
int tot=1;
int rt = 1;
void insert(const char* s){
    int p=rt;
    for(;*s;s++){
        char w=*s-'a';
        if(!b[p].v[w])b[p].v[w]=(++tot);
        p=b[p].v[w];
    }
    b[p].tag++;
}
char a[10005][51];
int n;
char s[1000005];
void init(){
    memset(b,0,sizeof(b));
    tot=1;
    for(int i=0;i<D;i++){
        b[0].v[i]=rt;
    }
    b[rt].fail=0;
    for(int i=1;i<=n;i++){
        insert(a[i]);
    }
    queue<int> q;
    q.push(rt);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<D;i++){
            if(!b[u].v[i]){
                b[u].v[i]=b[b[u].fail].v[i];
                continue;
            }
            int j=b[u].fail;
            while(!b[j].v[i])j=b[j].fail;
            b[b[u].v[i]].fail=b[j].v[i];
            q.push(b[u].v[i]);
        }
    }
}
int find(){
    int ans=0;
    int j=rt;
    for(int i=0;s[i];i++){
        char w=s[i]-'a';
        j=b[j].v[w];
        for(int k=j;k&&b[k].tag!=-1;k=b[k].fail){
            ans+=b[k].tag;
            b[k].tag=-1;
        }
        // printf("test: %c %d\n",w+'a',j);
    }
    return ans;
}
int main(){
    int cas;scanf("%d",&cas);
    const int Mem_MiB=(sizeof(b)+sizeof(a)+sizeof(s))/(1<<20);
    while(cas--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%s",a[i]);
        }
        scanf("%s",s);
        init();
        printf("%d\n",find());
    }
    return 0;
}