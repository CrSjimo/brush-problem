#include<cstdio>
#include<cstdlib>
#include<cstring>
int ind[105];
int outd[105];
#include<algorithm>
using std::max_element;
#include<vector>
using std::vector;
vector<int> G[105];
int main(){
    memset(ind,0xff,sizeof(ind));
    int x,y;
    while(~scanf("%d%d",&x,&y)){
        if(outd[x]==-1)outd[x]=0;
        if(outd[y]==-1)outd[y]=0;
        if(ind[x]==-1)ind[x]=0;
        if(ind[y]==-1)ind[y]=0;
        outd[x]++;
        ind[y]++;
        G[x].push_back(y);
    }
    for(int i=1;i<=100;i++){
        if(ind[i]==0){
            printf("%d\n",i);
            break;
        }
    }
    int maxn = max_element(outd,outd+101)-outd;
    printf("%d\n",maxn);
    for(int i=0;i<G[maxn].size();i++){
        int v=G[maxn][i];
        printf("%d ",v);
    }
    printf("\n");
    return 0;
}