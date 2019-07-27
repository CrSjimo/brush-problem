#include<stdio.h>
#include<algorithm>
#include<map>
typedef std::map<double,int> Map;
double a[110];
Map m;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 0;i<n;i++){
        int id;
        scanf("%d%lf",&id,a+i);
        m[a[i]] = id;
    }
    std::sort(a,a+n);
    double s = a[n-k];
    int id = m[s];
    printf("%d %g\n",id,s);
    return 0;
}