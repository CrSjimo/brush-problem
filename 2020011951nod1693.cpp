#include<stdio.h>
#include<vector>
#include<queue>
#define DEBUG
struct Edge{
    char dist;
    int next;
    Edge(){}
    Edge(char dist,int next){
        this->dist = dist;
        this->next = next;
    }
    bool operator<(const Edge& e)const{
        return dist>e.dist;
    }
};
std::vector< std::vector<Edge> > G;
std::vector<char> dist;
int n,m,s,t;
void dijstra(){
    std::priority_queue<Edge> q;
    q.push(Edge(0,s));
    dist[s] = 0;
    while(!q.empty()){
        Edge tmp = q.top();q.pop();
        if(tmp.next==t)return;
        if(dist[tmp.next]<tmp.dist)continue;
        for(int i = 0;i<G[tmp.next].size();i++){
            Edge e = G[tmp.next][i];
            if(dist[e.next]>dist[tmp.next]+e.dist){
                dist[e.next]=dist[tmp.next]+e.dist;
                e.dist = dist[e.next];
                q.push(e);
            }
        }
    }
}
std::vector<int> prime;
void init_prime(int k){
    int i=2;
    while(k){
        for(int j=2;j*j<=i;j++){
            if(i%j==0)goto nxt;
        }
        prime.push_back(i);
        k--;
        nxt:
        i++;
    }
}
int main(){
    init_prime(15);
    scanf("%d",&t);
    n=t+6;
    G.resize(n+5);
    dist = std::vector<char>(n+5,127);
    for(int i=2;i<=n;i++){
        G[i].push_back(Edge(1,i-1));
    }
    for(int k=1;k<=n;k++){
        for(int i=0;i<6;i++){
            if(prime[i]*k>n)break;
            G[k].push_back(Edge(prime[i],prime[i]*k));
        }
    }
    s=1;
    dijstra();
    printf("%d\n",dist[t]);
    return 0;
}