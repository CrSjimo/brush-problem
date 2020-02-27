#include<cstdio>
#include<cstdlib>
#include<cstring>
char* s;
char dfs(int l,int r,int o){//[l,r)
    if(r-l==1){
        //fprintf(stderr,"t:%d %d ",l,r);
        if(s[l]=='1'){
            printf("I");
        }else{
            printf("B");
        }
        return s[l];
    }else{
        int m=(l+r)>>1;
        char x1=dfs(l,m,o<<1);
        char x2=dfs(m,r,o<<1|1);
        // fprintf(stderr,"t:%d %d %c %c ",l,r,x1,x2);
        if(x1!=x2||x1=='-'){
            printf("F");
            return '-';
        }else if(x1=='1'){
            printf("I");
            return '1';
        }else if(x1=='0'){
            printf("B");
            return '0';
        }
    }
}
int main(){
    int n;scanf("%d",&n);
    s=(char*)malloc((1<<n|1)*sizeof(char));
    scanf("%s",s);
    dfs(0,1<<n,1);
    printf("\n");
    return 0;
}