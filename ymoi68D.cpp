#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
#include<algorithm>
using std::sort;
using std::swap;
#include<queue>
using std::queue;
int n = 9;
int fac[15] = {1,1,2,6,24,120,720,5040,40320,362880,3628800};
int cantor(int* a){
    int ans = 0,cnt = 0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++)if(a[j]<a[i])cnt++;
        ans+=cnt*fac[n-i];cnt=0;
    }
    return ans;
}
int* decantor(int x){
    int* a = (int*)calloc(n+1,sizeof(int));
    vector<int> tmp(n+1);
    for(int i=1;i<=n;i++)tmp[i-1]=i;
    for(int i=n;i>=1;i--){
        int k = x%fac[i-1];
        int p = x/fac[i-1];
        x = k;
        a[n-i+1]=tmp[p];      
        tmp.erase(tmp.begin()+p);   
    }
    return a;
}
struct Node{
    int a;
    int dis;
    Node(int dis,int a,int p0){
        this->dis=dis;
        this->a = a;
        this->p0 = p0;
    }
    int p0;
};
int op[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
inline bool cando(int i,int k){
    if(i%3==0 && k==3)return false;
    if(i%3==1 && k==2)return false;
    if((i-1)/3==0 && k==1)return false;
    if((i-1)/3==2 && k==0)return false;
    return true;
}
bool* vis;
int bfs(Node s,int t){
    queue<Node> q;
    q.push(s);
    while(!q.empty()){
        Node u = q.front();q.pop();
        // {
        //     printf("%d:\n",u.dis);
        //     int* aa = decantor(u.a);
        //     for(int i=1;i<=9;i++){
        //         printf("%d ",aa[i]);
        //         if(i%3==0)printf("\n");
        //     }
        //     printf("\n");
        // }
        if(u.a==t)return u.dis;
        if(vis[u.a])continue;
        vis[u.a]=true;
        for(int k=0;k<4;k++){
            if(cando(u.p0,k)){
                int* a = decantor(u.a);
                swap(a[u.p0],a[u.p0+3*op[k][0]+op[k][1]]);
                q.push(Node(u.dis+1,cantor(a),u.p0+3*op[k][0]+op[k][1]));
            }
        }
    }
    return -1;
}
int tmpa[10];
int main(){
    vis = (bool*)calloc(fac[9]+5,sizeof(bool));
    // int a[10] = {0,4,5,3,1,2,7,6,8,0};
    // printf("%d\n",cantor(a));
    // int* b = decantor(cantor(a));
    // for(int i=1;i<=9;i++){
    //     printf("%d ",b[i]);
    // }
    // printf("\n");
    int p0;
    for(int i=1;i<=9;i++){
        scanf("%d",&tmpa[i]);
        if(tmpa[i]==0)p0=i;
    }
    Node s(0,cantor(tmpa),p0);
    for(int i=1;i<=9;i++){
        scanf("%d",&tmpa[i]);
    }
    int t = cantor(tmpa);
    int ans = bfs(s,t);
    printf("%d\n",ans);
    return 0;
}