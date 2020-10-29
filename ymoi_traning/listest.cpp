#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using std::vector;
using std::lower_bound;

int lis(int* s,int* t){
    vector<int>b;
    b.reserve(t-s);
    b.push_back(*s);
    int ans=0;
    for(int*p=s+1;p<t;p++){
        if(*p>b[ans]){
            ans++;
            b.push_back(*p);
        }else{
            *lower_bound(b.begin(),b.end(),*p)=*p;
        }
    }
    for(int x:b){
        printf("%d ",x);
    }
    printf("\n");
    return ans+1;
}
int*a;
int main(){
    int n;scanf("%d",&n);
    a=(int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    lis(a+1,a+n+1); 
    return 0;
}