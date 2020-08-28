#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cctype>
using std::max;
using std::min;
int* lg;
int** st;
int** st2;
int getint(){
    int x=0,k=1;
    int c = 1919810;
    while(!isdigit(c)){
        c=getchar();
        if(c=='-')k=-1;
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*k;
}
void _putint(int x,bool t){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x==0&&t)return;
    _putint(x/10,1);
    putchar(x%10+'0');
}
void putint(int x){
    _putint(x,0);
}
void init(int n){
    lg=(int*)calloc((n+1),sizeof(int));
    lg[1]=0;
    for(int i=2;i<=n;i++){
        lg[i]=lg[i>>1]+1;
    }
    st=(int**)malloc((n+1)*sizeof(int*));
    st2=(int**)malloc((n+1)*sizeof(int*));
    int L=lg[n];
    for(int i=1;i<=n;i++){
        st[i]=(int*)calloc((L+1),sizeof(int));
        st2[i]=(int*)calloc((L+1),sizeof(int));
        st[i][0]=st2[i][0]=getint();
    }
    for(int j=0;j+1<=L;j++){
        for(int i=1;i+((1<<(j+1)))-1<=n;i++){
            st[i][j+1]=max(st[i][j],st[i+(1<<j)][j]);
            st2[i][j+1]=min(st2[i][j],st2[i+(1<<j)][j]);
        }
    }
}
int query(int l,int r){
    int L=lg[r-l+1];
    return max(st[l][L],st[r-(1<<L)+1][L])-min(st2[l][L],st2[r-(1<<L)+1][L]);
}
int main(){
    int n=getint(),m=getint();
    init(n);
    while(m--){
        int l=getint(),r=getint();
        putint(query(l,r));
        putchar('\n');
    }
    return 0;
}
