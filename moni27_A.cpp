#include<stdio.h>
#include<map>
#include<algorithm>
std::map<int,int> map;
int knum = 0;
int n,k;
int a[100010];
int start,end;
int maxx=-1;
int maxxid=-1;
int maxn=-1;
void add(int m){
    if(++map[m]==1){
        knum++;
    }
    if(map[m]>maxx){
        maxx=map[m];
        maxxid=m;
    }
}
void rm(int m){
    if(--map[m]==0){
        knum--;
    }
    if(m==maxxid){
        maxx--;
    }
}
void play(){
    start=1;end=0;
    while(end<=n){
        //printf("test:%d %d\n",start,end);
        while(knum<=k+1){
            add(a[++end]);
            if(end>n)goto finish;
        }
        rm(a[end--]);
        //printf("testend:%d %d\n",start,end);
        maxn=std::max(maxx,maxn);
        while(knum>k){
            rm(a[start++]);
            //printf("test2:%d %d\n",a[start-1],knum);
        }
    }
    finish:
    maxn=std::max(maxx,maxn);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++){
        scanf("%d",a+i);
    }
    play();
    printf("%d\n",maxn);
    return 0;
}