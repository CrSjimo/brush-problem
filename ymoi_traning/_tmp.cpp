#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>

int a[100];

double calc(double x){
    double ans = 0;
    for(int i=0;i<99;i++){
        ans+=fabs(1.0*a[i]-x);
    }
    return ans;
}

int main(){
    double avg;
    srand((unsigned)time(NULL));
    for(int i=0;i<99;i++){
        a[i]=rand()%100;
        avg+=1.0*a[i]/100;
    }
    printf("%d\n",a[5]);
    double avgd = calc(avg);
    printf("%lf\n",avgd);
    for(int i=0;i<99;i++){
        double c = calc(a[i]);
        if(c<avgd){
            for(int j=0;j<99;i++){
                if(fabs(a[j]-avg)<fabs(a[i]-avg)){
                    printf("%lf %lf %lf\n",c,calc(a[j]),fabs(a[j]-avg),fabs(a[i]-avg));
                    return 1;
                }
            }
        }
    }
    return 0;
}