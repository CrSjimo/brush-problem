#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
using std::vector;
using std::min;
#include<queue>
#include<cctype>
#include<string>
using std::string;
typedef string buffer;
using std::priority_queue;
struct Edge{
    int w,v;
    Edge(){}
    Edge(int w,int v){
        this->w=w;
        this->v=v;
    }
    bool operator<(const Edge& e)const{
        return w>e.w;
    }
};
vector< vector<Edge> > G;
int* dis;
void dijstra(int s,int t){
    priority_queue<Edge> q;
    q.push(Edge(0,s));
    dis[s]=0;
    while(!q.empty()){
        Edge tmp=q.top();q.pop();
        int u=tmp.v;
        if(u==t)return;
        if(dis[u]<tmp.w)continue;
        for(int i=0;i<G[u].size();i++){
            Edge& e=G[u][i];
            if(dis[e.v]>dis[u]+e.w){
                dis[e.v]=dis[u]+e.w;
                q.push(Edge(dis[e.v],e.v));
            }
        }
    }
}
inline vector<int> read_line(){
    //printf("test:%s\n",line);
    buffer buf;
    vector<int> list;
    for(;;){
        char c=getchar();
        if(isdigit(c)){
            buf.push_back(c);
        }else if(c==' '){
            list.push_back(atoi(buf.c_str()));
            buf.clear();
        }else if(c=='\n'){
            if(!buf.empty()){
                list.push_back(atoi(buf.c_str()));
            }
            break;
        }
    }
    return list;
}
int main(){
    int c,n;
    scanf("%d%d",&c,&n);
    dis=(int*)malloc((n+1)*sizeof(int));
    memset(dis,0x3f,(n+1)*sizeof(int));
    G.resize(n+1);
    while(c--){
        vector<int> list = read_line();
        if(list.size()==0)c++;
        for(int i=0;i<list.size();i++){
            for(int j=i+1;j<list.size();j++){
                int u=list[i],v=list[j];
                G[u].push_back(Edge(1,v));
                //printf("test:%d %d\n",u,v);
            }
        }
    }
    dijstra(1,n);
    if(dis[n]<0x3f3f3f3f)printf("%d\n",dis[n]-1);
    else printf("NO\n");
    return 0;
}