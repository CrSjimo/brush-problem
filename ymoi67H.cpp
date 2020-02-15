#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<functional>
using std::stable_sort;
using std::greater;
struct Node{
    int id;
    int v;
    bool operator<(const Node& nd)const{
        return nd.v<v;
    }
}* a;
int* w;
int main(){
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    n<<=1;
    a = (Node*)malloc((n+1)*sizeof(Node));
    w = (int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].v);
        a[i].id = i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",w+i);
    }
    stable_sort(a+1,a+n+1);
    for(int i=1;i<=m;i++){
        for(int i=1;i<=n;i+=2){
            if(w[i]>w[i+1]){
                a[i].v+=1;
            }else{
                a[i+1].v+=1;
            }
        }
        stable_sort(a+1,a+n+1);
    }
    printf("%d\n",a[q].id);
    return 0;
}