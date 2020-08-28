#include<cstdio>
#include<cstdlib>
#include<string>
using std::string;
#include<algorithm>
#include<cstring>
using std::sort;
using std::greater;
struct Node{
    Node* v[10];
    bool tag;
} b [100010];
int tot=1;
Node* rt = b+(tot++);
void insert(const char* s){
    Node* p=rt;
    for(;*s;s++){
        char w=*s-'0';
        if(!p->v[w])p->v[w]=b+(tot++);
        p=p->v[w];
    }
    p->tag=true;
}
bool find(const char* s){
    Node* p=rt;
    for(;*s;s++){
        char w=*s-'0';
        if(!p->v[w])return false;
        p=p->v[w];
    }
    return true;
}
string a[10010];
char tmp[11];
int main(){
    int cas;scanf("%d",&cas);
    while(cas--){
        tot=0;
        memset(b,0,sizeof(b));
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%s",tmp);
            a[i]=tmp;
        }
        sort(a+1,a+1+n,greater<string>());
        for(int i=1;i<=n;i++){
            if(find(a[i].c_str())){
                printf("NO\n");
                goto nex;
            }
            insert(a[i].c_str());
        }
        printf("YES\n");
        nex:;
    }
    return 0;
}