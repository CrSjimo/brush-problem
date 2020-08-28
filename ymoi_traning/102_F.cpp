#include<cstdio>
#include<cstdlib>
#include<cstring>
const int MAXN = 1e6+7;
const int MOD = 1e9+7;
char t[MAXN];
int nex[MAXN];
int cnt[MAXN];
int m;
void init(){
    nex[0]=-1;nex[1]=0;cnt[1]=1;
    for(int i=2;i<=m;i++){
        int j=nex[i-1];
        while(j!=-1&&t[i]!=t[j+1]){
            j=nex[j];
        }
        nex[i]=j+1;
        cnt[i]=cnt[j+1]+1;
    }
}
int main(){
    int cas;scanf("%d",&cas);
    while(cas--){
        memset(nex,0,sizeof(nex));
        memset(cnt,0,sizeof(cnt));
        scanf("%s",t+1);
        m=strlen(t+1);
        init();
        // for(int i=1;i<=m;i++){
        //     printf("%d ",cnt[i]);
        // }
        // printf("\n");
        long long ans=1;
        for(int i=1,j=0;i<=m;i++){
            while(j!=-1&&t[i]!=t[j+1])j=nex[j];
            j++;
            while(j>i/2)j=nex[j];
            ans*=(cnt[j]+1);
            ans%=MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}