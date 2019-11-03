#include<stdio.h>
#include<algorithm>
#include<vector>
typedef long long ll;
int n;
int a,b;
int arr[1010];
int brr[1010];
struct Node{
    int a,b;
} list[1010];
std::vector<Node> res;
bool cmp(Node n1,Node n2){
    // if(n1.a*n1.b==n2.a*n2.b){
        return n1.a<n2.a;
    // }
    // return n1.a*n1.b<n2.a*n2.b;
}
bool cmp2(Node n1,Node n2){
    return n1.b<n2.b;
}
ll tmp[1010];
bool cando(ll x){
    //printf("test-cando:%lld\n",x);
    for(int i=1;i<=n;i++){
        tmp[i]=list[i].b*x;
    }
    ll asum = a;
    Node* bmin = std::min_element(list+1,list+n+1,cmp2);
    for(int i=1;i<=n;i++){
        bool flag = 1;
        for(int j = 1;j<i;j++){
            asum*=list[i].a;
        }
        if(asum>bmin->b){

        }else{
            res.push_back(list[i]);
        }
    }
}
void bs(ll l,ll r){
    ll m=l+((r-l)/2);
    if(l==r){
        printf("%lld\n",l);
        return;
    }
    if(cando(m)){
        bs(l,m);
    }else{
        bs(m+1,r);
    }

}
const ll MAXN = 1e14;
int main(){
    scanf("%d%d%d",&n,&a,&b);
    for(int i = 1;i<=n;i++){
        // scanf("%d%d",arr+i,brr+i);
        scanf("%d%d",&list[i].a,&list[i].b);
    }
    std::sort(list+1,list+n+1,cmp);
    // ll ans = -1;
    // for(int i = 1;i<=n;i++){
    //     ll maxn = a;
    //     for(int j = 1;j<i;j++){
    //         maxn*=list[j].a;
    //     }
    //     ans = std::max(ans,maxn/list[i].b);
    // }
    bs(0,MAXN);
    // printf("%lld\n",ans);
    return 0;
}