#include<cstdio>
#include<vector>
#include<algorithm>
using std::vector;
using std::sort;

const int MAXN = 114514;

bool np[MAXN];
int prime[MAXN];
int tot=0;

void euler_sieve(int x){
    for(int i=2;i<=x;i++){
        if(!np[i]){
            prime[++tot]=i;
        }
        for(int j=1;j<=tot&&i*prime[j]<=x;j++){
            int p=prime[j];
            np[i*p]=true;
            if(i%p==0){
                break;
            }
        }
    }
}
vector<int> anses;
bool is_prime(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}
void dfs(int s,int pre,int now_ans){
    if(s==1){
        anses.push_back(now_ans);
        return;
    }
    if(is_prime(s-1)&&prime[pre]<s-1){
        dfs(1,114514,now_ans*(s-1));
    }
    for(int i=pre+1;i<=tot&&prime[i]*prime[i]<=s;i++){
        for(
            int p=prime[i],pk=p+1;
            pk<=s;
            p*=prime[i],pk+=p
        ){
            if(s%pk==0){
                dfs(s/pk,i,now_ans*p);
            }
        }
    }
}
int main(){
    euler_sieve(MAXN);
    int s;
    while(~scanf("%d",&s)){
        anses.clear();
        dfs(s,0,1);
        sort(anses.begin(),anses.end());
        int len=anses.size();
        printf("%d\n",len);
        if(!len)continue;
        for(int i=0;i<len;i++){
            printf("%d ",anses[i]);
        }
        printf("\n");
    }
    return 0;
}