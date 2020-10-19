#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;

const int MAXN = 1e7+10;
const int MOD = 1e9+7;
bool not_prime[MAXN];
int prime[MAXN];
int tot = 0;
vector< vector<int> > decomp;

void eulerSieve(int x){
    for(int i=2;i<=x;i++){
        if(!not_prime[i])prime[++tot]=i;
        for(int j=1;j<=tot&&i*prime[j]<=x;j++){
            not_prime[i*prime[j]]=true;
            if(i%prime[j]==0){
                break;
            }
        }
    }
}
int*a;
void dec(int i,vector<int>& vec){
    for(int j=1;j<=tot&&prime[j]<=i;j++){
        int p=prime[j];
        if(i%p==0)vec.push_back(p);
        while(i%p==0)i/=p;
    }
}
int main(){
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    not_prime[1]=true;
    eulerSieve(MAXN-5);
    int n,m;scanf("%d%d",&n,&m);
    a=(int*)malloc((n+1)*sizeof(int));
    decomp.resize(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        dec(a[i],decomp[i]);
        // fprintf(stderr,"test%d: ",a[i]);
        // for(int x:decomp[i]){
        //     fprintf(stderr,"%d ",x);
        //     if(a[i]%x)return 32;
        // }
        // fprintf(stderr,"\n");
    }
    while(m--){
        int l,r;scanf("%d%d",&l,&r);
        int ans=0;
        for(int i=l;i<=r;i++){
            if(!not_prime[i]){
                for(int j=1;j<=n;j++){
                    if(a[j]%i==0)(ans+=1)%=MOD;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}