//trie
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
struct Node{
    int v[10];
    bool tag;
} b [100010];
int tot=1;
int rt = 1;
bool insert(const char* s){
    int p=rt;
    bool flag=false;
    for(;*s;s++){
        char w=*s-'0';
        // printf("test: %d %d\n",w,p);
        if(b[p].tag==true)return false;
        if(!b[p].v[w]){
            b[p].v[w]=++tot;
            // printf("test1: %d %d %d\n",p,w,tot);
            flag=true;
        }else{
            // printf("test2: %d\n",b[p].v[w]);
        }
        p=b[p].v[w];
    }
    b[p].tag=true;
    return flag;
}
char a[10010][11];
int main(){
    int cas;scanf("%d",&cas);
    while(cas--){
        tot=1;
        memset(b,0,sizeof(b));
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%s",a[i]);
        }
        for(int i=1;i<=n;i++){
            if(!insert(a[i])){
                printf("NO\n");
                goto nex;
            }
            // printf("test1\n");
        }
        printf("YES\n");
        nex:;
    }
    return 0;
}