#include<cstdio>
#include<cstdlib>
int* s;
int* color;
int main(){
    int n,k,p;scanf("%d%d%d",&n,&k,&p);
    s=(int*)calloc(k,sizeof(int));
    color=(int*)malloc((n+1)*sizeof(int));
    int tmp = 0;
    int ans=0;
    for(int i=1;i<=n;i++){
        int pr;scanf("%d%d",color+i,&pr);
        if(pr<=p){
            for(int k=i;k>tmp;k--){
                s[color[k]]+=1;
            }
            tmp=i;
            ans+=s[color[i]]-1;
        }else{
            ans+=s[color[i]];
        }
    }
    printf("%d\n",ans);
    return 0;
}