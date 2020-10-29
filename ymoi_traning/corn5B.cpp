#include<cstdio>
#include<cstdlib>
#include<set>
using std::set;
#include<utility>
typedef std::pair<int,int> pii;
using std::make_pair;
using std::swap;
set<pii> st;
const int MOD=998244353;
typedef long long ll;
int C[1005][1005];
void dabiao(){
    C[0][0]=C[1][0]=C[1][1]=1;
    for(int i = 2;i<=1000;i++){
        C[i][0]=1;
        for(int j=1;j<=1000;j++){
            C[i][j]=(C[i-1][j-1]%MOD+C[i-1][j]%MOD)%MOD;
        }
    }
}
ll ksm(ll a,ll b){
    ll ans=1;
    for(;b;(a*=a)%=MOD,b>>=1){
        if(b&1)(ans*=a)%=MOD;
    }
    return ans;
}

template<typename T>T*&alloc(T*&a,size_t siz){
    return a=(T*)calloc((siz+1),sizeof(T));
}

int* a;
int* comb;
int* vis;
int n;
ll ans=0;
bool cfl(int i,int j){
    for(int k = 1;k<i;k++){
        pii pr = make_pair(comb[k],j);
        if(pr.first>pr.second){
            swap(pr.first,pr.second);
        }
        if(st.count(pr))return true;
    }
    return false;
}
void dfs(int i){
    if(i>n+1)return;
    ans++;ans%=MOD;
    // fprintf(stderr,"test: ");
    // for(int k=1;k<=i-1;k++){
    //     fprintf(stderr,"%d ",comb[k]);
    // }
    // fprintf(stderr,"\n");
    for(int j=comb[i-1]+1;j<=n;j++){
        if(!vis[j]){
            if(cfl(i,j))continue;
            vis[j]=1;
            comb[i]=j;
            dfs(i+1);
            vis[j]=0;
        }
    }
}
int* vis2;
void dfs2(int i,int s,int t){
    if(i>t-s)return;
    for(int j=comb[i-1]+1;j<t;j++){
        if(!vis2[j]&&!st.count(make_pair(s,j))){
            vis2[j]=1;
            comb[i]=j;
            comb[i+1]=t;
            vis[j]=vis[t]=1;
            dfs(i+2);
            vis[j]=vis[t]=0;
            dfs2(i+1,s,t);
            vis2[j]=0;
        }
    }
}

int main(){
    freopen("wsa.in","r",stdin);
    freopen("wsa.out","w",stdout);
    scanf("%d",&n);
    alloc(a,n+1);
    alloc(comb,n+1);
    alloc(vis,n+1);
    alloc(vis2,n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]==j||a[j]==i){
                st.insert(make_pair(i,j));
            }
        }
    }
    dfs(1);
    //fprintf(stderr,"test: %ld\n",st.size());
    // int i=0;
    // for(set<pii>::iterator p = st.begin();p!=st.end();p++,i++){
    //     int x1=p->first,x2=p->second;
    //     int num = n-x2;
    //     for(int i=1;i<x1;i++){
    //         if(vis[i]==0)num++;
    //     }
    //     for(int i=x1+1;i<x2;i++){
    //         if(comb[i]==0)num++;
    //     }
    //     ans+=ksm(2,num);
    //     ans%=MOD;
    //     //if(i%100==0)fprintf(stderr,"test: %d\n",i);
    // }
    printf("%lld\n",((ans)%MOD+MOD)%MOD);
    return 0;
}