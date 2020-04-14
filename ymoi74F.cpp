#include<cstdio>
#include<cstdlib>
#include<queue>
using std::priority_queue;
using std::vector;
using std::greater;
int* a;
int* b;
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    a=(int*)malloc((n+1)*sizeof(int));
    b=(int*)malloc((m+1)*sizeof(int));
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=m;i++)scanf("%d",b+i);
    int j=1;
    priority_queue< int,vector<int>,greater<int> > hp1;
    priority_queue<int> hp2;
    for(int i=1;i<=m;i++){
        for(;j<=b[i];j++){
            hp1.push(a[j]);
        }
        hp2.push(hp1.top());hp1.pop();
        while(!hp1.empty() && hp1.top()<hp2.top()){
            int hp1top = hp1.top();hp1.pop();
            int hp2top = hp2.top();hp2.pop();
            hp1.push(hp2top);
            hp2.push(hp1top);
        }
        printf("%d\n",hp2.top());
    }
    return 0;
}