#include<cstdio>
#include<cstdlib>
#include<algorithm>
using std::min;
char* s;
int* pos[4];
int cnt[4];
int main(){
    int n,k;scanf("%d%d",&n,&k);
    s=(char*)malloc((n+2)*sizeof(char));
    for(int i=1;i<=3;i++)pos[i]=(int*)calloc((n+1),sizeof(int));
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='J')pos[1][++cnt[1]]=i;
        if(s[i]=='O')pos[2][++cnt[2]]=i;
        if(s[i]=='I')pos[3][++cnt[3]]=i;
    }
    int ptr_o = 1,ptr_i = 1;
    int ans = 0x3f3f3f3f;
    for(int i=1;i+k-1<=cnt[1];i++){
        int rJ = pos[1][i+k-1];
        while(ptr_o<=cnt[2]&&pos[2][ptr_o]<=rJ)ptr_o++;
        if(ptr_o+k-1>cnt[2])break;
        int rO = pos[2][ptr_o+k-1];
        while(ptr_i<=cnt[3]&&pos[3][ptr_i]<=rO)ptr_i++;
        if(ptr_i+k-1>cnt[3])break;
        //printf("test: %d %d\n",pos[3][ptr_i+k-1],pos[1][i]);
        ans = min(ans,pos[3][ptr_i+k-1]-pos[1][i]+1-k*3);
    }
    printf("%d\n",ans==0x3f3f3f3f?-1:ans);
    return 0;
}