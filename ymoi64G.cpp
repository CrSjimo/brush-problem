#include<cstdio>
#include<cstdlib>
#include<queue>
using std::queue;
int* a;
bool* inq;
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    a = (int*)malloc(n*sizeof(int));
    inq = (bool*)malloc(1005*sizeof(bool));
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    queue<int> q;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(!inq[a[i]]){
            cnt++;
            q.push(a[i]);
            inq[a[i]]=true;
            if(q.size()>m){
                inq[q.front()]=false;
                q.pop();
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}