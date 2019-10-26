//no variable name comments
/*
 * @see my bilibili column article
 */
#include<stdio.h>
#include<algorithm>
struct Node{
    int start,interval,cnt;
} a[2048];
bool cmp(const Node a,const Node b){
    return a.cnt > b.cnt;
}
int b[60+10];
bool canHave(int t,int interval){
    while(t<60){
        if(!b[t]){
            return 0;
        }
        t += interval;
    }
    return 1;
}
int ans,m = 0,n;
void dfs(int k,int sum,int nt_num){
    if(nt_num >= n){
        ans = std::min(sum,ans);
        return;
    }
    for(int i = k;i<m;i++){
        if(!canHave(a[i].start,a[i].interval)){
            continue;
        }

        if(sum + (n - nt_num) / a[i].cnt >= ans) return;
        //Cyka Blyat  The fucking optmize
        
        for(int j = a[i].start;j<60;j+=a[i].interval){
            b[j]--;
        }
        dfs(i,sum+1,nt_num+a[i].cnt);
        for(int j = a[i].start;j<60;j+=a[i].interval){
            b[j]++;
        }
    }
    return;
}
int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int t;
        scanf("%d",&t);
        b[t]++;
    }
    for(int i = 0;i<60/2;i++){
        for(int j = i+1;j<60-i;j++){
            if(canHave(i,j)){
                a[m].start = i;
                a[m].interval = j;
                for(int t = i;t<60;t+=j){
                    a[m].cnt++;
                }
                m++;
            }
        }
    }
    std::sort(a,a+m,cmp);//seemed to have some optmize use
    //but don't know how to use;
    ans = 17;
    dfs(0,0,0);
    printf("%d\n",ans);
    return 0;
}