#include<cstdio>
#include<cstdlib>
#include<cmath>
double a,b,c,d;
double f(double x){
    return a*pow(x,3)+b*pow(x,2)+c*x+d;
}
double p;
double find(double l,double r){
    if(r-l<p)return l; 
    if(f(l)==0)return l;
    if(f(l)*f(r)<0){
        double m = (l+r)/2;
        if(f(l)*f(m)<=0){
            return find(l,m);
        }else{
            return find(m,r);
        }
    }else{
        return -19260817;
    }
}
int main(){
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    p = 0.001;
    for(double i=-100;i<100;i+=1){
        double s = find(i,i+1);
        if(s!=-19260817){
            printf("%.2lf ",s);
        }
    }
    printf("\n");
    return 0;
}