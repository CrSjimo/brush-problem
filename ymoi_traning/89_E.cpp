#include<cstdio>
#include<cstdlib>
#include<deque>
using std::deque;
int* a;
int main(){
    int n,k;scanf("%d%d",&n,&k);
    a=(int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    deque<int> q1;
    deque<int> q2;
    for(int i=1;i<=n;i++){
        while((!q1.empty())&&i-q1.front()>=k)q1.pop_front();
        while((!q1.empty())&&a[q1.back()]>a[i])q1.pop_back();
        q1.push_back(i);
        if(i<k)continue;
        printf("%d ",a[q1.front()]);
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        while((!q2.empty())&&i-q2.front()>=k)q2.pop_front();
        while((!q2.empty())&&a[q2.back()]<a[i])q2.pop_back();
        q2.push_back(i);
        if(i<k)continue;
        printf("%d ",a[q2.front()]);
    }
    printf("\n");
    return 0;
}