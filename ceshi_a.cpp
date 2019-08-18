#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define MAXN 2020
int arr[MAXN];
struct Edge{
    int pre1;
    int pre2;
    int dist;
};
int query(int i){
    if(arr[i] == i){
        return i;
    }
    return arr[i] = query(arr[i]);
}
void update(int i,int j){
    int aliasI = query(i);
    int aliasJ = query(j);
    arr[aliasI] = aliasJ;
}
void init(int len){
    while(len--){
        arr[len] = len;
    }
}
Edge elist[MAXN*MAXN/2];
char s[MAXN][10];
int n,cnt;
bool cmp(Edge e1,Edge e2){
    return e1.dist < e2.dist;
}
int calc(){
    int eNum = 0;
    std::sort(elist,elist+cnt,cmp);
    int ans = 0;
    for(int i = 0;i<cnt && eNum<n-1;i++){
        Edge e = elist[i];
        if(query(e.pre1) != query(e.pre2)){
            update(e.pre1,e.pre2);
            ans += e.dist;
            eNum++;
        }
    }
    return ans;
}
int calc2(char* s1,char* s2){
    int ans = 0;
    int len = strlen(s1);
    for(int i = 0;i<len;i++){
        if(s1[i]!=s2[i]){
            ans++;
        }
    }
    return ans;
}
int main(){
    while(~scanf("%d",&n) && n){
        memset(elist,0,sizeof(elist));
        init(n+10);
        cnt = 0;
        for(int i = 0;i<n;i++){
            scanf("%s",s[i]);
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                Edge e;
                e.pre1 = i;
                e.pre2 = j;
                e.dist = calc2(s[i],s[j]);
                elist[cnt++] = e;
            }
        }
        printf("The highest possible quality is 1/%d.\n",calc());
    }
    return 0;
}