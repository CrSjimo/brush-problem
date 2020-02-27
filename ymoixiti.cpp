#include<cstdio>
#include<cstdlib>
#include<queue>
using std::queue;
#include<set>
using std::set;
int* a;
set<int> inq;
int m,n;
int main(){
    scanf("%d%d",&m,&n);
    a = (int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    queue<int> q;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(!inq.count(a[i])){
            cnt++;
            q.push(a[i]);
            inq.insert(a[i]);
            if(q.size()>m){
                inq.erase(q.front());
                q.pop();
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}