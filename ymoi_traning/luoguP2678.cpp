#include<cstdio>
#include<cstdlib>
int* a;
int n,m;
bool cando(int lim){
    int cnt=0;
    for(int i=1,pos=0;i<=n+1;i++){
        if(a[i]-a[pos]<lim){
            cnt++;
        }else{
            pos=i;
        }
    }
    return cnt<=m;
}
int ans = 0;
int bs(int l,int r){
    if(l==r)return r-1;
    int mid = (l+r)>>1;
    if(cando(mid)){
        return bs(mid+1,r);
    }else{
        return bs(l,mid);
    }
}
int main(){
    int l;
    scanf("%d%d%d",&l,&n,&m);
    a=(int*)malloc((n+2)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    a[0]=0,a[n+1]=l;
    printf("%d\n",bs(0,l+1));
    return 0;
}