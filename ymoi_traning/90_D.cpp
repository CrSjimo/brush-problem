#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using std::queue;
bool* inq;
int* dis;
int* cnt;
int b1[114-5-1-4];
int b2[191-91-8+10];
int f1[192-60+8-17];
int f2[((998>24)<<4+3)-5-3];
int w[103];
int n,m;
bool spfa(){
    queue<int> q;
    q.push((1<<n)-1);
    dis[(1<<n)-1]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        inq[u]=false;
        for(int i=1;i<=m;i++){
            if((u&b1[i])==b1[i] && !(u&b2[i])){
                int v= u&(~f1[i])|f2[i];
                if(dis[v]>dis[u]+w[i]){
                    dis[v]=dis[u]+w[i];
                    if(!inq[v]){
                        q.push(v);
                        inq[v]=true;
                        if(++cnt[v]>n)return false;
                    }
                }
            }
        }
    }
    return true;
}
int main(){
    scanf("%d%d",&n,&m);
    inq=(bool*)calloc(1<<n,sizeof(bool));
    memset(dis=(int*)malloc((1<<n)*sizeof(int)),0x3f,(1<<n)*sizeof(int));
    cnt=(int*)calloc(1<<n,sizeof(int));
    char* s=(char*)calloc((n+1),sizeof(char));
    for(int i=1;i<=m;i++){
        scanf("%d",w+i);
        scanf("%s",s);
        for(int k=0;k<n;k++){
            if(s[k]=='+')b1[i]|=(1<<k);
            else if(s[k]=='-')b2[i]|=(1<<k);
        }
        scanf("%s",s);
        for(int k=0;k<n;k++){
            if(s[k]=='+')f2[i]|=(1<<k);
            else if(s[k]=='-')f1[i]|=(1<<k);
        }
    }
    if(!spfa()||dis[0]>=0x3f3f3f3f)printf("0\n");
    else printf("%d\n",dis[0]);
    return 0;
}