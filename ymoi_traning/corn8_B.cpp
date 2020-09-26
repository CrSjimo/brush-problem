#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::reverse;
const int MAXN=1e6+5;
struct Node{
    int v[26];
    int cnt;
    bool tag;
} b1[MAXN];
Node b2[MAXN];
int tot1=1;
int tot2=1;
int rt=1;
void insert(const char* s,Node* b,int& tot){
    int p=rt;
    for(;*s;s++){
        b[p].cnt++;
        char w=*s-'a';
        if(!b[p].v[w])b[p].v[w]=(++tot);
        p=b[p].v[w];
    }
    b[p].tag=true;
}
int find(const char* s,Node* b){
    int p=rt;
    for(;(*s)&&(*s!='*');s++){
        char w=*s-'a';
        if(!b[p].v[w])return 0;
        p=b[p].v[w];
    }
    return b[p].cnt;
}
int n,m;
#define OJ
char s[MAXN];
int main(){
    #ifdef OJ
    freopen("regex.in","r",stdin);
    freopen("regex.out","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        insert(s,b1,tot1);
        reverse(s,s+strlen(s));
        insert(s,b2,tot2);
    }
    while(m--){
        int ans=0;
        scanf("%s",s);
        if(s[0]=='*'){
            reverse(s,s+strlen(s));
            ans+=find(s,b2);
        }else{
            ans+=find(s,b1);
        }
        printf("%d\n",ans);
    }
    return 0;
}