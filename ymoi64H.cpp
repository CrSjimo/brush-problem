#include<cstdio>
#include<cstdlib>
#include<queue>
#include<vector>
using std::vector;
using std::queue;
queue<int> q;
int i=0;
int cnt = 0;
int a[100005];
std::vector<int> ta;
std::vector<int> na_of;
int main(){
    int n;
    scanf("%d",&n);
    for(int k=0;k<n;k++){
        int t,m;
        scanf("%d%d",&t,&m);
        for(int j=0;j<m;j++){
            int x;
            scanf("%d",&x);
            na_of.push_back(x);
            a[x]++;
            if(a[x]==1)cnt++;
            ta.push_back(t);
            q.push(i);
            i++;
        }
        while(t-ta[q.front()]>=86400){
            int ii = q.front();q.pop();
            if(--a[na_of[ii]] == 0)cnt--;
        }
        printf("%d\n",cnt);
    }
    return 0;
}