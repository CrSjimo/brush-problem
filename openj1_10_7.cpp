#include<stdio.h>
#include<algorithm>
#include<functional>
double odd[20],even[20];
int ocnt = 0,ecnt = 0;
int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0;i<t;i++){
        double n;
        char op[10];
        scanf("%s %lf",op,&n);
        if(op[0] == 'm'){
            odd[ocnt++] = n;
        }else{
            even[ecnt++] = n;
        }
    }
    std::sort(odd,odd+ocnt);
    std::sort(even,even+ecnt,std::greater<double>());
    for(int i = 0;i<ocnt;i++){
        printf("%.2lf ",odd[i]);
    }
    for(int i = 0;i<ecnt;i++){
        printf("%.2lf ",even[i]);
    }
    return 0;
}