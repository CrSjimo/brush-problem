#include<cstdio>
#include<cstdlib>
#include<cmath>
double d,c,d0,p0;
int n;
struct Node{
    double dis;
    double go;
    double price;
}* a;
int main(){
    scanf("%lf%lf%lf%lf%d",&d,&c,&d0,&p0,&n);
    a = (Node*)malloc((n+5)*sizeof(Node));
    a[0].dis=0;
    a[0].price=p0;
    double maxdis = d0*c;
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&a[i].dis,&a[i].price);
        if(a[i].dis-a[i-1].dis>maxdis){
            printf("No solution\n");
            return 0;
        }
    }
    a[n+1].dis=d;
    double ans = 0.0;
    for(int i=0,k=1;i<=n;i=k){
        double nextD = 0.0;
        for(;nextD<=maxdis && k<=n && a[k].price>=a[i].price;k++){
            nextD+=(a[k+1].dis-a[k].dis);
        }
        if(nextD<=maxdis){
            double delta = a[i].go-(a[k].dis-a[i].dis);
            if(delta>=0){
                a[k].go = delta;
            }else{
                ans+=((-delta)/d0)*a[i].price;
                a[k].go=0;
            }
        }else{
            ans+=((maxdis-a[i].go)/d0)*a[i].price;
            a[i+1].go = (maxdis-(a[i+1].dis-a[i].dis));
            k=i+1;
        }
    }
    printf("%.2lf\n",ans);
    return 0;
}