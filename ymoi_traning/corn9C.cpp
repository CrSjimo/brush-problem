#include<cstdio>
double& max(double& a,double& b){
    return a>b?a:b;
}
int main(){
    int cas;scanf("%d",&cas);
    while(cas--){
        int n;scanf("%d",&n);
        double ans=0.0;
        double maxn=0.0;
        for(int i=1;i<=n;i++){
            double k;scanf("%lf",&k);
            ans+=k/2.0;
            maxn=max(k,maxn);
        }
        if(maxn<ans)printf("%.1lf\n",ans);
        else printf("%.1lf\n",ans*2.0-maxn);
    }
    return 0;
}