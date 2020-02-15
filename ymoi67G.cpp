#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
vector<int> a;
int ans = 0;
void merge(int l,int m,int r){
    int i=l;
    int j=m+1;
    int n=r-l+1;
    vector<int> tmp;
    int k=0;
    for(;;){
        if(i<=m&&j<=r){
            if(a[i]<=a[j]){
                tmp.push_back(a[i++]);
            }else{
                tmp.push_back(a[j++]);
                ans=(ans+m-i+1);
            }
        }else if(i<=m&&j==r+1){
            tmp.push_back(a[i++]);
        }else if(i==m+1&&j<=r){
            tmp.push_back(a[j++]);
        }else if(i==m+1&&j==r+1){
            break;
        }
    }
    for(int p = 0;p<n;p++){
        a[l+p]=tmp[p];
    }
}
void merge_sort(int l,int r){
    if(l<r){
        int m=(l+r)>>1;
        merge_sort(l,m);
        merge_sort(m+1,r);
        merge(l,m,r);
    }
}
int main(){
    int n;scanf("%d",&n);
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    merge_sort(1,n);
    printf("%d\n",ans);
    return 0;
}