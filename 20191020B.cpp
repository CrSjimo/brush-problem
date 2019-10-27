#include<stdio.h>
#include<algorithm>
struct TT{
    long long val;
    int id;
};
bool cmp(TT at,TT bt){
    return at.val<bt.val;
}
TT arr[100010],brr[100010];
int map[100010];
const int MOD = 99999997;
int n;
int ans=0;
#include<vector>
int* a;
void merge(int l,int m,int r){
    int i=l;
    int j=m+1;
    int n=r-l+1;
    std::vector<int> tmp;
    int k=0;
    for(;;){
        if(i<=m&&j<=r){
            if(a[i]<=a[j]){
                //printf("test2:%d %d\n",i,a[i]);
                tmp.push_back(a[i++]);
            }else{
                //printf("test2:%d %d\n",j,a[j]);
                tmp.push_back(a[j++]);
                ans=(ans+m-i+1)%MOD;
            }
        }else if(i<=m&&j==r+1){
            //printf("test2a:%d %d\n",i,a[i]);
            tmp.push_back(a[i++]);
        }else if(i==m+1&&j<=r){
            //printf("test2a:%d %d\n",j,a[j]);
            tmp.push_back(a[j++]);
        }else if(i==m+1&&j==r+1){
            break;
        }
    }
    for(int p = 0;p<n;p++){
        a[l+p]=tmp[p];
        //printf("test:%d %d\n",l+p,tmp[p]);
    }
}
void merge_sort(int l,int r){
    if(l<r){
        int m=(l+r)>>1;
        merge_sort(l,m);
        merge_sort(m+1,r);
        merge(l,m,r);
        for(int i = l;i<=r;i++){
            //printf("test:%d~%d:%d %d\n",l,r,i,a[i]);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%lld",&arr[i].val);
        arr[i].id=i;
    }
    for(int i = 1;i<=n;i++){
        scanf("%lld",&brr[i].val);
        brr[i].id=i;
    }
    std::sort(arr+1,arr+n+1,cmp);
    std::sort(brr+1,brr+n+1,cmp);
    for(int i = 1;i<=n;i++){
        map[brr[i].id]=arr[i].id;
    }
    a=map;
    ans=0;
    merge_sort(1,n);
    printf("%d\n",ans);
    return 0;
}