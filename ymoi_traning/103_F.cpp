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
} b [100010];
int tot=1;
int rt = 1;
void insert(const char* s){
    int len=strlen(s);
    int p=rt;
    for(;*s;s++){
        char w=*s-'a';
        if(!b[p].v[w])b[p].v[w]=(++tot);
        p=b[p].v[w];
    }
    b[p].tag=len;
}
int n;
char s[100010];
char tmp[100010];
void init(){
    for(int i=0;i<D;i++){
        b[0].v[i]=rt;
    }
    b[rt].fail=0;
    for(int i=1;i<=n;i++){
        scanf("%s",tmp);
        insert(tmp);
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
char st[100010];
int jmp[100010];
int top=0;
void find(){
    int ans=0;
    int j=rt;
    for(int i=0;s[i];i++){
        st[++top]=s[i];
        char w=s[i]-'a';
        j=b[j].v[w];
        jmp[top]=j;
        if(b[j].tag){
            top-=b[j].tag;
            j=jmp[top];
        }
        // printf("test: %c %d\n",w+'a',j);
    }
    st[++top]=0;
}
int main(){
    const int Mem_MiB=(sizeof(b)+sizeof(s))/(1<<20);
    scanf("%s",s);
    scanf("%d",&n);
    init();
    find();
    printf("%s\n",st+1);
    return 0;
}