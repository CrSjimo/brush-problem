#include<cstdio>
#include<cstdlib>
#include<deque>
#include<algorithm>
#include<cmath>
using std::sort;
using std::max;
using std::deque;
int n,m,q,u,v,t;
int* a;
deque<int> qA;
deque<int> q1;
deque<int> q2;
const int INF = 0x7fffffff;
inline int pop(){
    int x;
    int a=(!qA.empty())?qA.front():-INF;
    int b=(!q1.empty())?q1.front():-INF;
    int c=(!q2.empty())?q2.front():-INF;
    if(a>=b&&a>=c){
        qA.pop_front();
        return a;
    }else if(b>=a&&b>=c){
        q1.pop_front();
        return b;
    }else{
        q2.pop_front();
        return c;
    }
}
int main(){
    scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
    double p=1.0*u/v;
    a=(int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        qA.push_front(a[i]);
    }
    int Q=0;
    for(int i=1;i<=m;i++){
        int x=pop();
        int nowX=x+Q;
        Q+=q;
        if(i%t==0)printf("%d ",nowX);
        int a1=(int)(p*nowX),a2=nowX-a1;
        // printf("\ntest: %d %d\n",(int)(p*nowX),nowX-(int)(p*nowX));
        q1.push_back(a1-Q);
        q2.push_back(a2-Q);
    }
    printf("\n");
    for(int i=1;;i++){
        int x=pop();
        if(x==-INF)break;
        if(i%t==0)printf("%d ",x+Q);
    }
    printf("\n");
    return 0;
}