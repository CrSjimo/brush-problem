#include<cstdio>
#include<cstdlib>
#include<cstring>
const int MAXN = 1e6+7;
char t[MAXN];
int nex[MAXN];
int m;
void init(){
    nex[0]=-1;nex[1]=0;
    for(int i=2;i<=m;i++){
        int j=nex[i-1];
        while(j!=-1&&t[i]!=t[j+1]){
            j=nex[j];
        }
        nex[i]=j+1;
    }
}
int main(){
    while(~scanf("%s",t+1)){
        memset(nex,0,sizeof(nex));
        if(t[1]=='.'&&t[2]==0)return 0;
        m=strlen(t+1);
        init();
        // printf("test: %d\n",nex[m]);
        int block=m-nex[m];
        // printf("test: %d\n",block);
        printf("%d\n",m%block?1:m/block);

    }
    return 0;
}