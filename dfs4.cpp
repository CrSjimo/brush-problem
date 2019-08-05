#include<stdio.h>
#include<algorithm>
struct Node{
    int start,interval,cnt;
} arr[2048];
bool cmp(const Node a,const Node b){
    return a.cnt > b.cnt;
}
int cnt[60+10];
bool canHave(int t,int interval){
    while(t<60){
        if(!cnt[t]){
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
        if(!canHave(arr[i].start,arr[i].interval)){
            continue;
        }

        if(sum + (n - nt_num) / arr[i].cnt >= ans) return;
        //Cyka Blyat  The fucking optmize
        
        for(int j = arr[i].start;j<60;j+=arr[i].interval){
            cnt[j]--;
        }
        dfs(i,sum+1,nt_num+arr[i].cnt);
        for(int j = arr[i].start;j<60;j+=arr[i].interval){
            cnt[j]++;
        }
    }
    return;
}
int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int t;
        scanf("%d",&t);
        cnt[t]++;
    }
    for(int i = 0;i<60/2;i++){
        for(int j = i+1;j<60-i;j++){
            if(canHave(i,j)){
                arr[m].start = i;
                arr[m].interval = j;
                for(int t = i;t<60;t+=j){
                    arr[m].cnt++;
                }
                m++;
            }
        }
    }
    std::sort(arr,arr+m,cmp);//seemed to have some optmize use
    //but don't know how to use;
    ans = 17;
    dfs(0,0,0);
    printf("%d\n",ans);
    return 0;
}